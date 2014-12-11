/*
#include <iostream>
using namespace std;
int main()
{
	int ch[2][3]=
	{
		{0,1,2},
		{10,11,12}
	};
	int *p1=&ch[1][2];
	int*p2=ch[1]+2;
	int*p3=ch[0];
	int*p4=ch[1];
	cout<<*p1<<" "
		<<*p2<<" "
		<<*p3<<" "
		<<*p4<<endl;
	return 0;
}
*/


//¼ÓÇ¿ÑµÁ·
#include <iostream>
using namespace std;
int main()
{
	int a[3][4]=
	{
		1,2,3,4,
		11,12,13,14,
		111,112,113,114
	};
	cout<<a<<" "<<*a<<endl;
	cout<<a[0]<<" "<<*(a+0)<<endl;
	cout<<&a[0]<<" "<<&a[0][0]<<endl;
	cout<<a[1]<<" "<<a+1<<endl;
	cout<<&a[1][0]<<" "<<*(a+1)+0<<endl;
	cout<<a[2]<<" "<<*(a+2)<<endl;
	cout<<&a[2]<<" "<<a+2<<endl;
	cout<<a[1][0]<<" "<<*(*(a+1)+0)<<endl;
	return 0;
}
