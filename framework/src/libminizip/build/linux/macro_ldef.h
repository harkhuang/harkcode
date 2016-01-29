#ifndef __MISC_L_MARCO_DEF
#define __MISC_L_MARCO_DEF

/************************************************************
 Copyright (C), 2001-2012, Kingdom Tech. Co., Ltd.
 FileName:      macro_ldef.h
 Author:        Version :          Date:
 Description:   �����궨��ģ��
 Version:       V1.0
 Function List:
   1. ���Ա��������
   2. �ַ�����ȫ��
   3. ����Ԫ�س�ʼ����
   4. �������ݴ����
 History:           // ��ʷ�޸ļ�¼
      <author>  <time>  <version >   <desc>
      lium      2012/01/01    V1.0     build this moudle
***********************************************************/


// 1.���Ա��������
#ifndef DEF_L_CLASS_METHOD
#define DEF_L_CLASS_METHOD

// ���Ա�ַ������� Get/Set ����
#define GETSETSTRINGMETHOD(name,size)  public:  \
	                                  inline char* Get##name() { return m_sz##name; } \
	                                  inline void Set##name(char *lpname) \
					                          { \
	                                     strncpy(m_sz##name,lpname,sizeof(m_sz##name) -1); \
	                                     m_sz##name[sizeof(m_sz##name) -1] = 0; \
					                          } \
					                        private: \
	                                  char m_sz##name[size +1];
// ���Ա�ַ���������ʼ��Ϊ��
#define GETSETSTRIN_INIT(name) m_sz##name[0] = 0;


// ���Ա�������� Get/Set ����
#define GETSETINTEGERMETHOD(name)  public:  \
	                                  inline int Get##name() { return m_n##name; } \
	                                  inline void Set##name(int ndata) \
					                          { \
	                                     m_n##name = ndata; \
					                          } \
					                        private: \
	                                  int m_n##name;

// ���Ա����������ʼ��Ϊ0
#define GETSETINTIN_INIT(name)    m_n##name = 0;

// ���Ա����������ʼ��Ϊvalue
#define GETSETINTIN_INIT_VALUE(name,value)    m_n##name = value;


#ifdef _WIN32
#define GETSETINTEGERMETHOD64(name)  public:  \
                                  inline _int64 Get##name() { return m_n##name; } \
                                  inline void Set##name(_int64 ndata) \
				                          { \
                                     m_n##name = ndata; \
				                          } \
				                        private: \
                                 _int64 m_n##name;
#endif

#endif

// 2.�ַ�����ȫ��

// �ַ�����ȫ����
// ע�⣺src �������ַ�����
#ifndef DEF_L_SAFESTRCPY
#define DEF_L_SAFESTRCPY
#define SAFESTRCPY(src,dst)         { \
									                    strncpy(src,dst,sizeof(src) -1); \
	                                    src[sizeof(src) -1] =0; \
									                  }

#define SAFESTRCAT(src,dst)            { \
											int n_strcat_dstoffset = strlen(src); \
                      int n_strcat_dstleft = sizeof(src) -1 -n_strcat_dstoffset; \
                      if (n_strcat_dstleft <0) n_strcat_dstleft =0; \
									   strncpy(src + n_strcat_dstoffset,dst,n_strcat_dstleft); \
	                                   src[sizeof(src) -1] =0; \
									   }
#define SAFESTRZERO(src) memset(src, 0, sizeof(src))

#define SAFEFZERO(src) src[0] = 0;

#define SAFELZERO(src) src[sizeof(src) -1] =0;

#define FIRSTZERO(src) src[0] = 0;

#define LASTZERO(src) src[sizeof(src) -1] =0;

#endif

#ifndef DEF_L_SAFESPRINTF
#define DEF_L_SAFESPRINTF
// ����Ϊ�ɱ������C99��׼��VC6.0��֧��
#define SAFESPRINTF(src, format, ...)    { \
																		         _snprintf(src, sizeof(src)/sizeof(src[0]) - 1, format, __VA_ARGS__); \
																		         src[sizeof(src)/sizeof(src[0]) - 1] = 0;              \
																		      }
#endif

#ifndef DEF_L_SAFENSPRINTF
#define DEF_L_SAFENSPRINTF
#define SAFESNPRINTF(src, n, format, ...)  { \
																		         _snprintf(src, n, format, __VA_ARGS__); \
																		        }
#endif


// 3.����Ԫ�س�ʼ����
#ifndef DATA_ZERO
#define DATA_ZERO(a) memset(a, 0, sizeof(a))
#define  DATA_FZERO(a)	  a[0] = 0;
#define  DATA_LZERO(a)   a[sizeof(a) - 1] = 0;

// ���ݽṹ���
#define DATAST_ZERO(a) memset(&a, 0, sizeof(a))
#endif

// ��ṹ���鳤��
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#endif



// 4.�������ݴ����
#ifndef DEF_L_FLOAT
#define DEF_L_FLOAT
#define FLOAT_LOWDATA    0.000001
// �ж����������������
#define FLOAT_EQUAL(a,b)                     (fabs((a) - (b)) < FLOAT_LOWDATA)
// �ж������������ݲ����
#define FLOAT_NOEQUAL(a,b)                 (!FLOAT_EQUAL(a,b))
// ��ʼ����������
#define FLOAT_INIT(a)                       a = 0.00000
// �жϸ�����С�ڵ�����
#define FLOAT_SMALLANDEQUALZERO(a)         ((a) <= FLOAT_LOWDATA)

#define FLOAT_GREATERZERO(a)               ((a) > FLOAT_LOWDATA)

// �жϸ�����������
#define FLOAT_EQUALZERO(a)                 (fabs(a) < FLOAT_LOWDATA)
// �жϸ�������������
#define FLOAT_NOEQUALZERO(a)               (!FLOAT_EQUALZERO(a))
// ���ڵ���0��С�ڵ���1
#define FLOAT_ZERO2ONE(a)                  (FLOAT_EQUALZERO(a) || (FLOAT_GREATERZERO(a) && (FLOAT_SMALLANDEQUALZERO((a) - 1.0)) ))
#endif


#endif
