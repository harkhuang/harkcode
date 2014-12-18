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
		cerr<<"超出数组限制，第"<<i<<"个元素溢出\n";
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
			cout<<"第"<<sum++<<"个元素输出完毕\n\n";
		}
		cout<<"第"<<obj++<<"个对象中的数组元素输出完毕\n\n";
	}
	return 0;
}
