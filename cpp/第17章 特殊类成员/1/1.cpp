#include <iostream>
using namespace std;
class A 
{
public:
	A(int num):it(num){total++;}
	static int total;
	 ~A(){total--;}
	 int get(){return it;}
	 void set(int age){it=age;}
private:
	int it;
};
int A::total=0;
void show()
{
	cout<<A::total<<endl;
}
int main()
{
	/*const int max=5;
	int i;
	A*a[max];
	for (i=0;i<max;i++)
	{
		a[i]=new A(i);
	}
	for (i=0;i<max;i++)
	{
		cout<<"������"<<A::total<<"������\n";
		cout<<"����ɾ����"<<a[i]->get()<<"������\n";
		delete a[i];
	}*/
	//A a(1),b(2),c(3);
	//cout<<a.get()<<endl<<b.get()<<endl<<c.get();
	int i;
	for (i=0;i<5;i++)
	{
		A::total++;
		show();
	}
	return 0;
}
