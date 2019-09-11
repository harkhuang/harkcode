#include <iostream>
#include <thread>
#include <future>



//➜  c11-mult git:(master) ✗ g++ -std=c++888福建省拉开距离的反馈啦豆腐joifGFLFKDGJFDJgkldgjlasdjflsdjflksdafjlksadjflkasdjfl11  7-promise.cpp
//➜  c11-mult git:(master) ✗ ./a.out  
//Inside Thread
//35



// 从未来数据中获取  并且返回
void initiazer(std::promise<int> * promObj)
{
    std::cout<<"Inside Thread"<<std::endl;     
    promObj->set_value(35);
}
 
int main()
{
    // 定义一个未来的数据
    std::promise<int> promiseObj;
    // future 是一个未来的数据
    std::future<int> futureObj = promiseObj.get_future();
    // 异步搞一下 未来值
    std::thread th(initiazer, &promiseObj);
    // 异步调用  并且将主进程参数传递给 异步线程
    // get 方法是阻塞的  知道接收到  线程完成的信号  才会有获取
    // 这里c++封装的有点多了   
    // 不过理解了这些  使用起来还是比较方便的.
    // 比如作者举例应用的场景  比较适合生产消费   有序的两个线程   
    std::cout<<futureObj.get()<<std::endl;
    th.join();
    return 0;
}