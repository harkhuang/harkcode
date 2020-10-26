
// file: 1functor.cpp 
#include <iostream> 
using namespace std;


// 由于将 operator() 多载化了，因此 plus 成了㆒个仿函式
template <class T>
struct plus1 {
    T operator()(const T& x, const T& y) const { return x + y; }
};
// 由于将 operator() 多载化了，因此 minus 成了㆒个仿函式
template <class T>
struct minus1 {
    T operator()(const T& x, const T& y) const { return x - y; }
};



void test1()
{
//     plus<int> plusobj;
//     plusobj(30, 50);
// 
//     // 匿名仿函数调用
    plus1<int>()(30, 60);
    minus1<int>()(30,60);
// 

}