#include<stdio.h>
main()
{
int a[3][4]={{3,17,8,11},{66,7,8,19},{12,88,7,16}};
int *p=a[0],max,i,j,row,col;
max=a[0][0];
row=col=0;
for(i=0;i<3;i++)
for(j=0;j<4;j++)
if(*(p+i*4+j)>max)
{
max=*(p+i*4+j);
row=i;
col=j;
}
printf("a[%d][%d]=%d/n",row,col,max);
}
