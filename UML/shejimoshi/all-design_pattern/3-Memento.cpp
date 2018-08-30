#include <string>
using namespace std;
class Memento;
#include <iostream>
using namespace std;
typedef string State;
//创作者类
class Originator
{
public:
    typedef string State;
    Originator();
    Originator(const State& sdt);
    ~Originator();

    Memento* CreateMemento();
    void SetMemento(Memento* men);
    void RestoreToMemento(Memento* mt);
    State GetState();
    void SetState(const State& sdt);
    void PrintState();
protected:
private:
    State _sdt;

    //预留备忘录接口  并且在备忘录模式中添加friend
    Memento* _mt;
};


class Memento
{
public:
protected:
private:
    //这是最关键的地方， 将 Originator 为 friend 类，可以访问内部信息，但是其他类不能访问
    friend class Originator;


    typedef string State;
    Memento();
    Memento(const State& sdt);
    ~Memento();
    void SetState(const State& sdt);
    State GetState();
private:
    State _sdt;
};


Originator::Originator()
{
    _sdt = "";
    _mt = 0;
}
Originator::Originator(const State& sdt)
{
    _sdt = sdt;
    _mt = 0;
}
Originator::~Originator()
{
}
Memento* Originator::CreateMemento()
{
    return new Memento(_sdt);
}
State Originator::GetState()
{
    return _sdt;
}
void Originator::SetState(const State& sdt)
{
    _sdt = sdt;
}
void Originator::PrintState()
{
    cout<<this->_sdt<<"....."<<endl;
}
void Originator::SetMemento(Memento* men)
{
}
void Originator::RestoreToMemento(Memento* mt)
{
    this->_sdt = mt->GetState();

}
//class Memento
Memento::Memento()
{
}
Memento::Memento(const State& sdt)
{
    _sdt = sdt;
}
State Memento::GetState()
{
    return _sdt;
}
void Memento::SetState(const State& sdt)
{
    _sdt = sdt;
}



int main(int argc,char* argv[])
{
    Originator* o = new Originator();
    o->SetState("old"); //备忘前状态
    o->PrintState();
    Memento* m = o->CreateMemento(); //将状态备忘
    o->SetState("new"); //修改状态
    o->PrintState();
    o->RestoreToMemento(m); //恢复修改前状态    因为之前在基类中有记录之前状态  所以 叫备忘录模式
    o->PrintState();
    return 0;

}