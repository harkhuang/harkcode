#include <iostream>
#include <thread>
#include <future>
std::promise<int> promiseObj;

//➜  c11-mult git:(master) ✗ g++ -std=c++11  7-promise.cpp
//➜  c11-mult git:(master) ✗ ./a.out  
//Inside Thread
//35

void initiazer(std::promise<int> * promObj)
{
    std::cout<<"Inside Thread"<<std::endl;     
    promObj->set_value(35);
}
 
int main()
{
    // future 是一个未来的数据
    std::future<int> futureObj = promiseObj.get_future();
    std::thread th(initiazer, &promiseObj);

    // 异步调用  并且将主进程参数传递给 异步线程
    std::cout<<futureObj.get()<<std::endl;
    th.join();
    return 0;
}