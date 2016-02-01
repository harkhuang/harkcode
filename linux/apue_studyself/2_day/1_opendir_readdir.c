#include "../apue.h"
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
/*文件夹结构体的操作*/
// /home/u1/zhuxiaoke/apue/2_day/abcd
// /root/abcd 

int main(int argc, char **argv)//字符个数   第几个字符 使用的是指针数组  记录的地址
{
	int ret;//定义一个整型的返回值
	int pfid;//定义一个标识符
	DIR *dir;//定义一个文件夹指针
	struct dirent *pd;  //文件夹指针结构体
/*
struct dirent   //
{
	ino_t d_ino; //定义的是一个文件夹信息
	char d_name[NAME_MAX+1];//该数组记录的是文件名
};
*/
	dir = opendir(argv[1]);//       打开文件夹  返回文件夹指针

	pd = readdir(dir);// 读一个文件夹指针   转化为结构体指针   读一个节点   移动结构题中数组的光标
	while(pd != NULL)//当文件夹不是空的时候
	{
		printf("%s\n", pd->d_name);//打印出文件的名字  逐个打印出名字知道标识符不是空的时候
		pd = readdir(dir);//读取下一个节点中的内容
	}

	closedir(dir);//关闭文件夹
	



#if 0
	chdir("/root");//更改当前进程目录路径
	//工作目录
	ret = mkdir("abcd", S_IRWXU);//创建目录  权限是wrx  所属用户u
	printf("ret=%d\n", ret);//代嗯结果  创建是否成功
	chdir("/root/abcd");//再次更改
	pfid = open("file", O_CREAT);//以只读的方式打开文件

	close(pfid);//关闭文件指针
	chdir("/root");//更改目录

	ret = rmdir("abcd");//删除一个目录
	perror("rmdir");//错误提示
	printf("ret=%d\n", ret);//打印出错的函数
	
#endif
}









