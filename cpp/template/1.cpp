/* *****
模板显示特化
**** */


// 将特殊的模版类  构造成其他类型

#include <iostream>

template <class T>
struct CTest{
    void operator()(){ std::cout<< "CTest<T>"<<std::endl;}
};

struct CTest<char > {
    void operator()(){ std::cout<< "CTest<char>"<<std::endl;}
};

struct CTest<int > {
    void operator()(){ std::cout<< "CTest<int>"<<std::endl;}
};


int main()
{
    CTest<double> test1;
    CTest<char> test2;
    CTest<int> test3;
    

    test1();
    test2();
    test3();

    return 0;
}