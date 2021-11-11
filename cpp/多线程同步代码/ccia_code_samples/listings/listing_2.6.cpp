#include <thread>
#include <utility>



// 自动回收的线程方法 
class scoped_thread
{
    std::thread t;
public:

    // 不允许隐式转换
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
    int& i;//初始化必须被传入

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
    // 可以自动回收的线程
    scoped_thread t(std::thread(func(some_local_state)));
        
    do_something_in_current_thread();
}

int main()
{
    f();
}
