
// aa.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"
#include "stdio.h"
#include "math.h"


int main(void)
{
	int a;
	int b;
	int c;
	double delta;   //delta=b*b-4*a*c
	double x1;
	double x2;
	double x;
	char f;

	
	printf("delta = %d\n",delta);
	printf("==================一元二次方程a*x*x+b*x+c=0求解===============\n");
	qiujie:
	printf("请依次输入a,b,c三个数的值：\n");
	scanf("%d%d%d",&a,&b,&c);
	delta=b*b-4*a*c;
	if(a==0)
	{
		x=-c/b;
		printf("a=0,构不成一元二次方程,x=%lf\n",x);
		printf("是否重新输入？请输入y或n\n");
		scanf("%c",&f);
		if(f=='y')
			{
				goto qiujie;
			}
		else
			{
				printf("即将退出\n");
			}
		
		
	}
	else
	{
		printf("该方程为一元二次方程");
		if(delta>0)
		{
			x1=(-b+sqrt(delta))/(2*a);
			x2=(-b-sqrt(delta))/(2*a);
			printf("该方程有两个解：x1=%lf,x2=%lf",x1,x2);
		}
		else if(delta==0)
		{
			x1=(-b)/2*a;
			printf("该方程有两个解：x1=x2=%lf",x1);
		}
		else
		{
			printf("该方程无解，是否重新输入？请输入y或n\n");
			scanf("%c",&f);
			printf("%c\n",f);
			if(f == 'y')
			{
				goto qiujie;
			}
			else
			{
				printf("即将退出");
				sleep(1);
				printf("sleep  out");
				return 0;
			}

		}
	}
	return 0;
}
