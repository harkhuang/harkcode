#include <thread>
#include <utility>
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <sstream>
class scoped_thread
{
    std::thread t;
public:
    explicit scoped_thread(std::thread t_):
        t(std::move(t_))
    {
        if(!t.joinable())
            throw std::logic_error("No thread");
    }
    ~scoped_thread()
    {
        t.join();
    }
    scoped_thread(scoped_thread const&)=delete;
    scoped_thread& operator=(scoped_thread const&)=delete;
};

void do_something(int& i)
{
    ++i;
}

struct func
{
    int& i;

    func(int& i_):i(i_){}

    void operator()()
    {
        for(unsigned j=0;j<1000000;++j)
        {
            do_something(i);
        }
    }
};

void do_something_in_current_thread()
{}

void f()
{
    int some_local_state;
    scoped_thread t(std::thread(func(some_local_state)));
        
    do_something_in_current_thread();
}
#include <functional>
double my_divide (double x, double y) {return x/y;}

void bind_test(){
    // 表示参数预留一个位置  后面自动补充是2
    auto fn_half = std::bind (my_divide,std::placeholders::_1,2);  
    std::cout << fn_half(10) << '\n'; 
}

// bind没有便利 ,如果使用auto后 使用几乎相同


void some_function(){};
void some_other_function(){};


void test_terminate()
{
    std::thread t1(some_function); 
    std::thread t2=std::move(t1); 
    t1=std::thread(some_other_function); 
    std::thread t3; 
    t3=std::move(t2); // Transferring ownership of a thread
    // t1=std::move(t3); // This assignment will terminate the program!
    
    t3.join();
    t1.join();
}



#include <string>


template<typename ...Element> class MyTuple
{
    //std::cout << Element << std::endl;
};

MyTuple<int,double,std::string> tup;



// template<typename Head, typename ...Tail>
// class tuple<Head, Tail...> : private tuple<Tail...> {};

//特化版本
// template<> class tuple<> {};


// 可以容纳n个参数的函数模板方法
void fngcs(){
    std::cout << "empty" << std::endl;
}

template <class ...Args> 
void fngcs(Args... args){
    std::cout << sizeof...(args) << std::endl;
    fngcs(args...);
};

#include <iostream>
#include <tuple>
using namespace std;

/************利用递归方式展开可变参数模板函数的参数包************/
//1.求最大值（可接受多个参数）

int maximum(int n)   //递归终止函数
{
    return n;
}

template<class... Args>
int maximum(int n, Args... args) //递归函数
{
    return std::max(n, maximum(args...)); 
}

/************mytest************/
void print1() {}
template<typename T, typename... Args> 
void print1(T firstArg,Args... args){
    std::cout << firstArg << std::endl;
    print1(args...);
}

//********************************
void print() {}

template <typename T, typename... Types> 
void print(T firstArg, Types... args) {
  std::cout << firstArg << '\n'; // print first argument
  print(args...);                // call print() for remaining arguments
}




// 递归退出方法
void testp(){}
                          // 定义参数展开的类型Args
template<typename T, typename... Args> 
void testp(T firstArg,Args... args){
    std::cout << firstArg << std::endl;
    //调用args 的方式是后面加 ...
    testp(args... );
}


int main()
{
    int a = 4;
    int b=  2; 
    int c = 3;
    // print1(a,b,c);
    testp(a,b,c);
    // std::cout << maximum(a,b,c) << std::endl;
}
