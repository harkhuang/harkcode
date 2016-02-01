#include <stdio.h>
/*while(!feof(pf))    ret = getline(&pbuf, &len, pf);  */
int main()
{
	FILE *pf;//定义一个文件指针  不要忘记 ‘*’
	char *pbuf=NULL;//定义一个字符串
	int len=0;//定义一个长度
	int i=0;//定义一个
	int ret;//一个整型的返回值

	pf = fopen("1.c", "r");//只读的方式打开当前路径下的文件1.c
	if(pf == NULL)//如果文件指针不为空
	{
		perror("fopen");
		return -1;//return 
	}
	//cat filename
	while(!feof(pf))//文件不结束    feof判断是不是文件的结尾
	{
		ret = getline(&pbuf, &len, pf);//将文件中的内容写到字符数组中   （自己定义的字符数组）  len代表的值是。。获得的字符个数
		//获得一个pbuf字符串   获得一个长度  len   
#if 1
		if(ret == -1)//如果返回值是-1表示没有获得成功
		{
			break;
		}
#endif
		fprintf(stdout, "<len=%d>%s", len,pbuf);//将字符流发射到当前标准的输入输出 以 "<len=%d>%s"格式 长度是len的  pbuf写入pbuf
	}

	return 0;

}









