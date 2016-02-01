#include "../apue.h"
//goto 

/*实现以goto方式容错。。。。*/
int main()
{
	int pfid;

	pfid = open(argv[1], O_RDWR);//打开文件  只读方式打开
	if(pfid < 0)
	{
		perror("open");
		goto ERR;
	}
	ret = read(pfid, buf, sizeof(buf));
	if(ret < 0)
	{
		goto ERR1;
	}
ERR1:
	close(pfid);
ERR:
	exit(1);

}






