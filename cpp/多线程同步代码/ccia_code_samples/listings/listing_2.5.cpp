#include <thread>
#include <functional>
void some_function()
{}

void some_other_function(int)
{}

std::thread f()
{
    //void some_function();
    return std::thread(some_function);
}
std::thread g()
{
    //void some_other_function(int);
    std::thread t(some_other_function,42);
    return t;
}

std::thread i()
{
    void f(int i,std::string const &s);
    std::thread t(f,3,"arg");

    // 函数方法是模板 必须声明参数类型
    std::function<void (int, std::string const &)> lambdf = [](int i, std::string const &s){};
    std::thread t1(lambdf,3,"arg");
}
void f(int i,std::string const &s){}

int main()
{
    std::thread t1=f();
    t1.join();
    std::thread t2=g();
    t2.join();
}
