#include <vector>
#include <thread>
#include <algorithm>
#include <functional>

void do_work(unsigned id)
{}


void f()
{
    std::vector<std::thread> threads;
    for(unsigned i=0;i<20;++i)
    {
        threads.push_back(std::thread(do_work,i));
    }
    std::for_each(threads.begin(),threads.end(),
        // 此处调用是用于回收线程资源.  如何绑定调用join的呢
        // 绑定调用函数成员  
        // 理解迭代器   理解绑定  通过迭代器 绑定调用方法.
        std::mem_fn(&std::thread::join));
      //  std::bind(&std::thread::join, _1)
}


int main()
{
    f();
}
