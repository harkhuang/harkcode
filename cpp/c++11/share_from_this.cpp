#include <iostream>
#include <memory>
struct A : public std::enable_shared_from_this<A>
{
    void foo()
    {
        shared_from_this()->baz();
    }

    void baz()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

struct B : public std::enable_shared_from_this<B>
{
    void bar()
    {
        shared_from_this()->baz();
    }

    void baz()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

struct D: A, B {};


int main()
{
 std::shared_ptr<D> d(new D);
 d->foo();
 d->bar();
 return 0;
}
