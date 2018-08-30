
#include <iostream>
using namespace std;
class Strategy
{
public:
    Strategy();
    virtual ~Strategy();
    virtual void AlgrithmInterface() = 0;
protected:
private:

};


class Strategy;
/**
*这个类是 Strategy 模式的关键，也是 Strategy 模式和 Template 模式的根本区别所在。
*Strategy 通过“组合”（委托） 方式实现算法（实现） 的异构，而 Template 模式则采取的是继承的方式
*这两个模式的区别也是继承和组合两种实现接口重用的方式的区别
*/

class Context
{
public:
    Context(Strategy* stg);
    ~Context();
    void DoAction();
protected:
private:
    Strategy* _stg;
};
class ConcreteStrategyA:public Strategy
{
public:
    ConcreteStrategyA();
    virtual ~ConcreteStrategyA();
    void AlgrithmInterface();
protected:
private:
};
class ConcreteStrategyB:public Strategy
{
public:
    ConcreteStrategyB();
    virtual ~ConcreteStrategyB();
    void AlgrithmInterface();
protected:
private:
};

#include <iostream>
using namespace std;
Strategy::Strategy()
{
}
Strategy::~Strategy()
{
    cout<<"~Strategy....."<<endl;

}
void Strategy::AlgrithmInterface()
{
}
ConcreteStrategyA::ConcreteStrategyA()
{
}
ConcreteStrategyA::~ConcreteStrategyA()
{
    cout<<"~ConcreteStrategyA....."<<endl;
}
void ConcreteStrategyA::AlgrithmInterface()
{
    cout<<"test ConcreteStrategyA....."<<endl;
}
ConcreteStrategyB::ConcreteStrategyB()
{
}
ConcreteStrategyB::~ConcreteStrategyB()
{
    cout<<"~ConcreteStrategyB....."<<endl;
}
void ConcreteStrategyB::AlgrithmInterface()
{
    cout<<"test ConcreteStrategyB....."<<endl;
}



Context::Context(Strategy* stg)
{
    _stg = stg;
}
Context::~Context()
{
    if (!_stg)
        delete _stg;
}
void Context::DoAction()
{
    _stg->AlgrithmInterface();

}
using namespace std;
int main(int argc,char* argv[])
{
    Strategy* ps = new ConcreteStrategyA();
    Context* pc = new Context(ps);
    pc->DoAction();
    if (NULL != pc)
        delete pc;
    return 0;
}