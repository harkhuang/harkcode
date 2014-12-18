/*未使用模板
#include <iostream>
using namespace std;
void swap(int &rx,int &ry)
{
	int temp=rx;
	rx=ry;
	ry=temp;
}
void swap(float&ra,float &rb)
{
	float temp=ra;
	ra=rb;
	rb=temp;
}
void swap(double&a,double &b)
{
	double temp=a;
	a=b;
	b=temp;
}
int main()
{
	int x=2,y=5;
	cout<<"交换前，x:"<<x<<" y:"<<y<<endl;
	swap(x,y);
	cout<<"交换后，x:"<<x<<" y:"<<y<<endl;
    float a=2.15f,b=5.34f;
	cout<<"交换前，a:"<<a<<" b:"<<b<<endl;
	swap(a,b);
	cout<<"交换后，a:"<<a<<" b:"<<b<<endl;
	cout<<fixed;
    double c=2.153456f,d=5.347283f;
	cout<<"交换前，c:"<<c<<" d:"<<d<<endl;
	swap(c,d);
	cout<<"交换后，c:"<<c<<" d:"<<d<<endl;
	return 0;
}
*/

//使用模板
#include <iostream>
using namespace std;
template<class Type>
Tswap(Type &rx,Type &ry)
{
	Type temp=rx;
	rx=ry;
	ry=temp;
}
int main()
{
	int x=2,y=5;
	cout<<"交换前，x:"<<x<<" y:"<<y<<endl;
	Tswap(x,y);
	cout<<"交换后，x:"<<x<<" y:"<<y<<endl;
    float a=2.15f,b=5.34f;
	cout<<"交换前，a:"<<a<<" b:"<<b<<endl;
	Tswap(a,b);
	cout<<"交换后，a:"<<a<<" b:"<<b<<endl;
	cout<<fixed;
    double c=2.153456f,d=5.347283f;
	cout<<"交换前，c:"<<c<<" d:"<<d<<endl;
	Tswap(c,d);
	cout<<"交换后，c:"<<c<<" d:"<<d<<endl;
	return 0;
}
