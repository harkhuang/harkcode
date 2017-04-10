#include <iostream>
using namespace std;

class A
{
public:
	A();
	A(A&)
	{
		cout<< "kaobeigouzhaohanshu...\n";
	}
	A* func_pointer(A *a)  ;
	A  func(A a);
	~A();
};

A::A()
{
	cout<< "gouzhaohanshu...\n";
}




A::~A()
{
	{cout<< "xigouhanshu...\n";}
}
A A::func(A a)
{
	cout<< "func:\n";
	return a;
}


A funcxx(A a)
{
	cout<< "func:\n";
	return a;
}

A* A::func_pointer(A *a)  //一定要注意定义 和 使用的区别!!!
{
	cout<< "func_pointer:\n";
	return a;
}

int main()   
{
	int k = 1;
	k = 100 + k;


	cout<<"-------------构造:-------------"<<endl;

	//默认执行无参数的构造函数
	A a;
	cout<<"-------------拷贝构造:-------------"<<endl;
	//仅仅执行了函数  做了指针的赋值 没有成员的拷贝操作
	A *c = a.func_pointer(&a);
	cout<<"-------------直接构造:-------------"<<endl;
	
	
	//默认执行拷贝构造  这个函数调用拷贝构造
	funcxx(a);
	getchar();
	return 0;
}

