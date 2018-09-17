// #include <iostream>


// using namespace std;
// template <class Type> class Test { 
// public: 
//      void f() { 
//          cout << "My Type is: " << typeid(*this).name() << endl; 
//      } 
// }; 

// template<typename T>
// class A{
// 	public:
// 		virtual void beep(){ }
// 		//成员函数模板不能为虚函数 
// 		template<typename T2>
// 		virtual void print(){ }
// };
// int main()
// {
// 	system("pause");
// 	return 0;

// }

#include <iostream>
#include <string>

using namespace std;

template <typename T>


class A{
public:
    virtual void func1(const T& p)
    {
        cout<<"A:"<<p<<endl;
    }
};

template <typename T>
class B
: public A<T>
{
public:
    virtual void func1(const T& p)
    {
        cout<<"A<--B:"<<p<<endl;
    }
};



class X
{
public:

// 在类里面 构造虚函数模版  太难了  因为构造虚函数表is hard
    template <typename T>
    virtual void func2(const T& p)
    {
        cout<<"C:"<<p<<endl;
    }
};

int main(int argc, char** argv)
{
    A<string> a;
    B<int> b;
    B<string> c;

    A<string>* p = &a;
    p->func1("A<string> a");
    p = dynamic_cast<A<string>*>(&c);
    p->func1("B<string> c");
    B<int>* q = &b;
    q->func1(3);
	return 0;
}

