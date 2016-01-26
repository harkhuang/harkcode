#ifndef __KDENCODE_H__
#define __KDENCODE_H__

/*************************************
Version : 1.0.0.3
*************************************/

#define KDCOMPLEX_ENCODE 6
/*************************************
int nEncode_Level          ���ܼ��� = KDCOMPLEX_ENCODE
unsigned char *pSrcData    ��Ҫ���ܵ�Դ��
int nSrcDataLen            ��Ҫ����Դ�ĵĳ���
unsigned char *pDestData   ���Ļ�����
int nDestDataBufLen        ���Ļ������Ĵ�С
void *pKey                 ��Կ
int nKeyLen                ��Կ�ĳ���

����ֵ                     �������ĵĳ���
ע:
���ܼ��� = KDCOMPLEX_ENCODE ʱ
���Ļ������Ĵ�С           nDestDataBufLen = 2*nSrcDataLen(����Դ�ĵĳ���)����nDestDataBufLen>= 32
��������Ϊ0x00��βASCII�ַ���
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
