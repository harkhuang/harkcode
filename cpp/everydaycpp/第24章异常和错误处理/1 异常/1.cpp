/*���쳣��ʾ
#include <iostream>
using namespace std;
class wrong{};
void error()
{
	cout<<"����\n";
	throw wrong();
}
int main()
{
	try
	{
		error();
	}
	catch (wrong)
	{
		cout<<"�ô����Ѿ����\n";
	}
	return  0;
}
*/

//���ӵ���쳣��ʾ
#include <iostream>
using namespace std;
const int num=5;
class people
{
public:
    people(int size=num);
    people(const people&r);
    ~people(){delete[]p;}
    people&operator=(const people&);
    int&operator[](int off);
    const int&operator[](int off)const;
    int GetSize()const{return size;}
    friend ostream&operator<<(ostream&,const people&);
    class wrong{};
	private:
		int *p;
		int size;
};
people::people(int Size):size(Size)
{
	p=new int[size];
	for (int i=0;i<size;i++)
	{
		p[i]=0;
	}
}
people&people::operator =(const people&r)
{
	if (this==&r)
	{
		return *this;
	}
	delete[]p;
	size=r.GetSize();
	p=new int[size];
	for (int i=0;i<size;i++)
	{
		p[i]=r[i];
	}
	return *this;
}
people::people(const people&r)
{
	size=r.GetSize();
	p=new int(size);
	for (int i=0;i<size;i++)
	{
		p[i]=r[i];
	}
}
int&people::operator [](int off)
{
	int size=GetSize();
	if (off>=0&&off<GetSize())
	{
		return p[off];
	}
	throw wrong();
	return p[0];
}
const int&people::operator [](int off)const
{
	int Size=GetSize();
	if (off>=0&&off<GetSize())
	{
		return p[off];
	}
	throw wrong();
	return p[0];
}
ostream &operator<<(ostream&out,const people&the)
{
	for (int i=0;i<the.GetSize();i++)
	{
		out<<"["<<i<<"]"<<the[i]<<endl;
	}
	return out;
}
int main()
{
	people one(20);
	try
	{
		for (int i=0;i<100;i++)
		{
			one[i]=i;
			cout<<"one["<<i<<"]��ֵ���..."<<endl;
		}
	}
	catch (people::wrong)
	{
		cout<<"�������鳤�ȣ����ܼ���ִ�и�ֵ������\n";
	}
	cout<<"�������\b\n";
	return 0;
}
