

#include <memory>
#include <iostream>
/**
 * output: 5
 *         5
 *         5
 *         7
 */
int test()
{
    int x = 5;

    // 将值拷贝进来
    auto copyLambda = [x]() { return x; };

    // 将值引用进来
    auto refLambda = [&x]() { return x; };
    std::cout << copyLambda() << std::endl;
    std::cout << refLambda() << std::endl;
    x = 7;
    std::cout << copyLambda() << std::endl;
    std::cout << refLambda() << std::endl;
}

void test1()
{
    int x, y;
    auto lam1 = [x, &y]() { return x * y; }; // OK
    //auto lam2 = [&x, x]() { return x * x; }; // Error: x captured twice
}

void test2()
{
    class Foo
    {
        int x;

    public:
        Foo() : x(10) {}

        void bar()
        {
            // Increment x every time we are called
            auto lam = [this]() { return ++x; };
            std::cout << lam() << std::endl;
        }
    };
    class Foo2{
        public: 
            Foo2():x(22){}
            void 
    }
    Foo foo;
    foo.bar(); // Outputs 11
    foo.bar(); // Outputs 12
}

void test3()
{
    int x = 10;
    int y = 14;
    auto lam1 = []() { return 24; };         // OK: capture nothing
    auto lam2 = [=]() { return x + y; };     // OK: copy x, copy y
    auto lam3 = [&]() { return x + y; };     // OK: reference x, reference y
    auto lam4 = [=, &x]() { return x + y; }; // OK: reference x, copy y
    auto lam5 = [&, x]() { return x + y; };  // OK: copy x, reference y
    // auto lam6 = [&x, = ]() { return x + y; };  // Error: default must be first
    // auto lam7 = [=, x]() { return x + y; };    // Error: both specify copy x
    // auto lam8 = [=, this]() { return x + y; }; // Error: both specify copy this
    // auto lam9 = [&, &x]() { return x + y; };   // Error: both specify reference x

    std::cout << lam1() << std::endl;
    std::cout << lam2() << std::endl;
    std::cout << lam3() << std::endl;
    std::cout << lam4() << std::endl;
    std::cout << lam5() << std::endl;
}
int main()
{
    test3();
}