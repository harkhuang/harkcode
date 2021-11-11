#include <thread>
#include <iostream>
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
{

    std::cout << "in do_something_in_current_thread " <<std::endl;
}

void f()
{
    int some_local_state=0;
    func my_func(some_local_state);
    std::thread t(my_func);
    try
    {
        do_something_in_current_thread();
    }
    catch(...)
    {
        t.join();
        std::cout << "Something " <<std::endl;
        throw;
    }
    t.join();// error join在程序执行期间 只可以被调用一次
}

int main()
{
    f();
}
