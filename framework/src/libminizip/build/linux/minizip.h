#ifndef _LIB_MINIZIP_INCLIDE_
#define _LIB_MINIZIP_INCLIDE_


enum EM_MINIZIP_COMPRESSION 
{
	EM_MINIZIP_COMPRESSION_NO = 0,
	EM_MINIZIP_SPEED_BEST = 1,
	EM_MINIZIP_COMPRESSION_BEST = 9,
	EM_MINIZIP_COMPRESSION_DEFAULT = -1,
};
	
enum EM_MINIZIP_MODE 
{
	EM_MINIZIP_ON = 0,
	EM_MINIZIP_OFF = 1,
};



#ifdef __cplusplus
extern "C" {
#endif

// nmode:0 create new zip and add file
// nmode:1 use exists zip and add file
int minizip_zip(const char * lpszzipfilename, 
                      const char * lpszfilename, 
                      const char * lpszpassword,
                      int nmode, int nlevel = EM_MINIZIP_COMPRESSION_DEFAULT);

int minizip_unzip(const char * lpszzipfilename, 
                       const char * lpszdirname, 
                       const char * lpszpassword);                     
                      

#ifdef __cplusplus
}
#endif

#endif

