#include <iostream>


using namespace std;

template<typename T> 
T Max(T t1,T t2)
{
    return (t1>t2)?t1:t2;
}

// 对char * 类型进行特化（特化就是特殊化处理）
typedef const char* CCP;
template<> 
CCP Max<CCP>(CCP s1,CCP s2)
{
    return (strcmp(s1,s2)>0)?s1:s2;
}

int main(){
//调用实例：int Max<int>(int,int)
    int i=Max(10,5);
    //调用显示特化：const char* Max<const char*>(const char*,const char*)
    const char* p=Max<const char*>("very","good");
    cout<<"i:"<<i<<endl;
    cout<<"p:"<<p<<endl;
}