//��23.16.1 δ���廯numģ���๹�캯��
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
		cout<<"����people���operator=������\n";
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
	cout<<"����people���operator<<������\n";
	out<<the.GetAge();
	return out;
}
people::people(int thisAge):age(thisAge)
{
	cout<<"����people��Ĵ�һ�������Ĺ��캯����\n";
}
people::people():age(0)
{
	cout<<"����people���Ĭ�Ϲ��캯����\n";
}
people::~people()
{
	cout<<"����people�������������\n";
}
template <template <class T> class TT,class T> 
ostream & operator << (ostream &out, const TT<T> &tt); 
template<class T>
class num 
{
public:
	num(int Tsize=size);
	~num(){cout<<"����numģ��������캯����\n";delete[]pt;}
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
	out<<"����numģ�����operator<<������\n";
	for (int i=0;i<tt.GetSize();i++)
	{
		out<<tt[i]<<endl;
	}
	return out;
}
template<class T>
num<T>::num(int size):numsize(size)
{
	cout<<"����numģ����Ĵ�һ�������Ĺ��캯����\n";
	pt=new T[size];
	for (int i=0;i<size;i++)
	{
		pt[i]=0;
	}
}
template<class T>
num<T>&num<T>::operator=(const num&r)
{
	cout<<"����numģ�����operator=������\n";
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


//��23.16.2   ���Ӿ��廯��numģ���๹�캯��


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
		cout<<"����people���operator=����...\n";
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
	cout<<"����people���operator<<����...\n";
	out<<the.GetAge();
	return out;
}
people::people(int thisAge):age(thisAge)
{
	cout<<"����people��Ĵ�һ�������Ĺ��캯��...\n";
}
people::people():age(0)
{
	cout<<"����people���Ĭ�Ϲ��캯��...\n";
}
people::~people()
{
	cout<<"����people�����������...\n";
}
template <template <class T> class TT,class T> 
ostream & operator << (ostream &out, const TT<T> &tt); 
template<class T>
class num 
{
public:
	num(int Tsize=size);
	~num(){cout<<"����numģ��������캯��...\n";delete[]pt;}
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
	out<<"����numģ�����operator<<����...\n";
	for (int i=0;i<tt.GetSize();i++)
	{
		out<<tt[i]<<endl;
	}
	return out;
}
template<class T>
num<T>::num(int size):numsize(size)
{
	cout<<"����numģ����Ĵ�һ�������Ĺ��캯��...\n";
	pt=new T[size];
	for (int i=0;i<size;i++)
	{
		pt[i]=0;
	}
}
num<people>::num(int num):numsize(num)
{
	cout<<"����numģ����Ĵ�һ�����������⹹�캯��...\n";
	pt=new people[num];
}
template<class T>
num<T>&num<T>::operator=(const num&r)
{
	cout<<"����numģ�����operator=����...\n";
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
