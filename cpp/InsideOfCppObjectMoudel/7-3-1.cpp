#include <iostream>
 
class V {
    public:
    // 虚函数
    virtual void f() {}  // must be polymorphic to use runtime-checked dynamic_cast
};

// 虚继承?
struct A : virtual V {};

struct B : virtual V {
  B(V* v, A* a) {
    // casts during construction (see the call in the constructor of D below)
    dynamic_cast<B*>(v); // well-defined: v of type V*, V base of B, results in B*
    dynamic_cast<B*>(a); // undefined behavior: a has type A*, A not a base of B
  }
};


// 在多重继承的情况下  需要虚继承以区分类之间的关联
struct D : A, B {
    D() : B(static_cast<A*>(this), this) { }
};
 

 
struct Base {
    virtual ~Base() {}
};
 
struct Derived: Base {
    virtual void name() {}
};
 
int main()
{
    D d; // the most derived object
    A& a = d; // upcast, dynamic_cast may be used, but unnecessary
    D& new_d = dynamic_cast<D&>(a); // downcast
    B& new_b = dynamic_cast<B&>(a); // sidecast
 
 
    Base* b1 = new Base;
    if(Derived* d = dynamic_cast<Derived*>(b1)) // 判断该指针是否含有子类指针
    {
        std::cout << "downcast from b1 to d successful\n";
        d->name(); // safe to call
    }
 
    
    Base* b2 = new Derived;

    // 此处模版赋值会不成功
    // 正确应用这个转型函数 非常有效
    // 通常情况是未能正确的加载子类项造成的.
    if(Derived* d = dynamic_cast<Derived*>(b2))
    {
        std::cout << "downcast from b2 to d successful\n";
        d->name(); // safe to call
    }
 
    Base* b2 = new Derived;
    if(Derived* d = dynamic_cast<Derived*>(d))
    {
        std::cout << "downcast from b2 to d successful\n";
        d->name(); // safe to call
    }
 



    delete b1;
    delete b2;
}