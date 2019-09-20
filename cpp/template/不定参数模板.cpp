#include <iostream>

//不定参数模板
//non-template function,结束递归
template <typename T>
void print(const T & arg)
{
    qDebug()<<__PRETTY_FUNCTION__<<arg;
}
template <typename T,typename ... Types>
void print(const T & arg1,const Types & ... args)
{
    qDebug()<<__PRETTY_FUNCTION__<<arg1;
    print(args...);
}





int main ()
{
    print(1,2,3,4.55555,"aaaaa",2.3333,6);
    return 0;
}