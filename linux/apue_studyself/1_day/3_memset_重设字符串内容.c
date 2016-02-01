#include <stdio.h>
#include <string.h>
/*fgets(buf,n,pf)        memset(buf, 0, sizeof(char)*5)*/
int main()
{
	FILE *stream;//定义文件指针
	char buf[20];//定义字符数组

	stream  = fopen("file.txt","r");//打开文件 并返回文件指针  *stream  文件的指针是一个结构体  具体类型。。
	if(stream == NULL)//如果没成功的打开   
	{
		perror("fopen");
		return -1;
	}

	memset(buf, 0, sizeof(char)*5);//清理缓存 清空缓存,
	//memset(buf,0,0);  为什么两次结果一样？
	fgets(buf, sizeof(buf), stream);//从文件中获得一串字符  到  buf中
	printf("buf=%s\n", buf);//打印buf
}
