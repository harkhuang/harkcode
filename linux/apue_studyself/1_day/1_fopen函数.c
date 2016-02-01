#include <stdio.h>
#include <sys/types.h>
/*fopen函数  */
int main(int argc, char **argv)
{
	FILE *pfile = NULL;//初始化文件指针

	if(argc != 2)//如果不是两个参数
	{
		printf("%s <filename>\n", argv[0]);//显示错误
		return -1;
	}

	pfile = fopen(argv[1], "r+");//以读写的方式打开一个文件  返回一个文件指针  当前路径下的  一个文件名
	if(pfile == NULL)//如果一文件是空   输出一个错误的警告
	{
		perror("fopen");
		return -1;
	}

	printf("%d\n", sizeof(off_t));//off_t是一个长整形  long  可以比int容纳更多
	fseeko(pfile, (off_t)1024*(off_t)1024*(off_t)1024*(off_t)10, SEEK_SET);//以更大幅度的移动文件指针   fseeko    off_t类型
}
