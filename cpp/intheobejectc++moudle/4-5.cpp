#include <iostream>
using namespace std;

class Base {
public:
	void i() { cout << "Base::i" << endl; };
};
typedef  void   (*Fun)           (void);
typedef  void  (Base::*function )()  ;

void hifunctionptr() {
	std::cout << "hi function ptr" << std::endl;
}

int main()
{
	Fun xxx = hifunctionptr;
	(*xxx) ();
	xxx();

	void (Base:: * xxpsapd)() = &Base::i;


	function f = &Base::i;

	// 	f();   ///error
	Base b;
	(b.*f)  ();  // ok
	(b.*xxpsapd)();
	std::cout << sizeof(Base) << std::endl;  // 类大小是1

	//printf("%p", &Base::i);


	//union {
	//	void* pv;
	//	void(Base::* pfn)();
	//} u;
	//u.pfn = &Base::i;
	//Base b;
	//(b.*u.pfn)();
	//(b.*(u.pfn))();
}
 