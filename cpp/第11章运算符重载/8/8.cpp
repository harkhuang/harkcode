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
	const num operator+(const num&r){return num(n+r.get());}
	const num &operator++()
	{
		++n;
		
		
		return *this;
	}
	const num operator++(int o)
	{
		num temp(*this);
		++n;
		return temp;
	}
private:
	int n;
};
int main()
{
	num one(1),two(2),three;
	//three=one.add(two);
	three=one+two;
	cout<<"one:"<<one.get()<<endl;
	cout<<"two:"<<two.get()<<endl;
	cout<<"three:"<<three.get()<<endl;
	return 0;
}