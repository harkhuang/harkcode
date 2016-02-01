#include "../apue.h"

int main(int argc, char **argv)
{
	int pfid;

	pfid  = open(argv[1], O_CREAT);//以创建的方式打开文件

	if(pfid>0)
	{
		printf("open file success\n");
		printf("the file id is %d\n",pfid);
	}
	else
	{
		error("open()");
	}

	close(pfid);
}
