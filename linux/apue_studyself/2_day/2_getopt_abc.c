#include <unistd.h>
#include "../apue.h"
/*参数选项实现的函数*/

/*
optarg: 选项参数
optind: 再一次getopt时下一个argv的下标

*/
int main(int argc, char **argv)//定义的是一个  字符个数  字符串的地址数组
{
	int ret;//定义一个整型

	while((ret = getopt(argc, argv, "-abc"))!=-1)//当ret  的返回  
	{
		//printf("ch=%d\n", ch);
		//./exe -abc file 
		switch(ret)//选择的字符
		{
			case 1://当返回值是1的时候执行
			{
				printf("1:optind=%d\n", optind);//打印选的
				printf("1:%s\n", argv[optind-1]);//打印第一个字符串
				break;
			}
			case 'a'://pid=1   
			{
				printf("a\n");
				printf("optind=%d\n", optind);
				break;
			}
			case 'b'://pid=1
			{
				printf("b\n");
				printf("optind=%d\n", optind);
				break;
			}
			case 'c'://pid = 2  为什么这个等于2？？？？？？？！！！！！！！！！！！！
			{
				printf("c\n");
				printf("optind=%d\n", optind);
				break;
			}
			case '?'://容错  当输入的不是选项 返回的是‘？’  
			{
				printf("nothing\n");
				printf("optind=%c\n", optind);
				break;
			}

		}
	}
	
	//printf("%s\n", argv[optind]);
}
//getopt获得选择option  返回的optind  控制optind操作
