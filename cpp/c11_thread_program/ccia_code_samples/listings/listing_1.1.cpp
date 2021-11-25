#include <iostream>
#include <thread>

void hello()
{
    std::cout<<"Hello Concurrent World\n";
}

int main()
{
    std::thread t(hello);

    // 线程创建无非也就是在另外一个线程空间中执行一个函数而已 提供生命周期和堆栈的管理
    std::thread t(hello);
    t.join();
}

