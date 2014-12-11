#include <iostream>
using namespace std;
template<class T,int n>
class people
{
	public:
		people();
		people(const T&t);
		T&operator[](int i);
		void show();
	private:
		T a[n];
};
template<class T,int n>
people<T,n>::people()
{
	cout<<"ִ�й��캯��\n";
	for (int i=0;i<n;i++)
	{
		a[i]=(i+1);
	}
}
template<class T,int n>
people<T,n>::people(const T&t)
{
	cout<<"ִ�д�һ�������Ĺ��캯��\n";
	for (int i=0;i<n;i++)
	{
		a[i]=t;
	}
}
template<class T,int n>
T&people<T,n>::operator[](int i)
{
	cout<<"ִ���±����������operator[]\n";
	if (i<0||i>=n)
	{
		cerr<<"�����������ƣ���"<<i<<"��Ԫ�����\n";
		exit(EXIT_FAILURE);
	}
	return a[i];
}
template<class T,int n>
void people<T,n>::show()
{
	for (int i=0;i<n;i++)
	{
		cout<<"a["<<i<<"]:"<<a[i]<<"\t";
	}
	cout<<endl;
}
int main()
{
	people<people<int,2>,3>two;
	int obj=1;
	for (int i=0;i<4;i++)
	{
		int sum=1;
		for (int j=0;j<2;j++)
		{
			cout<<"\ntwo["<<i<<"]["<<j<<"]:"<<two[i][j]<<"\n";
			cout<<"��"<<sum++<<"��Ԫ��������\n\n";
		}
		cout<<"��"<<obj++<<"�������е�����Ԫ��������\n\n";
	}
	return 0;
}
