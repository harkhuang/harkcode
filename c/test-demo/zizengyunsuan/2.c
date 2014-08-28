#include<stdio.h>


int  main()

{

	int a,c;
	c=0;
	a=2;
	int *p;
	p=&a,
	printf("*p=%d                p=%x\n",*p,p),
	c=*(p++),
	printf("*p=%d *p++=%d p=%x\n",*p,c,p); 

	//printf("*p=%d *p++=%d *p=%d",*p,*p++,*p); // 3 2 2
	
	return 0;
}
