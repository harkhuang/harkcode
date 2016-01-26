#ifndef __KDENCODE_H__
#define __KDENCODE_H__

/*************************************
Version : 1.0.0.3
*************************************/

#define KDCOMPLEX_ENCODE 6
/*************************************
int nEncode_Level          加密级别 = KDCOMPLEX_ENCODE
unsigned char *pSrcData    需要加密的源文
int nSrcDataLen            需要加密源文的长度
unsigned char *pDestData   密文缓冲区
int nDestDataBufLen        密文缓冲区的大小
void *pKey                 密钥
int nKeyLen                密钥的长度

返回值                     生成密文的长度
注:
加密级别 = KDCOMPLEX_ENCODE 时
密文缓冲区的大小           nDestDataBufLen = 2*nSrcDataLen(加密源文的长度)并且nDestDataBufLen>= 32
生成密文为0x00结尾ASCII字符串
*************************************/
int KDEncode(int nEncode_Level, 
			  unsigned char *pSrcData, int nSrcDataLen, 
			  unsigned char *pDestData, int nDestDataBufLen, 
			  void *pKey, int nKeyLen);


/*************************************
*************************************/
int KDReEncode( unsigned char *pSrcData, int nSrcDataLen, 
			  unsigned char *pDestData, int nDestDataBufLen, 
			  int nOldEncode_Level, void *pOldKey, int nOldKeyLen, 
			  int nNewEncode_Level, void *pNewKey, int nNewKeyLen );

#endif
