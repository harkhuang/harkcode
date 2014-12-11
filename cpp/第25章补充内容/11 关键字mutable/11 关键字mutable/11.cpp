#include <iostream> 
#include <iomanip> 
using namespace std; 
class A
{ 
public: 
	A(int i):x(i){} 
	int add() const//注意这里的const 
	{ 
		return ++x; 
	} 
private: 
	mutable int x;//你可以试着将这里的mutable去掉再编译试试 
}; 

void main() 
{ 
	A a(0); 
	for(int tmp,i=0;i<10;i++) 
	{ 
		tmp = a.add(); 
		cout<<setw(tmp)<<setfill(' ')<<tmp<<endl; 
	} 
} 
