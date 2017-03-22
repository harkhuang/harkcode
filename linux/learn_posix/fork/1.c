 /**********************************************************************
 # File Name:   1.c
 # Version:     1.0
 # Mail:        shiyanhk@gmail.com 
 # Created Time: 2016-02-01	
 # Detail:      fopen test
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	FILE *pf;//a ptr  of file
	char buf[100]; 
	open file return a fileptr 
	FILE pf = fopen("my","w+"); 

	if(pf == NULL) //if error
	{
	perror("open()");
	exit(1);
	}

	strcpy(buf,"hello\n"); 

	fputs(buf,pf); 

	fclose(pf);

	bzero(buf,100);

	pf = fopen("my","a+"); 

	if(pf == NULL)
	{
	perror("open");
	exit(1);
	}

	strcpy(buf,"world\n"); 

	//put buf in file
	fputs(buf,pf); 

	fclose(pf);
}
		
