#include <stdio.h>
/*设置标准输入输出setbuf(stdin, outbuf)*/
int main()
{
	int i;//定义一个整型
	FILE *stream;//定义一个文件结构体指针
	char pdata[5];//定义一个字符数组
	char outbuf[10];//定义一个字符数组

	stream = fopen("file.txt", "r+");//打开一个文件以读写的方式打开
	if(stream  == NULL)//如果文件指针没成功打开指针是空！
	{
		perror("fopen");//显示错误
		return -1;//返回-1  结束
	}
	
	setbuf(stdin, outbuf);//将outbuf设置成标准输入 ？  实现函数设置条件编译
	fread(pdata, sizeof(pdata), 1, stdin);//从标准输入中读取  1  表示一块长度为data大小的数据
	printf("pdata=%s\n", pdata);//输出一个data

	fwrite(outbuf, sizeof(outbuf), 1, stream);//写入数据   
	fclose(stream);//关闭文件指针  使用完要释放
}












