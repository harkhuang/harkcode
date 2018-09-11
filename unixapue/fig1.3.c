#include "apue.h"
#include <dirent.h>



/**
遍历文件夹
1.打开文件夹
2.获取文件夹指针  //此处记录文件夹所有信息

思考：
文件夹其实也是文件描述符一种
打开文件夹指针就是获取文件夹指针所有相关的信息

 * 
 */
int
main(int argc, char *argv[])
{
	DIR				*dp; //文件夹描述符
	struct dirent	*dirp;// 文件结构体指针

	if (argc != 2)
		err_quit("usage: ls directory_name");

	if ((dp = opendir(argv[1])) == NULL)   //打开文件夹描述符  获得文件描述符指针
		err_sys("can't open %s", argv[1]);
	while ((dirp = readdir(dp)) != NULL)   // 读取文件描述符指针
	{
		printf("%s \n", dirp->d_name);  //文件名称
		printf("%lld \n ", dirp->d_ino);  // 文件i节点
		printf("%c \n ", dirp->d_type);  //文件类型
		printf("%d \n ", dirp->d_seekoff);  //文件offset指针偏移量

	}


	closedir(dp);
	exit(0);
}
