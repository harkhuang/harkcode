#include <thread>
#include <iostream> 

struct func
{
  int& i;
  func(int& i_) : i(i_) {}
  void operator() ()
  {
    for (unsigned j=0 ; j<1000000 ; ++j)
    {
      do_something(i);           // 1 潜在访问隐患：空引用
    }
  }
};

void oops()
{
  int some_local_state=0;
  func my_func(some_local_state);
  std::thread my_thread(my_func);
  my_thread.join();          // 2 不等待线程结束
}                              // 3 新线程可能还在运行 




/*
如果不对资源进行管理的话  程序会异常中断 报如下错误.
terminate called without an active exception
[1]    76268 abort      ./a.out
*/

/*
编译程序如果没有引入pthread  也会报错   std::thread 
terminate called after throwing an instance of 'std::system_error'
  what():  Enable multithreading to use std::thread: Operation not permitted
[1]    76166 abort      ./a.out

*/


int main()
{

  std::thread mytrd(oops);
  return 0;
}