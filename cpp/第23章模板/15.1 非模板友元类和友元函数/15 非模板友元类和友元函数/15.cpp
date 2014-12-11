//错
/*
#include <iostream>
using namespace std;
const int size=10;
template<class T>
class num 
{
public:
	num(int Tsize=size);
	num(const num&r);
	~num(){delete[]pt;}
	num&operator=(const num&);
	T&operator[](int offset){return pt[offset];}
	const T&operator[](int offset)const
	{
		return pt[offset];
	}
	int GetSize() const {return numsize;}
	friend void print(num<T>);
private:
	int numsize;
	T*pt;
};
template<class T>
void print(num<T>sw)
{
	cout<<"friend函数执行\n";
	for (int i=0;i<sw.numsize;i++)
	{
		cout<<"num["<<i<<"]:\t";
		cout<<sw.pt[i]<<"\n";
	}
}
template<class T>
num<T>::num(int size):numsize(size)
{
	pt=new T[size];
	for (int i=0;i<size;i++)
	{
		pt[i]=0;
	}
}
template <class T>
num<T>::num(const num&r)
{
	numsize=r.GetSize();
	pt=new T[numsize];
	for (int i=0;i<numsize;i++)
	{
		pt[i]=r[i];
	}
}
template<class T>
num<T>&num<T>::operator=(const num&r)
{
	if (this==&r)
	{
		return *this;
		delete[]pt;
		numsize=r.GetSize();
		pt=new T[numsize];
		for (int i=0;i<numsize;i++)
		{
			pt[i]=r[i];
		}
	}
	return *this;
}
int main()
{
	num<int>one;
	for (int i=0;i<one.GetSize();i++)
	{
		one[i]=i*2;	
	}
	print(one);
	return 0;
}
*/

//正

#include <iostream>
using  std::cout;
const int size=10;
template<class T>
class num 
{
public:
	num(int Tsize=size);
	num(const num&r);
	~num(){delete[]pt;}
	num&operator=(const num&);
	T&operator[](int offset){return pt[offset];}
	const T&operator[](int offset)const
	{
		return pt[offset];
	}
	int GetSize() const {return numsize;}
	friend void print(num<T>);
private:
	int numsize;
	T*pt;
};
void print(num<int>sw)
{
	cout<<"friend函数执行\n";
	for (int i=0;i<sw.numsize;i++)
	{
		cout<<"num["<<i<<"]:\t";
		cout<<sw.pt[i]<<"\n";
	}
}
void print(num<double>sw)
{
	cout<<"friend函数执行\n";
	for (int i=0;i<sw.numsize;i++)
	{
		cout<<"num["<<i<<"]:\t";
		cout<<sw.pt[i]<<"\n";
	}
}
template<class T>
num<T>::num(int size):numsize(size)
{
	pt=new T[size];
	for (int i=0;i<size;i++)
	{
		pt[i]=0;
	}
}
template <class T>
num<T>::num(const num&r)
{
	numsize=r.GetSize();
	pt=new T[numsize];
	for (int i=0;i<numsize;i++)
	{
		pt[i]=r[i];
	}
}
template<class T>
num<T>&num<T>::operator=(const num&r)
{
	if (this==&r)
	{
		return *this;
		delete[]pt;
		numsize=r.GetSize();
		pt=new T[numsize];
		for (int i=0;i<numsize;i++)
		{
			pt[i]=r[i];
		}
	}
	return *this;
}
int main()
{
	num<int>one;
	num<double>two;
	for (int i=0;i<one.GetSize();i++)
	{
		one[i]=i*2;	
	}
	print(one);
	print(two);
	return 0;
} 
