#include <iostream> 
#include <iomanip> 
using namespace std; 
class A
{ 
public: 
	A(int i):x(i){} 
	int add() const//ע�������const 
	{ 
		return ++x; 
	} 
private: 
	mutable int x;//��������Ž������mutableȥ���ٱ������� 
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
