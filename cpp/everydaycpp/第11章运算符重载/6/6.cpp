#include <iostream>
using namespace std;
class num 
{
public:
	num(){n=1;cout<<"���캯��ִ��\n";}
	num(int i){n=i;cout<<"�������Ĺ��캯��ִ��\n";}
	num(const num&s){n=s.n;cout<<"���ƹ��캯��ִ��\n";}
	~num(){cout<<"��������ִ��\n";}
	int get()const{return n;}
	void set(int x){n=x;}
	void add(){++n;}
	const num &operator++()
	{
		++n;
		
		
		return *this;
	}
private:
	int n;
};
int main()
{
	num i;
	cout<<"i:"<<i.get()<<endl;
	i.add();
	cout<<"i:"<<i.get()<<endl;
	num n=++i;
	
	cout<<"n:"<<n.get()<<endl;
	return 0;
}