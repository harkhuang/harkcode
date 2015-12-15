 /**********************************************************************
 # File Name:   nullptr.c
 # Version:     1.0
 # Mail:        shiyanhk@gmail.com 
 # Created Time: 2015-03-23	
 ************************************************************************/
#include <stdio.h>

int main(int argc,char **argv)
{
	char *ptr =NULL;
	*ptr = "";
	if(strcmp(ptr ,"")  == 0)
	
	{
		printf("ptr==0\n" );
	}
	return 0;
}

