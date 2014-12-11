#include <iostream>
using namespace std;
class num 
{
public:
	num(){n=new int;*n=1;cout<<"构造函数执行\n";}
	//num(int i){n=new int;*n=i;cout<<"带参数的构造函数执行\n";}
	num(const num&s){n=new int;*n=s.get();cout<<"复制构造函数执行\n";}
	~num(){delete n;n=NULL;cout<<"析构函数执行\n";}
	int get()const{return *n;}
	void set(int x){*n=x;}
	//const num operator+(const num&r){return num(n+r.get());}
	
	//const num equal(const num&r){*n=r.get();return *this;}
	const num &operator=(const num&r)
	{
		if (this==&r)
		{
			return *this;
		}
		cout<<"operator=函数在调用\n";
		*n=r.get();
		return *this;
	}
private:
	int *n;
};
int main()
{
	num one,two;
	one.set(1);
	num three;
	three=one=one;
	
	cout<<three.get();
	
	return 0;
}