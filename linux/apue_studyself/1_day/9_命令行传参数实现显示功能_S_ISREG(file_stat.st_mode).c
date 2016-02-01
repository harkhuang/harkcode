#include "../apue.h"
/*如何实现的各种显示  很牛逼各种位运算*/
int main(int argc, char **argv)
{
	int i;
	struct stat file_stat;//定义结构体
	char file_mode[10];//定义字符数组
	char *str_res[]={"---","--x","-w-","-wx","r--","r-x","rw-","rwx"};//以读写的方式打开
	int tmp;

	// printf("%x %x %x %x\n", S_IRWXO,S_IROTH,S_IWOTH,S_IXOTH);
#if 1
	memset(file_mode, 0,10*sizeof(char));

	for(i = 1; i<argc; i++)
	{
		stat(argv[i], &file_stat);//将文件 的状态指针  赋值给file_stat    后面是一系列对状态的操作
		if(S_ISREG(file_stat.st_mode))
		{
			file_mode[0] = '-';
		}
		else
			if(S_ISBLK(file_stat.st_mode))
			{
				file_mode[0] = 'b';
			}
			//S_ISCHR S_ISLNK S_ISDIR S_ISSOCK S_ISFIFO
		printf("ino=%d size=%d	", file_stat.st_ino, file_stat.st_size);
		
		tmp = file_stat.st_mode>>6&S_IRWXO;
		strcat(file_mode, str_res[tmp]);

		tmp = file_stat.st_mode>>3&S_IRWXO;
		strcat(file_mode, str_res[tmp]);

		tmp = file_stat.st_mode&S_IRWXO;
		strcat(file_mode, str_res[tmp]);

		printf("%s", file_mode);
	}
#endif
}












