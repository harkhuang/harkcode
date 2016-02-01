#include "../apue.h"
// > 重定向
int main(int argc, char **argv)
{
	int pf_1, pf_2, pdup;//以整形来定义文件指针  
	int pf;//文件指针
	char buf[20];//字符数组
	int n;//整形变量

	if(argc != 3)//参数若果不是三个
	{
		printf("%s <file name>\n", argv[0]);
		return -1;
	}

	//close(0);

//./exe file.txt tmp.txt
	pf_1 = open(argv[1], O_RDWR);//pf_1指向第一个文件   读写的方式打开  argv[1]文件
	if(pf == -1)//没成功的打开文件
	{
		perror("open");
		return -1;
	}
	//read(0, buf, sizeof(buf));
	pf_2 = open(argv[2], O_RDWR);//以读写方式打开文件argv【2】返回值是文件描述符
	if(pf == -1)
	{
		perror("open");
		return -1;
	}
	pdup = dup2(pf_1, pf_2);//将2的指针指向1   实现了指针的重定向
	read(pdup, buf, sizeof(buf));
	printf("buf=%s pf_1=%d pf_2=%d pdup=%d\n", buf, pf_1,pf_2,pdup);
	
	close(pf_1);
	close(pf_2);
	//1
#if 0
	close(1);

	pf = open(argv[1], O_RDWR);
	if(pf == -1)
	{
		perror("open");
		return -1;
	}
	//write(pf, "hello world\n", 20);
	write(1,"hello world\n", 20);
	write(2,"open err", 20);
	
	n = read(0, buf, sizeof(buf));
	buf[n]='\0';
	write(1, buf, n);
	close(pf);
#endif
}












