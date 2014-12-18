/*δʹ��ģ��
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
	cout<<"����ǰ��x:"<<x<<" y:"<<y<<endl;
	swap(x,y);
	cout<<"������x:"<<x<<" y:"<<y<<endl;
    float a=2.15f,b=5.34f;
	cout<<"����ǰ��a:"<<a<<" b:"<<b<<endl;
	swap(a,b);
	cout<<"������a:"<<a<<" b:"<<b<<endl;
	cout<<fixed;
    double c=2.153456f,d=5.347283f;
	cout<<"����ǰ��c:"<<c<<" d:"<<d<<endl;
	swap(c,d);
	cout<<"������c:"<<c<<" d:"<<d<<endl;
	return 0;
}
*/

//ʹ��ģ��
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
	cout<<"����ǰ��x:"<<x<<" y:"<<y<<endl;
	Tswap(x,y);
	cout<<"������x:"<<x<<" y:"<<y<<endl;
    float a=2.15f,b=5.34f;
	cout<<"����ǰ��a:"<<a<<" b:"<<b<<endl;
	Tswap(a,b);
	cout<<"������a:"<<a<<" b:"<<b<<endl;
	cout<<fixed;
    double c=2.153456f,d=5.347283f;
	cout<<"����ǰ��c:"<<c<<" d:"<<d<<endl;
	Tswap(c,d);
	cout<<"������c:"<<c<<" d:"<<d<<endl;
	return 0;
}
