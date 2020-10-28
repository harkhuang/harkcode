#include <iostream>
#include <algorithm>
#include "vector"



class CEmpty1 {
public:
	char a1;
};


class CEmpty2 :public  CEmpty1 {
public:
	char a2;
};



// 继承过程中不会assiment padding.
class CEmpty3 :public  CEmpty2 {
public:
	char a3;
};



class CEmpty4  {
public:
	char a3;
};


class CEmpty {
public:
	static int b;
	static int c;
	static int d;
	int a;
	virtual void func() {};
};



class       CEmpty5 {
public:
	int m_a;
	short int m_b;
	//int GetValue() { return m_a; }
};

int main()
{


	std::cout << sizeof(CEmpty1) << std::endl;
	std::cout << sizeof(CEmpty2) << std::endl;
	std::cout << sizeof(CEmpty3) << std::endl;
	std::cout << sizeof(CEmpty4) << std::endl;
	std::cout << sizeof(CEmpty5) << std::endl;

	CEmpty empty;

	std::cout << sizeof(CEmpty) << std::endl;
	std::cout << sizeof(empty) << std::endl;


	return 0;
}