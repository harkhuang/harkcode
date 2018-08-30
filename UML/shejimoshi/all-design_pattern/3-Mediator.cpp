#include <string>
#include <iostream>
using namespace std;
class Mediator
{
public:
    virtual ~Mediator();
    virtual void DoActionFromAtoB() = 0;
    virtual void DoActionFromBtoA() = 0;
protected:
    Mediator();
private:
};
class Colleage
{
public:

    virtual ~Colleage();
    virtual void Aciton() = 0;
    virtual void SetState(const string& sdt) = 0;
    virtual string GetState() = 0;
protected:
    Colleage();
    Colleage(Mediator* mdt);
    Mediator* _mdt;
private:
};



class ConcreteColleageA:public Colleage
{
public:
    ConcreteColleageA();
    ConcreteColleageA(Mediator* mdt);
    ~ConcreteColleageA();
    void Aciton();
    void SetState(const string& sdt);
    string GetState();
protected:
private:
    string _sdt;
};
class ConcreteColleageB:public Colleage
{
public:
    ConcreteColleageB();

    ConcreteColleageB(Mediator* mdt);
    ~ConcreteColleageB();
    void Aciton();
    void SetState(const string& sdt);
    string GetState();
protected:
private:
    string _sdt;
};


Colleage::Colleage()
{
    //_sdt = " ";
}
Colleage::Colleage(Mediator* mdt)
{
    this->_mdt = mdt;
    //_sdt = " ";
}
Colleage::~Colleage()
{
}
ConcreteColleageA::ConcreteColleageA()

{
}
ConcreteColleageA::~ConcreteColleageA()
{
}
ConcreteColleageA::ConcreteColleageA(Mediator*    mdt):Colleage(mdt)
{
}
string ConcreteColleageA::GetState()
{
    return _sdt;
}
void ConcreteColleageA::SetState(const string& sdt)
{
    _sdt = sdt;
}
using namespace std;
void ConcreteColleageA::Aciton()
{
    _mdt->DoActionFromAtoB();
    cout<<"State of ConcreteColleageB:"<<"        "<<this->GetState()<<endl;
}
ConcreteColleageB::ConcreteColleageB()
{
}
ConcreteColleageB::~ConcreteColleageB()
{
}
ConcreteColleageB::ConcreteColleageB(Mediator*mdt):Colleage(mdt)

{
}
void ConcreteColleageB::Aciton()
{
    _mdt->DoActionFromBtoA();
    cout<<"State of ConcreteColleageB:"<<"        "<<this->GetState()<<endl;
}
string ConcreteColleageB::GetState()
{
    return _sdt;
}
void ConcreteColleageB::SetState(const string& sdt)
{
    _sdt = sdt;
}

class ConcreteMediator:public Mediator
{
public:
    ConcreteMediator();
    ConcreteMediator(Colleage* clgA,Colleage* clgB);
    ~ConcreteMediator();
    void SetConcreteColleageA(Colleage* clgA);
    void SetConcreteColleageB(Colleage* clgB);
    Colleage* GetConcreteColleageA();
    Colleage* GetConcreteColleageB();
    void IntroColleage(Colleage* clgA,Colleage* clgB);
    void DoActionFromAtoB();
    void DoActionFromBtoA();
protected:
private:
    Colleage* _clgA;
    Colleage* _clgB;
};

Mediator::Mediator()
{
}
Mediator::~Mediator()
{
}
ConcreteMediator::ConcreteMediator()
{
}
ConcreteMediator::~ConcreteMediator()
{
}
ConcreteMediator::ConcreteMediator(Colleage* clgA,Colleage* clgB)
{
    this->_clgA = clgA;
    this->_clgB = clgB;
}
void ConcreteMediator::DoActionFromAtoB()
{
    _clgB->SetState(_clgA->GetState());
}
void ConcreteMediator::SetConcreteColleageA(Colleage* clgA)
{
    this->_clgA = clgA;
}
void ConcreteMediator::SetConcreteColleageB(Colleage* clgB)
{
    this->_clgB = clgB;
}
Colleage* ConcreteMediator::GetConcreteColleageA()
{
    return _clgA;
}
Colleage* ConcreteMediator::GetConcreteColleageB()
{
    return _clgB;
}

void ConcreteMediator::IntroColleage(Colleage* clgA,Colleage* clgB)
{
    this->_clgA = clgA;
    this->_clgB = clgB;
}
void ConcreteMediator::DoActionFromBtoA()
{
    _clgA->SetState(_clgB->GetState());
}

int main(int argc,char* argv[])
{
    ConcreteMediator* m = new ConcreteMediator();
    ConcreteColleageA* c1 = new ConcreteColleageA(m);
    ConcreteColleageB* c2 = new ConcreteColleageB(m);
    m->IntroColleage(c1,c2);
    c1->SetState("old");
    c2->SetState("old");
    c1->Aciton();
    c2->Aciton();
    cout<<endl;
    c1->SetState("new");
    c1->Aciton();
    c2->Aciton();
    cout<<endl;
    c2->SetState("old");
    c2->Aciton();
    c1->Aciton();

    return 0;
}