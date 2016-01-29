#ifndef __MISC_L_MARCO_DEF
#define __MISC_L_MARCO_DEF

/************************************************************
 Copyright (C), 2001-2012, Kingdom Tech. Co., Ltd.
 FileName:      macro_ldef.h
 Author:        Version :          Date:
 Description:   基础宏定义模块
 Version:       V1.0
 Function List:
   1. 类成员变量定义
   2. 字符串安全宏
   3. 数据元素初始化宏
   4. 浮点数据处理宏
 History:           // 历史修改记录
      <author>  <time>  <version >   <desc>
      lium      2012/01/01    V1.0     build this moudle
***********************************************************/


// 1.类成员变量定义
#ifndef DEF_L_CLASS_METHOD
#define DEF_L_CLASS_METHOD

// 类成员字符串变量 Get/Set 方法
#define GETSETSTRINGMETHOD(name,size)  public:  \
	                                  inline char* Get##name() { return m_sz##name; } \
	                                  inline void Set##name(char *lpname) \
					                          { \
	                                     strncpy(m_sz##name,lpname,sizeof(m_sz##name) -1); \
	                                     m_sz##name[sizeof(m_sz##name) -1] = 0; \
					                          } \
					                        private: \
	                                  char m_sz##name[size +1];
// 类成员字符串变量初始化为空
#define GETSETSTRIN_INIT(name) m_sz##name[0] = 0;


// 类成员整数变量 Get/Set 方法
#define GETSETINTEGERMETHOD(name)  public:  \
	                                  inline int Get##name() { return m_n##name; } \
	                                  inline void Set##name(int ndata) \
					                          { \
	                                     m_n##name = ndata; \
					                          } \
					                        private: \
	                                  int m_n##name;

// 类成员整数变量初始化为0
#define GETSETINTIN_INIT(name)    m_n##name = 0;

// 类成员整数变量初始化为value
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

// 2.字符串安全宏

// 字符串安全拷贝
// 注意：src 必须是字符数组
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
// 调整为可变参数，C99标准，VC6.0不支持
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


// 3.数据元素初始化宏
#ifndef DATA_ZERO
#define DATA_ZERO(a) memset(a, 0, sizeof(a))
#define  DATA_FZERO(a)	  a[0] = 0;
#define  DATA_LZERO(a)   a[sizeof(a) - 1] = 0;

// 数据结构清空
#define DATAST_ZERO(a) memset(&a, 0, sizeof(a))
#endif

// 求结构数组长度
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#endif



// 4.浮点数据处理宏
#ifndef DEF_L_FLOAT
#define DEF_L_FLOAT
#define FLOAT_LOWDATA    0.000001
// 判断两个浮点数据相等
#define FLOAT_EQUAL(a,b)                     (fabs((a) - (b)) < FLOAT_LOWDATA)
// 判断两个浮点数据不相等
#define FLOAT_NOEQUAL(a,b)                 (!FLOAT_EQUAL(a,b))
// 初始化浮点数据
#define FLOAT_INIT(a)                       a = 0.00000
// 判断浮点数小于等于零
#define FLOAT_SMALLANDEQUALZERO(a)         ((a) <= FLOAT_LOWDATA)

#define FLOAT_GREATERZERO(a)               ((a) > FLOAT_LOWDATA)

// 判断浮点数等于零
#define FLOAT_EQUALZERO(a)                 (fabs(a) < FLOAT_LOWDATA)
// 判断浮点数不等于零
#define FLOAT_NOEQUALZERO(a)               (!FLOAT_EQUALZERO(a))
// 大于等于0且小于等于1
#define FLOAT_ZERO2ONE(a)                  (FLOAT_EQUALZERO(a) || (FLOAT_GREATERZERO(a) && (FLOAT_SMALLANDEQUALZERO((a) - 1.0)) ))
#endif


#endif
