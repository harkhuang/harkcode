#include<stdio.h>
int main()
{
	
	int i,j,t;
	int arr[5];
	int n=5;

	for(i=0;i<5;i++)
	{
		scanf("%d",&arr[i]);	
	}
	
     for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            if(arr[j+1]<arr[j])
            {
              t=arr[j+1];
              arr[j+1]=arr[j];
              arr[j]=t;
             }
	for(i=0;i<5;i++)
	{
		printf("%d\n",arr[i]);	
	}
}