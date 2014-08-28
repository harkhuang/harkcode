 /**********************************************************************
 # File Name:   qsort.c
 # Version:     1.0
 # Mail:        shiyanhk@gmail.com 
 # Created Time: 2014-08-22	
 ************************************************************************/
#include <stdio.h>


void QuickSort(int a[],int numsize)/*a是整形数组，numsize是元素个数*/
{
	int i=0,j=numsize-1;
	int val=a[0];/*指定参考值val大小*/
if(numsize>1)/*确保数组长度至少为2，否则无需排序*/
{
	while(i<j)/*循环结束条件*/
	{
	/*从后向前搜索比val小的元素，找到后填到a[i]中并跳出循环*/
		for(;j>i;j--)
		if(a[j]<val)
		{
			a[i]=a[j];
			break;
		}
	/*从前往后搜索比val大的元素，找到后填到a[j]中并跳出循环*/
		for(;i<j;i++)
		if(a[i]>val)
		{
			a[j]=a[i];
			break;
		}
	}
	a[i]=val;/*将保存在val中的数放到a[i]中*/
	QuickSort(a,i);/*递归，对前i个数排序*/
	QuickSort(a+i+1,numsize-1-i);/*对i+1到numsize-1这numsize-1-i个数排序*/
}
}
 

int arry[]={1,22,33,41,2,23,451,12,66,8,12,85};
int size =12;

int main(int argc,char **argv)
{
	int i=0;
	QuickSort(arry,12 );
	for(i=0;i++;i<12)
	printf("a[%d]:%d",i,arry[i]);
	return 0;
}

