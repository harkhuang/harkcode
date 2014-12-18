#include <iostream>
using namespace std;
class num 
{
public:
	num(){n=1;}
	~num(){}
	int get()const{return n;}
	void set(int x){n=x;}
	void add(){++n;}
	num operator++()
	{
		++n;
		num t;
		t.set(n);
		return t;
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
	//num n=i.operator++();
	cout<<"n:"<<n.get()<<endl;
	return 0;
}