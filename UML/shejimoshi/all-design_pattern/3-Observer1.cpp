#include <list>
#include <string>
#include <iostream>
#include <list>
using namespace std;


typedef string State;

class Observer;

class Subject
{
public:
    virtual ~Subject();
    virtual void Attach(Observer* obv);
    virtual void Detach(Observer* obv);
    virtual void Notify();
    virtual void SetState(const State& st) = 0;
    virtual State GetState() = 0;
protected:
    Subject();
private:
    list<Observer* >* _obvs;
};


class Observer
{
public:
    virtual ~Observer();
    virtual void Update(Subject* sub) = 0;
    virtual void PrintInfo() = 0;
protected:
    Observer();
    State _st;
private:
};
class ConcreteObserverA:public Observer
{
public:
    virtual Subject* GetSubject();
    ConcreteObserverA(Subject* sub);
    virtual ~ConcreteObserverA();
    //传入 Subject 作为参数，这样可以让一个 View 属于多个的 Subject。
    void Update(Subject* sub);
    void PrintInfo();
protected:
private:
    Subject* _sub;
};
class ConcreteObserverB:public Observer
{
public:
    virtual Subject* GetSubject();
    ConcreteObserverB(Subject* sub);

    virtual ~ConcreteObserverB();
    //传入 Subject 作为参数，这样可以让一个 View 属于多个的 Subject。
    void Update(Subject* sub);
    void PrintInfo();
protected:
private:
    Subject* _sub;
};

Observer::Observer()
{
    _st = '\0';
}
Observer::~Observer()
{
}
ConcreteObserverA::ConcreteObserverA(Subject* sub)
{
    _sub = sub;
    _sub->Attach(this);
}
ConcreteObserverA::~ConcreteObserverA()
{

    _sub->Detach(this);
    if (_sub != 0)
    {
        delete _sub;
    }
}
Subject* ConcreteObserverA::GetSubject()
{
    return _sub;
}
void ConcreteObserverA::PrintInfo()
{
    cout<<"ConcreteObserverA observer...."<<_sub->GetState()<<endl;
}
void ConcreteObserverA::Update(Subject* sub)
{
    _st = sub->GetState();
    PrintInfo();
}
ConcreteObserverB::ConcreteObserverB(Subject* sub)
{
    _sub = sub;
    _sub->Attach(this);
}
ConcreteObserverB::~ConcreteObserverB()
{
    _sub->Detach(this);
    if (_sub != 0)
    {
        delete _sub;
    }
}
Subject* ConcreteObserverB::GetSubject()
{

    return _sub;
}
void ConcreteObserverB::PrintInfo()
{
    cout<<"ConcreteObserverB observer....     "<<_sub->GetState()<<endl;
}
void ConcreteObserverB::Update(Subject* sub)
{
    _st = sub->GetState();
    PrintInfo();
}


class ConcreteSubject:public Subject
{
public:
    ConcreteSubject();
    ~ConcreteSubject();
    State GetState();
    void SetState(const State& st);
protected:
  
private:
    State _st;
};


Subject::Subject()
{
    //****在模板的使用之前一定要 new，创建
    _obvs = new list<Observer*>;
}
Subject::~Subject()
{
}
void Subject::Attach(Observer* obv)
{
    _obvs->push_front(obv);
}
void Subject::Detach(Observer* obv)
{
    if (obv != NULL)
        _obvs->remove(obv);
}

void Subject::Notify()
{

    list<Observer*>::iterator it;
    it = _obvs->begin();
   for (;it != _obvs->end();it++)
    {
        //关于模板和 iterator 的用法
       (*it)->Update(this);
      
    }
}
ConcreteSubject::ConcreteSubject()
{
    _st = '\0';
}
ConcreteSubject::~ConcreteSubject()
{
}
State ConcreteSubject::GetState()
{
    return _st;
}
void ConcreteSubject::SetState(const State& st)
{
    _st = st;
}

int main(int argc,char* argv[])
{

    // 观察的数据  这里只是一个string字符串  也可以是一个复杂的结构体
    ConcreteSubject* sub = new ConcreteSubject();

    // 构造
    Observer* o1 = new ConcreteObserverA(sub);
    Observer* o2 = new ConcreteObserverB(sub);
    sub->SetState("old");
    sub->Notify();
    sub->SetState("new"); //也可以由 Observer 调用
    sub->Notify();
    return 0;
}