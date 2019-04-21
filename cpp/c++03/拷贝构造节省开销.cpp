#include <iostream>
using namespace std;

class A
{
public:
	A(){cout<<"gouzhaohanshu...\n";}
	A(A&){cout<<"kaobei-gouzhaohanshu...\n";}
	~A(){cout<<"xigouhanshu...\n";}
};

A func(A a)
{
	cout<<"func:";
	return a;
}
int main()
{
	A a;
	func(a);
	printf("%s\n","hello" );
	getchar();
	return 0;
}