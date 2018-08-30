
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
*������� Strategy ģʽ�Ĺؼ���Ҳ�� Strategy ģʽ�� Template ģʽ�ĸ����������ڡ�
*Strategy ͨ������ϡ���ί�У� ��ʽʵ���㷨��ʵ�֣� ���칹���� Template ģʽ���ȡ���Ǽ̳еķ�ʽ
*������ģʽ������Ҳ�Ǽ̳к��������ʵ�ֽӿ����õķ�ʽ������
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