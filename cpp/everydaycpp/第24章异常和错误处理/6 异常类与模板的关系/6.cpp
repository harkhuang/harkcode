#include <iostream>
using namespace std;
const int num=5;
class wrong{};
template <class T>
class people
{
public:
	people(int size=num);
	~people(){delete[]p;}
	T&operator[](int off);
	const T&operator[](int off)const;
	int GetSize()const{return size;}
	
	class offset
	{
	public:
		offset(int Size):size(Size){}
		~offset(){}
		virtual int Get(){return size;}
		virtual void show()
		{
			cout<<"抛出offset异常\n";
			cout<<"下标值"<<size<<"出错"<<endl;
		}
	protected:
		int size;
	};
	class Big:public offset
	{
	public:
		Big(int Size):offset(Size){}
		virtual void show()
		{
			cout<<"抛出Big异常\n";
			cout<<"下标值"<<offset::size<<"出错"<<endl;
		}
	};
	class Nav:public offset
	{
	public:
		Nav(int Size):offset(Size){}
		virtual void show()
		{
			cout<<"抛出Nav异常\n";
			cout<<"下标值"<<offset::size<<"出错"<<endl;
		}
	};
	class Small
	{
	public:
		Small(int Size):size(Size){}
		~Small(){}
		virtual int get(){return size;}
		virtual void show()
		{
			cout<<"抛出Small异常\n";
			cout<<"下标值"<<size<<"出错"<<endl;
		}
	protected:
		int size;
	};
	class Zero:public Small
	{
	public:
		Zero(int Size):Small(Size){}
		virtual void show()
		{
			cout<<"抛出Zero异常\n";
			cout<<"下标值"<<Small::size<<"出错"<<endl;
		}
	};
private:
	int *p;
	int size;
};
template<class T>
people<T>::people(int Size):size(Size)
{
	cout<<"调用构造函数\n";
	if (Size==0)
	{
		throw Zero(Size);
	}
	if (Size<10)
	{
		throw Small(Size);
	}
	if (Size>10000)
	{
		throw Big(Size);
	}
	if (Size<1)
	{
		throw Nav(Size);
	}
	p=new T[size];
	for (int i=0;i<size;i++)
	{
		p[i]=0;
	}
}
template<class T>
T&people<T>::operator[](int off)
{
	int size=GetSize();
	if (off>=0&&off<GetSize())
	{
		return p[off];
	}
	throw wrong();
	return p[0];
}
template<class T>
const T&people<T>::operator[](int off)const
{
	int Size=GetSize();
	if (off>=0&&off<GetSize())
	{
		return p[off];
	}
	throw wrong();
	return p[0];
}
int main()
{
	try
	{
		people<int> one(0);
		for (int i=0;i<100;i++)
		{
			one[i]=i;
			cout<<"one["<<i<<"]赋值完毕..."<<endl;
		}
	}
	catch (wrong)
	{
		cout<<"超过数组长度，不能继续执行赋值操作！\n";
	}
	catch (people<int>::Small &small)
	{
		small.show();
	}
	catch (people<int>::offset &off) 
	{
		off.show();
	}
	catch (...) 
	{
		cout<<"程序出现异常"<<endl;
	}
	return 0;
} 
