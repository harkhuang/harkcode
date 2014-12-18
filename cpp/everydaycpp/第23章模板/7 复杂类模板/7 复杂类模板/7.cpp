#include <iostream>
using namespace std;
const int size=10;
class people
{
public:
	people(int i):x(i){}
	people():x(0){}
	int GetAge()const{return x;}
	void show()const{cout<<x;}
private:
	int x;
};
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
private:
	int numsize;
	T*pt;
};
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
	num<people>two;
	people*p;
	for (int i=0;i<one.GetSize();i++)
	{
		one[i]=i*2;
		p=new people(i*4);
		two[i]=*p;
		delete p;
	}
	for (int j=0;j<one.GetSize();j++)
	{
		cout<<"one["<<j<<"]:\t";
		cout<<one[j]<<"\t\t";
		cout<<"two["<<j<<"]:\t";
		two[j].show();
		cout<<endl;
	}
	return 0;
}
