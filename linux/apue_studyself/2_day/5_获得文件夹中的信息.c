#include "../apue.h"
#include <glob.h>
/*获得当前路径文件夹 中的信息*/
int main()
{
	int ret, i;//定义两个整型的变量
	glob_t glob_res;//定义一个glob_t类型的结构体指针
/*
typedef struct           //golb结构体  只是结构体不是链表
{
	int gl_pathc;  //含有的个数
	char **gl_pathv;//指针数组      数组中存放的是文件名字的指针  每一个指针能找到对应的地址 *p中的内容是个文件指针  *p[]类型的指针
	int gl_offs;//无关紧要
}
* ? [] {}
GLOB_NOSORT GLOB_APPEND GLOB_NOCHECK(字符串处理)
*/
	ret = glob("*", GLOB_NOSORT,NULL, &glob_res);//获得当前路径下的所有的文件  存放再glob_res结构体中
	if(ret == -1)//没获得成功返回-1
	{
		perror("glob");
		return -1;
	}

	ret = glob(".*", GLOB_NOSORT|GLOB_APPEND, NULL, &glob_res);//追加获得隐藏的文件
	if(ret == -1)//没成功返回-1
	{
		perror("glob");
		return -1;
	}
	

	for(i=0; i<glob_res.gl_pathc; i++)//循环的输出文件名子
	{
		printf("[%d]:%s\n", i,glob_res.gl_pathv[i]);//为什打印出来的能是个文件名子呢????数组a[]已经引用了
	}
}
