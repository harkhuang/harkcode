
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <utime.h>
#include <sys/stat.h>

#include "minizip.h"
#include "zlib.h"
#include "unzip.h"
#include "zip.h"


#define MKDIR(d) mkdir(d, 0775)

const int WRITE_BUFFER_SIZE = 16384;
const int MAX_FILENAME_LEN = 256;

// Errors id
const int ERROR_CREATE_ZIP = -100;
const int ERROR_GET_CRC32 = -101;
const int ERROR_WHILE_READ = -102;
const int ERROR_FILE_NOT_FOUND = -103;
const int ERROR_ZIP_FILE_NOT_FOUND = -104;
const int ERROR_ZIP_FILE = -105;


void getFileTime(const char *filename, tm_zip *tmzip, uLong *dostime)
{
  struct stat s =
    {
      0
    };
  time_t tm_t = 0;

  if (strcmp(filename, "-") != 0)
  {
    char name[MAX_FILENAME_LEN + 1];

    int len = strlen(filename);
    if (len > MAX_FILENAME_LEN)
    {
      len = MAX_FILENAME_LEN;
    }

    strncpy(name, filename, MAX_FILENAME_LEN - 1);
    name[MAX_FILENAME_LEN] = 0;

    if (name[len - 1] == '/')
    {
      name[len - 1] = 0;
    }

    /* not all systems allow stat'ing a file with / appended */
    if (stat(name, &s) == 0)
    {
      tm_t = s.st_mtime;
    }
  }

  struct tm* filedate = localtime(&tm_t);
  tmzip->tm_sec = filedate->tm_sec;
  tmzip->tm_min = filedate->tm_min;
  tmzip->tm_hour = filedate->tm_hour;
  tmzip->tm_mday = filedate->tm_mday;
  tmzip->tm_mon = filedate->tm_mon;
  tmzip->tm_year = filedate->tm_year;
}

void setFileTime(const char *filename, uLong dosdate, tm_unz tmu_date)
{
  struct tm newdate;
  newdate.tm_sec = tmu_date.tm_sec;
  newdate.tm_min = tmu_date.tm_min;
  newdate.tm_hour = tmu_date.tm_hour;
  newdate.tm_mday = tmu_date.tm_mday;
  newdate.tm_mon = tmu_date.tm_mon;

  if (tmu_date.tm_year > 1900)
  {
    newdate.tm_year = tmu_date.tm_year - 1900;
  }
  else
  {
    newdate.tm_year = tmu_date.tm_year;
  }
  newdate.tm_isdst = -1;

  struct utimbuf ut;
  ut.actime = ut.modtime = mktime(&newdate);
  utime(filename, &ut);
}

int isLargeFile(const char* filename)
{
  FILE* pFile = fopen64(filename, "rb");
  if (pFile == NULL) return 0;

  fseeko64(pFile, 0, SEEK_END);
  ZPOS64_T pos = ftello64(pFile);
  fclose(pFile);

  return (pos >= 0xffffffff);
}

// Calculate the CRC32 of a file
int getCRC32(const char* filenameinzip, Bytef *buf, unsigned long size_buf, unsigned long* result_crc)
{
  unsigned long calculate_crc = 0;

  int status = ZIP_OK;

  FILE *fin = fopen64(filenameinzip, "rb");
  if (fin == NULL) status = ERROR_GET_CRC32;
  else
  {
    unsigned long size_read = 0;
    do
    {
      size_read = (int) fread(buf, 1, size_buf, fin);

      if ((size_read < size_buf) && (feof(fin) == 0))
      {
        status = ERROR_WHILE_READ;
      }

      if (size_read > 0)
      {
        calculate_crc = crc32(calculate_crc, buf, size_read);
      }
    }
    while ((status == ZIP_OK) && (size_read > 0));
  }

  if (fin)
  {
    fclose(fin);
  }

  *result_crc = calculate_crc;
  return status;
}

int extractCurrentFile(unzFile uf, const char *password)
{
  unz_file_info64 file_info = { 0 };
  char filename_inzip[256] = { 0 };

  int status = unzGetCurrentFileInfo64(uf, &file_info, filename_inzip, sizeof(filename_inzip), NULL, 0, NULL, 0);
  if (status != UNZ_OK)
  {
    return status;
  }

  uInt size_buf = WRITE_BUFFER_SIZE;
  void* buf = (void*) malloc(size_buf);
  if (buf == NULL) return UNZ_INTERNALERROR;
	
	if (password &&(password[0]==0))
	{
  	password = NULL;
  }
  status = unzOpenCurrentFilePassword(uf, password);
  const char* write_filename = filename_inzip;

  // Create the file on disk so we can unzip to it
  FILE* fout = NULL;
  if (status == UNZ_OK)
  {
    fout = fopen64(write_filename, "wb");
  }

  // Read from the zip, unzip to buffer, and write to disk
  if (fout != NULL)
  {
    do
    {
      status = unzReadCurrentFile(uf, buf, size_buf);
      if (status <= 0) break;
      if (fwrite(buf, status, 1, fout) != 1)
      {
        status = UNZ_ERRNO;
        break;
      }
    }
    while (status > 0);

    if (fout) fclose(fout);

    // Set the time of the file that has been unzipped
    if (status == 0)
    {
      setFileTime(write_filename, file_info.dosDate, file_info.tmu_date);
    }
  }

  unzCloseCurrentFile(uf);

  free(buf);
  return status;
}

int minizip_zip(const char * lpszzipfilename, 
                      const char * lpszfilename, 
                      const char * lpszpassword,
                      int nmode, int nLevel)
{
  int nret = -1;
  int nstatus = 0;
//  int opt_compress_level = Z_DEFAULT_COMPRESSION;
	if (nLevel != Z_DEFAULT_COMPRESSION && nLevel != Z_BEST_COMPRESSION && nLevel != Z_BEST_SPEED && nLevel !=  Z_NO_COMPRESSION)
	{
		return -10086;	
	} 
	int nzipmode = APPEND_STATUS_CREATE;
	if (nmode ==0)
	{
		nzipmode = APPEND_STATUS_CREATE;
	}
	else
	{
		nzipmode = APPEND_STATUS_ADDINZIP;
	}
  // Create archive zipfilename
  zipFile zf = zipOpen64(lpszzipfilename, nzipmode);
  if (zf == NULL)
  {
    nstatus = ERROR_CREATE_ZIP;
  }

  int size_buf = WRITE_BUFFER_SIZE;
  Bytef* buf = (Bytef*) malloc(size_buf);

  // Get information about the file on disk so we can store it in zip
  zip_fileinfo zi;
  memset(&zi,0x00,sizeof(zip_fileinfo));
  getFileTime(lpszfilename, &zi.tmz_date, &zi.dosDate);

  unsigned long crcFile = 0;
  if (nstatus == ZIP_OK)
  {
    nstatus = getCRC32(lpszfilename, buf, size_buf, &crcFile);
  }

  int zip64 = isLargeFile(lpszfilename);

  // Construct the filename that our file will be stored in the zip as.
  const char *savefilenameinzip = lpszfilename;
  {
    const char *tmpptr = NULL;
    const char *lastslash = 0;

    for (tmpptr = savefilenameinzip; *tmpptr; tmpptr++)
    {
      if (*tmpptr == '\\' || *tmpptr == '/')
      {
        lastslash = tmpptr;
      }
    }
    if (lastslash != NULL)
    {
      savefilenameinzip = lastslash + 1;
    }
  }
	if ((lpszpassword) && (lpszpassword[0] ==0))
	{
		lpszpassword = NULL;
	}
  // Create zip file
  nstatus = zipOpenNewFileInZip3_64(zf, savefilenameinzip, &zi, NULL, 0, NULL, 0, NULL /* comment*/,
                                   Z_DEFLATED, nLevel, 0,
                                   -MAX_WBITS, DEF_MEM_LEVEL, Z_DEFAULT_STRATEGY, lpszpassword, crcFile, zip64);

  // Add file to zip
  FILE *fin = NULL;
  if (nstatus == ZIP_OK)
  {
    fin = fopen64(lpszfilename, "rb");
    if (fin == NULL)
    {
      nstatus = ERROR_FILE_NOT_FOUND;
    }
  }

  int size_read = 0;
  if (nstatus == ZIP_OK)
  {
    // Read contents of file and write it to zip
    do
    {
      size_read = (int) fread(buf, 1, size_buf, fin);
      if ((size_read < size_buf) && (feof(fin) == 0))
      {
        nstatus = ERROR_WHILE_READ;
      }

      if (size_read > 0)
      {
        nstatus = zipWriteInFileInZip(zf, buf, size_read);
      }
    }
    while ((nstatus == ZIP_OK) && (size_read > 0));
  }

  if (fin)
  {
    fclose(fin);
  }

  if (nstatus >= 0)
  {
    nstatus = zipCloseFileInZip(zf);
  }

  zipClose(zf, NULL);

  // Release memory
  free(buf);

  if (nstatus == UNZ_OK)
  {
    nret = 0;
  }

  return nret;
}

int minizip_unzip(const char * lpszzipfilename, 
                  const char * lpszdirname, 
                  const char * lpszpassword)
{
  int nret = -1;
  int nstatus = 0;
  int nct = 0;

  unzFile uf = NULL;

  // Open zip file
  if (lpszzipfilename != NULL)
  {
    uf = unzOpen64(lpszzipfilename);
  }
  if (uf == NULL)
  {
    return ERROR_ZIP_FILE_NOT_FOUND;
  }

  // Extract all
  nstatus = unzGoToFirstFile(uf);
  while (nstatus == UNZ_OK)
  {
	  chdir(lpszdirname);
  	nstatus = extractCurrentFile(uf, lpszpassword);
  	if (nstatus == UNZ_OK)
  	{
	  	nct ++;
	  	nstatus =unzGoToNextFile(uf);
	  }
	}
	
  if (nct > 0)
  {
    nret = 0;
  }

  return nret;
}

int minizip_getfilenameinzip(const char * lpszzipfilename, char *lpszfilenameinzip, int nmaxlen)
{
  int nret = -1;
  // Open zip file
  unzFile uf = NULL;
  if (lpszzipfilename != NULL)
  {
    uf = unzOpen64(lpszzipfilename);
  }

  if (uf == NULL)
  {
    return nret;
  }

  // Get filename in zip
  unz_file_info64 file_info = { 0 };

  int status = unzGetCurrentFileInfo64(uf, &file_info, lpszfilenameinzip, nmaxlen, NULL, 0, NULL, 0);
  if (status != UNZ_OK)
  {
    return nret;
  }
  nret = 0;
  return nret;
}
