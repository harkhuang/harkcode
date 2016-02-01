#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
/*0标准入    1是标准出   2是标准错误  这三个是默认的*/
/*pdup = dup2(pf_1, pf_2);//将2的指针指向1*/
int main()
{
	int pf;//整型变量 
	char buf[]="hello world";//字符串
	int n;//整形变量
	//0:标注输入 1： 2：
	n = read(0, buf, sizeof(buf));//从标准中度buf大小文件到   buf
	if(n == -1)//
	{
		perror("read");
		return -1;
	}
	write(1, buf, n);//将buf写入到标准输出1里面
	//printf("read buf=%s\n", buf);

#if 0
	//3
	pf  = open("tmp", O_TRUNC|O_RDWR);
	if(pf == -1)
	{
		printf("errno=%d EEXIST=%d\n", errno, EEXIST);
		perror("open");
		return -1;
	}
	printf("pf=%d\n", pf);

	//write(pf, buf, sizeof(buf));
	//lseek(pf, 0,SEEK_SET);
	memset(buf, 0, sizeof(buf));
	read(pf, buf, sizeof(buf));
	printf("buf=%s\n", buf);
	close(pf);
	#endif
}
