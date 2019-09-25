#include <memory>
#include <iostream>
 
struct Foo {
    Foo(int n = 0) noexcept : bar(n) {
        std::cout << "Foo: constructor, bar = " << bar << '\n';
    }
    ~Foo() {
         std::cout << "Foo: destructor, bar = " << bar << '\n';
    }
    int getBar() const noexcept { return bar; }
private:
    int bar;
};
 

 
int main()
{
    std::shared_ptr<Foo> sptr = std::make_shared<Foo>(1);
    std::cout << "The first Foo's bar is " << sptr->getBar() << "\n";
 
    // 重置，与新的 Foo 实例 交换
     // （此调用后将销毁旧实例）  
    sptr.reset(new Foo);
    std::cout << "The second Foo's bar is " << sptr->getBar() << "\n";
}