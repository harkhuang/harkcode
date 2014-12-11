/*
#include <iostream>
using namespace std;
int main()
{
	char ch1[]="Hello world",ch2[20];int i;
	for (i=0;*(ch1+i)!='\0';i++)
	{
		*(ch2+i)=*(ch1+i);
	}
	*(ch2+i)='\0';
	cout<<"ch1:"<<ch1<<endl;
	cout<<"ch2:"<<ch2<<endl;
	return 0;
} 
*/

#include <iostream>
using namespace std;
int main()
{
	char ch1[]="Hello world",ch2[20];
	char *p1=ch1,*p2=ch2;
	for (;*p1!='\0';p1++,p2++)
	{
		*p2=*p1;
	}
	*p2='\0';
	cout<<"ch1:"<<ch1<<endl;
	cout<<"ch2:"<<ch2<<endl;
	return 0;
}
