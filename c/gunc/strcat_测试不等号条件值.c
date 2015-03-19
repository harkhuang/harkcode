 /**********************************************************************
 # File Name:   strcat_测试不等号条件值.c
 # Version:     1.0
 # Mail:        shiyanhk@gmail.com 
 # Created Time: 2015-03-19	
 ************************************************************************/
#include <stdio.h>




//strcat 是将两个长字符串拼接成一个字符串
void myStrcat(char string1[], char string2[])
{
	//找string1的'\0'位置
	int i = 0;
	while (string1[i] != '\0')
	{
		i++;
	}

	//把string2加到string1后面
	int j = 0;
	while (string2[j] != '\0')
	{
		string1[i++] = string2[j++];
	}

	//不要忘记在最后添加\0
	string1[i] = '\0';
}
int main(int argc,char **argv)
{
	///test 1
	if(1!=2)
	{
		printf("1!=2 进入...\n");
	}
	if(1!=1)
	{
		printf("1!=1 进入判断条件。。。\n");
	}

	//test 2
	char buff1[100]={"aa\0a"}; //虽然打印出只有aa， 但是buff1 里面是有两个字符串的    一个'\0'认为是一个字符串
	char buff2[100]={"bbb"};
	
	printf("before mystrcat buff1 :%s  buff2:%s \n",buff1,buff2 );
	myStrcat(buff1, buff2);
	printf("after mystrcat buff1 :%s  buff2:%s \n",buff1,buff2 );
	
	
	
	return 0;
}

