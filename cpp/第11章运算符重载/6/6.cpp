#include <iostream>
using namespace std;
class num 
{
public:
	num(){n=1;cout<<"构造函数执行\n";}
	num(int i){n=i;cout<<"带参数的构造函数执行\n";}
	num(const num&s){n=s.n;cout<<"复制构造函数执行\n";}
	~num(){cout<<"析构函数执行\n";}
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