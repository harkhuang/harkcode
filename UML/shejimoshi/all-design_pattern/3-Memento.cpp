#include <string>
using namespace std;
class Memento;
#include <iostream>
using namespace std;
typedef string State;
//��������
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

    //Ԥ������¼�ӿ�  �����ڱ���¼ģʽ�����friend
    Memento* _mt;
};


class Memento
{
public:
protected:
private:
    //������ؼ��ĵط��� �� Originator Ϊ friend �࣬���Է����ڲ���Ϣ�����������಻�ܷ���
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
    o->SetState("old"); //����ǰ״̬
    o->PrintState();
    Memento* m = o->CreateMemento(); //��״̬����
    o->SetState("new"); //�޸�״̬
    o->PrintState();
    o->RestoreToMemento(m); //�ָ��޸�ǰ״̬    ��Ϊ֮ǰ�ڻ������м�¼֮ǰ״̬  ���� �б���¼ģʽ
    o->PrintState();
    return 0;

}