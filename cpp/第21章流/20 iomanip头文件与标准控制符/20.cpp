/*
//例21.20.1 	setw()、setfill()和setprecision()的使用
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float n=3.1456f;
	for(int i=0;i<5;i++)
	{
		n=n*n;
		cout<<setw(6)<<setfill('.')<<i<<setfill(' ')<<setw(22)<<setprecision(2)<<fixed<<n<<endl;
	}
	return 0;
}
*/
//例21.20.2   showpoint标志的作用
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float n=3.1456f;
	for(int i=0;i<5;i++)
	{
		n=n*n;
		cout<<setw(6)<<setfill('.')<<i<<setfill(' ')<<setw(22)<<setprecision(2)<<showpoint<<n<<endl;
	}
	return 0;
} 
