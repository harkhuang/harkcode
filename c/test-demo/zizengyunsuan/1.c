#include<stdio.h>


int  main()

{
	int i =1;
	int a,b,c ;
    a=i++,b=i++,c=i++;
	//printf("a:%d  b:%d  c:%d\n",a,b,c	);//输出结果是  1  2   3
	i=0;
	//printf(":%d  :%d  :%d\n",i++,i++,i++	);//输出结果是  2 1 0
	
	
	
	c=0;
	a=2;
	int *p;
	p=&a;	
	printf("*p=%d p=%x\n",*p,p); 
	c=*p++;
	printf("*p=%d *p++=%d p=%x\n",*p,c,p); 

	//printf("*p=%d *p++=%d *p=%d",*p,*p++,*p); // 3 2 2
	
	return 0;
}
