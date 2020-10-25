#include <random>
#include <iostream>
#include <memory>
#include <functional>

void f(int n1, int n2, int n3,  int& n4, int n5)
{
	std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
	n4 = 8;
}

int g(int n1)
{
	return n1;
}

struct Foo {
	void print_sum(int n1, int n2)
	{
		std::cout << n1 + n2 << '\n';
	}
	int data = 10;
};

int test_bind1()
{
	using namespace std::placeholders;  // for _1, _2, _3...

	// demonstrates argument reordering and pass-by-reference
	int n = 7;
	// (_1 and _2 are from std::placeholders, and represent future
	// arguments that will be passed to f1)

	// 绑定后函数被变形
	// 这么绑定n后面没有啥意义的 n 是常量 默认被省略了

	// _1, _2 是两个必要的参数 其他参数是默认的结构

	auto f1 = std::bind(f, _2, 42, _1, std::ref(n), n);
	n = 10;
	f1(1, 2, 1001); // 1 is bound by _1, 2 is bound by _2, 1001 is unused
					// makes a call to f(2, 42, 1, n, 7)
	f1(1, 2);
// 
	// nested bind subexpressions share the placeholders
	// 嵌套的结构子结构享有绑定参数
	// 嵌套结构中使用_3

	// g 的返回值 作为f 的第二个参数
	auto f2 = std::bind(f, _3, std::bind(g, _3), _3, 4, 5);
	f2(10, 11, 12); // makes a call to f(12, g(12), 12, 4, 5);

 	// common use case: binding a RNG with a distribution
 	std::default_random_engine e;
 	std::uniform_int_distribution<> d(0, 10);

	// 绑定并且使用的意思  这个里不需要传递参数 e 是默认的参数
 	auto rnd = std::bind(d, e); // a copy of e is stored in rnd
 	for (int n = 0; n < 10; ++n) 
 		std::cout << rnd() << ' '; // make a call d(e)
 	std::cout << '\n';

 	// bind to a pointer to member function
 	Foo foo;
	auto f3 = std::bind(&Foo::print_sum, &foo, 95, _1);  // 这里的foo作用是什么?前面不是已经绑定了一次方法吗???
	f3(5);
// 
	// bind to a pointer to data member
	auto f4 = std::bind(&Foo::data, _1);
	std::cout << f4(foo) << '\n';
// 
	// smart pointers can be used to call members of the referenced objects, too
	std::cout << f4(std::make_shared<Foo>(foo)) << '\n'
		<< f4(std::make_unique<Foo>(foo)) << '\n';



	return 0;
}