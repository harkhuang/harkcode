//例23.16.1 未具体化num模板类构造函数
/*
#include <iostream>
using  namespace std;
const int size=2;
class people
{
public:
	people(int);
	people();
	~people();
	int GetAge()const{return age;}
	void SetAge(int the){age=the;}
	people &operator=(const people&r)
	{
		cout<<"调用people类的operator=函数…\n";
		if (this==&r)
		{
			return *this;
			
		}
		age=r.age;
		return *this;
	}
	friend ostream&operator<<(ostream&,const people&);
private:
	int age;
};
ostream&operator<<(ostream&out,const people&the)
{
	cout<<"调用people类的operator<<函数…\n";
	out<<the.GetAge();
	return out;
}
people::people(int thisAge):age(thisAge)
{
	cout<<"调用people类的带一个参数的构造函数…\n";
}
people::people():age(0)
{
	cout<<"调用people类的默认构造函数…\n";
}
people::~people()
{
	cout<<"调用people类的析构函数…\n";
}
template <template <class T> class TT,class T> 
ostream & operator << (ostream &out, const TT<T> &tt); 
template<class T>
class num 
{
public:
	num(int Tsize=size);
	~num(){cout<<"调用num模板类的析造函数…\n";delete[]pt;}
	num&operator=(const num&);
	T&operator[](int offset){return pt[offset];}
	const T&operator[](int offset)const
	{
		return pt[offset];
	}
	int GetSize() const {return numsize;}
	friend ostream & operator << <>(ostream &out, const num<T> &tt); 
private:
	int numsize;
	T*pt;
};    
template <template <class T> class TT, class T> 
ostream & operator << (ostream &out, const TT<T> &tt) 
{
	out<<"调用num模板类的operator<<函数…\n";
	for (int i=0;i<tt.GetSize();i++)
	{
		out<<tt[i]<<endl;
	}
	return out;
}
template<class T>
num<T>::num(int size):numsize(size)
{
	cout<<"调用num模板类的带一个参数的构造函数…\n";
	pt=new T[size];
	for (int i=0;i<size;i++)
	{
		pt[i]=0;
	}
}
template<class T>
num<T>&num<T>::operator=(const num&r)
{
	cout<<"调用num模板类的operator=函数…\n";
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
	//num<int>one;
	num<people>two;
	for (int i=0;i<two.GetSize();i++)
	{
		//one[i]=i*2;	
		two[i]=i*3;
	}
	///cout<<one;
	cout<<two;
	return 0;
}
*/


//例23.16.2   增加具体化的num模板类构造函数


#include <iostream>
using  namespace std;
const int size=2;
class people
{
public:
	people(int);
	people();
	~people();
	int GetAge()const{return age;}
	void SetAge(int the){age=the;}
	people &operator=(const people&r)
	{
		cout<<"调用people类的operator=函数...\n";
		if (this==&r)
		{
			return *this;
			
		}
		age=r.age;
		return *this;
	}
	friend ostream&operator<<(ostream&,const people&);
private:
	int age;
};
ostream&operator<<(ostream&out,const people&the)
{
	cout<<"调用people类的operator<<函数...\n";
	out<<the.GetAge();
	return out;
}
people::people(int thisAge):age(thisAge)
{
	cout<<"调用people类的带一个参数的构造函数...\n";
}
people::people():age(0)
{
	cout<<"调用people类的默认构造函数...\n";
}
people::~people()
{
	cout<<"调用people类的析构函数...\n";
}
template <template <class T> class TT,class T> 
ostream & operator << (ostream &out, const TT<T> &tt); 
template<class T>
class num 
{
public:
	num(int Tsize=size);
	~num(){cout<<"调用num模板类的析造函数...\n";delete[]pt;}
	num&operator=(const num&);
	T&operator[](int offset){return pt[offset];}
	const T&operator[](int offset)const
	{
		return pt[offset];
	}
	int GetSize() const {return numsize;}
	friend ostream & operator << <>(ostream &out, const num<T> &tt); 
private:
	int numsize;
	T*pt;
};    
template <template <class T> class TT, class T> 
ostream & operator << (ostream &out, const TT<T> &tt) 
{
	out<<"调用num模板类的operator<<函数...\n";
	for (int i=0;i<tt.GetSize();i++)
	{
		out<<tt[i]<<endl;
	}
	return out;
}
template<class T>
num<T>::num(int size):numsize(size)
{
	cout<<"调用num模板类的带一个参数的构造函数...\n";
	pt=new T[size];
	for (int i=0;i<size;i++)
	{
		pt[i]=0;
	}
}
num<people>::num(int num):numsize(num)
{
	cout<<"调用num模板类的带一个参数的特殊构造函数...\n";
	pt=new people[num];
}
template<class T>
num<T>&num<T>::operator=(const num&r)
{
	cout<<"调用num模板类的operator=函数...\n";
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
	//num<int>one;
	num<people>two;
	for (int i=0;i<two.GetSize();i++)
	{
		//one[i]=i*2;	
		two[i]=i*3;
	}
	//cout<<one;
	cout<<two;
	return 0;
}
