 /**********************************************************************
 # File Name:   shuzufuzhi_行参数组赋值_.c
 # Version:     1.0
 # Mail:        shiyanhk@gmail.com 
 # Created Time: 2015-03-19	
 ************************************************************************/
#include <stdio.h>
#include <string.h>


int fuzhi(char *a)
{
	strcat(a,"beifuzhila~");
	return 0;
}
int main(int argc,char **argv)
{
	char a[11]={0};
	fuzhi(a);
	printf("a:%s \n",a);
	return 0;
}


//得出结论  行参数组可以被返回  前提条件是  在外部分配的栈空间
