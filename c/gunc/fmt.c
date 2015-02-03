#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#define _vsnprintf vsnprintf 

#if 0
int mon_log(char* format, ...)
{
	char str_tmp[50];
	int i=0;
	va_list vArgList; //定义一个va_list型的变量,这个变量是指向参数的指针.
	//遍历参数列表
	va_start (vArgList, format); //用va_start宏初始化变量,这个宏的第二个参数是第一个可变参数的前一个参 //数,是一个固定的参数.
	i=vsnprintf(str_tmp, 50, format, vArgList); //注意,不要漏掉前面的_(vc中  _vsnprintf)(gunc中 vsnprintf)
	va_end(vArgList); //用va_end宏结束可变参数的获取
	
	return i; //返回参数的字符个数中间有逗号间隔
}
//调用上面的函数
void main()
{
	int i=mon_log("%s,%d,%d,%d","asd",2,3,4);
	printf("%d\n",i);
}

//输出 9。


//分析:
//asd,2,3,4
//123456789 （共9个字符，间隔符逗号计算在内）
//返回值用法：

#else
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

//利用输入参数构造messgae
char *make_message(const char *fmt, ...) 
{
	/* 初始时假设我们只需要不超过100字节大小的空间 */
	int n, size = 100;//设置变量
	char *p;//指针变量p
	va_list ap;//列表变量  ap
	if ( (p = (char *) malloc(size*sizeof(char))) == NULL)//为指针申请内存空间
	{
		return NULL;//如果内存没有申请成功
	}
	while (1)
	{
				/* 尝试在申请的空间中进行打印操作 */
				va_start(ap, fmt);//开始遍历列表
				n = vsnprintf (p, size, fmt, ap);//
				va_end(ap);
				/* 如果vsnprintf调用成功，返回该字符串 */
				if (n > -1 && n < size)
				{
					return p;
				}
				/* vsnprintf调用失败(n<0)，或者p的空间不足够容纳size大小的字符串(n>=size)，尝试申请更大的空间*/
				size *= 2; /* 两倍原来大小的空间 */
				if ((p = (char *)realloc(p, size*sizeof(char))) == NULL)
				{
					return NULL;
				}
	}
}
int main() 
{
	/* 调用上面的函数 */
	char* str = make_message("%d,%d,%d,%d",5,6,7,8);
	printf("%s\n",str);
	free(str);
	/* we allocate the memory in the make_message function, so we should release it by caller(main function). */
	return 0;
}
#endif
