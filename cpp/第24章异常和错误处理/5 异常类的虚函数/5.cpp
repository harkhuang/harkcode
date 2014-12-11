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
	class offset
	{
	public:
		offset(int Size):size(Size){}
		~offset(){}
		virtual int Get(){return size;}
		virtual void show()
		{
			cout<<"�׳�offset�쳣\n";
			cout<<"�±�ֵ"<<size<<"����"<<endl;
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
			cout<<"�׳�Big�쳣\n";
			cout<<"�±�ֵ"<<offset::size<<"����"<<endl;
		}
	};
	class Nav:public offset
	{
	public:
		Nav(int Size):offset(Size){}
		virtual void show()
		{
			cout<<"�׳�Nav�쳣\n";
			cout<<"�±�ֵ"<<offset::size<<"����"<<endl;
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
			cout<<"�׳�Small�쳣\n";
			cout<<"�±�ֵ"<<size<<"����"<<endl;
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
			cout<<"�׳�Zero�쳣\n";
			cout<<"�±�ֵ"<<Small::size<<"����"<<endl;
		}
	};
private:
	int *p;
	int size;
};
people::people(int Size):size(Size)
{
	cout<<"���ù��캯��\n";
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
		people one(0);
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
	catch (people::Small &small)
	{
		small.show();
	}
	catch (people::offset &off) 
	{
		off.show();
	}
	catch (...) 
	{
		cout<<"��������쳣"<<endl;
	}
	return 0;
}
