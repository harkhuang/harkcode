#include <iostream>
using namespace std;
/*
void copy(char a[],char b[])
{
	int i;
	for ( i=0;a[i]!=0;i++)
	{
		b[i]=a[i];
	}
	b[i]='\0';
}
*/

/*
void copy(char *a,char *b)
{
	for (;*a!=0;a++,b++)
	{
		*b=*a;
	}
	*b='\0';
}
*/

void copy(char *a,char *b)
{
	 char*p1,*p2;
	 p1=a;p2=b;
     /*
	 for (;*p1!=0;p1++,p2++)
	 {
		*p2=*p1;
	 }
	 */

	 //¼ò»¯
	 //for (;(*p2++=*p1++)!=0;)

	//¼ÌÐø¼ò»¯
	 for (;*p2++=*p1++;)

	 *p2='\0';
}

int main()
{
	char ch1[]="Hello world",ch2[20];
	copy(ch1,ch2);
	cout<<"ch1:"<<ch1<<endl;
	cout<<"ch2:"<<ch2<<endl;
	return 0;
} 
