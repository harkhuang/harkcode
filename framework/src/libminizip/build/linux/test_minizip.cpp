/*
// For Compiler

*/
#include<stdlib.h>
#include<stdio.h>
#include "macro_ldef.h"
#include "minizip.h"

int main(int argc, char ** argv)
{
	const char *lpszzipfilename = "test.zip";
	const char *lpszfilename1 = "1.dat";
	const char *lpszfilename2 = "test1.txt";
	int nret = -1;
	
	// create zip 
	nret = minizip_zip(lpszzipfilename,lpszfilename1, "",0,EM_MINIZIP_COMPRESSION_BEST);
//	nret = minizip_zip(lpszzipfilename,lpszfilename1, "",0,EM_MINIZIP_COMPRESSION_NO);
	//	nret = minizip_zip(lpszzipfilename,lpszfilename1, "",0,EM_MINIZIP_SPEED_BEST);
	//nret = minizip_zip(lpszzipfilename,lpszfilename1, "",0);
	printf("minizip_zip [%s] ret=%d\n",lpszfilename1,nret);
	//nret = minizip_zip(lpszzipfilename,lpszfilename2, "",1,EM_MINIZIP_COMPRESSION_BEST);
//	nret = minizip_zip(lpszzipfilename,lpszfilename2, "",1,EM_MINIZIP_COMPRESSION_NO);
//		nret = minizip_zip(lpszzipfilename,lpszfilename2, "",1,EM_MINIZIP_SPEED_BEST);
//	nret = minizip_zip(lpszzipfilename,lpszfilename2, "",1);
//	printf("minizip_zip [%s] ret=%d\n",lpszfilename2,nret);

	nret = minizip_unzip(lpszzipfilename,"./","");
	printf("minizip_unzip ret=%d\n",nret);
	
  return 0;
}
