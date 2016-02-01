#include "../apue.h"
/*???? fdopen    open  fopen  */
int main()
{
	int pfid;//定义文件描述符
	char buf[6];//定义字符数组
	FILE *pf;//定义文件结构体指针
	int i;//整形变量

	pfid = open("tmp.txt", O_RDWR);//以读写方式打开文件   返回空闲的文件描述符  3
	if(pfid < 0)
	{
		perror("open");
		return -1;
	}
	//fileno() FILE文件结构体－》int　文件描述符
	//int 文件描述符－》ＦＩＬＥ类型的文件结构体
	pf = fdopen(pfid, "r+");
	for(i=0; i<5; i++)
	{
		
		fprintf(pf, "hello_%d\n", i);
	}

#if 0
	 //lseek(pfid, 5, SEEK_SET);
	 //read(pfid, buf, 5);
	 pread(pfid, buf, sizeof(buf), 5);
	 printf(buf);
	 memset(buf, 0, sizeof(buf));
	 pread(pfid, buf, sizeof(buf), 5);
	 printf(buf);
	//lseek read/write
	//pwrite()
#endif
	fclose(pf);
}













