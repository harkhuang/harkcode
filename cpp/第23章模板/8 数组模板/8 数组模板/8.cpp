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
	cout<<"执行构造函数\n";
	for (int i=0;i<n;i++)
	{
		a[i]=(i+1);
	}
}
template<class T,int n>
people<T,n>::people(const T&t)
{
	cout<<"执行带一个参数的构造函数\n";
	for (int i=0;i<n;i++)
	{
		a[i]=t;
	}
}
template<class T,int n>
T&people<T,n>::operator[](int i)
{
	cout<<"执行下标运算符函数operator[]\n";
	if (i<0||i>=n)
	{
		cerr<<"超出数组限制，第:"<<i<<"个元素溢出\n";
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
	people<double,4>one;
	one.show();
	people<double,4>*p=new people<double,4>[4];
	for (int i=0;i<9;i++)
	{
		p[i]=one[i];
		p[i].show();
	}
	return 0;
}
