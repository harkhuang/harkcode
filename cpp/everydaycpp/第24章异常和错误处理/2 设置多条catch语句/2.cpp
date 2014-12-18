#include <iostream>
using namespace std;
const int num=5;
class people
{
public:
    people(int size=num);
    ~people(){delete[]p;}
    int&operator[](int off);
    const int&operator[](int off)const;
    int GetSize()const{return size;}
    class wrong{};
    class Zero{};
    class Small{};
    class Big{};
    class Nav{};
	private:
		int *p;
		int size;
};
people::people(int Size):size(Size)
{
    cout<<"���ù��캯��\n";
    if (Size==0)
    {
		throw Zero();
    }
	if (Size<10)
	{
		throw Small();
	}
	if (Size>10000)
	{
		throw Big();
	}
	if (Size<1)
	{
		throw Nav();
	}
	p=new int[size];
	for (int i=0;i<size;i++)
	{
		p[i]=0;
	}
}
int&people::operator[](int off)
{
	int size=GetSize();
	if (off>=0&&off<GetSize())
    {
		return p[off];
    }
	throw wrong();
	return p[0];
}
const int&people::operator[](int off)const
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
		people one(60000);
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
	catch (people::Big)
	{
		cout<<"�±�ֵ̫��\n";
	}
	catch (people::Small)
	{
		cout<<"�±�ֵ̫С\n";
	}
	catch (people::Zero)
	{
		cout<<"�±�ֵΪ0\n";
	}
	catch (people::Nav)
	{
		cout<<"�±�ֵΪ����\n";
	}
	cout<<"�������\b\n";
	return 0;
}
