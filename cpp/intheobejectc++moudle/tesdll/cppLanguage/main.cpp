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

A* A::func_pointer(A *a)  //һ��Ҫע�ⶨ�� �� ʹ�õ�����!!!
{
	cout<< "func_pointer:\n";
	return a;
}

int main()   
{
	int k = 1;
	k = 100 + k;


	cout<<"-------------����:-------------"<<endl;

	//Ĭ��ִ���޲����Ĺ��캯��
	A a;
	cout<<"-------------��������:-------------"<<endl;
	//����ִ���˺���  ����ָ��ĸ�ֵ û�г�Ա�Ŀ�������
	A *c = a.func_pointer(&a);
	cout<<"-------------ֱ�ӹ���:-------------"<<endl;
	
	
	//Ĭ��ִ�п�������  ����������ÿ�������
	funcxx(a);
	getchar();
	return 0;
}

