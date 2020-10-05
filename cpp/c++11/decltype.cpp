#include <iostream>

void test0(){
    int x = 42;

    // 获取x的类型 然后调用模版 进行构造
    std::vector<decltype(x)> v(100, x); // v is a vector<int>

    v.push_back(123);
    v.push_back(456);
}






void test1(){
    struct S {
        int x = 42;
    };
    const S s;

    // 获取s的类型然后进行定义
    decltype(s.x) y; // y has type int, even though s.x is const
}




// 获取  闭包函数类型(
int ytest()
{
    int i = 33;
    decltype(i) j = i * 2;

    std::cout << "i = " << i << ", "
        << "j = " << j << '\n';

    auto f = [](int a, int b) -> int
    {
        return a * b;
    };

    decltype(f) g = f; // the type of a lambda function is unique and unnamed
    i = f(2, 2);
    j = g(3, 3);

    std::cout << "i = " << i << ", "
        << "j = " << j << '\n';
}
struct A { double x; };
const A* a;
decltype(a->x) y;       // type of y is double (declared type)
<<<<<<< HEAD
/// 迷惑  为什么 是引用类型
decltype((a->x)) z = y; // type of z is const double& (lvalue expression)
=======


 
decltype((a->x)) z = y; // type of z is const double& (lvalue expression)


//泛型编程中类型延迟定义构建  为泛型编程提供了更多的灵活性
// 缺乏最佳实践?
// 下面的用例只能说是一个小实践

>>>>>>> 0a17bababab27d077fb222ed6cb050bd16904eaf
// 在模版中使用类型判断 是这个函数使用的精髓
// 延迟了返回类型的判断
template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) // return type depends on template parameters
                                      // return type can be deduced since C++14
{
    return t + u;
}



int  main()
{
    return 0;
}