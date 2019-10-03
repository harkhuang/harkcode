#include <iostream>

//不定参数模板
//non-template function,结束递归
template <typename T>
void print(const T & arg)
{
    std::cout<<__PRETTY_FUNCTION__<<arg <<std::endl;
}
template <typename T,typename ... Types>
void print(const T & arg1,const Types & ... args)
{
    std::cout<<__PRETTY_FUNCTION__<<arg1<<std::endl;
    print(args...);
}

 /*
void print(const T &, const Types &...) [T = int, Types = <int, int, double, char [6], double, int>]1
void print(const T &, const Types &...) [T = int, Types = <int, double, char [6], double, int>]2
void print(const T &, const Types &...) [T = int, Types = <double, char [6], double, int>]3
void print(const T &, const Types &...) [T = double, Types = <char [6], double, int>]4.55555
void print(const T &, const Types &...) [T = char [6], Types = <double, int>]aaaaa
void print(const T &, const Types &...) [T = double, Types = <int>]2.3333
void print(const T &) [T = int]6
 
 */

int test ()
{
    print(1,2,3,4.55555,"aaaaa",2.3333,6);
    return 0;
}

template <class... T>
void f(T... args)
{    
    std::cout << sizeof...(args) << std::endl; //打印变参的个数
}



int main()
{
    f();        //0
    f(1, 2);    //2
    f(1, 2.5, "");    //3
    return 0;
}