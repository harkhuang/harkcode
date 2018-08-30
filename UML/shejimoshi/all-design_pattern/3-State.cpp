
#include <iostream>
using namespace std;

class Context; //前置声明
class State
{
public:
    State();
    virtual ~State();
    virtual void OperationInterface(Context* ) = 0;
    virtual void OperationChangeState(Context*) = 0;
protected:
    bool ChangeState(Context* con,State* st);
private:
    //bool ChangeState(Context* con,State* st);
};

class State;
/**
*
**/
class Context
{
public:
    Context();
    Context(State* state);
    ~Context();
    void OprationInterface();
    void OperationChangState();
protected:
private:
    friend class State; //表明在 State 类中可以访问 Context 类的 private 字段

    bool ChangeState(State* state);
private:
    State* _state;
};

class ConcreteStateA:public State
{
public:
    ConcreteStateA();
    virtual ~ConcreteStateA();
    virtual void OperationInterface(Context* );
    virtual void OperationChangeState(Context*);

protected:
private:
};
class ConcreteStateB:public State
{
public:
    ConcreteStateB();
    virtual ~ConcreteStateB();
    virtual void OperationInterface(Context* );
    virtual void OperationChangeState(Context*);
protected:
private:
};

State::State()
{
}
State::~State()
{
}
void State::OperationInterface
    (Context* con)
{
    cout<<"State::.."<<endl;
}
bool State::ChangeState(Context* con,State* st)
{
    con->ChangeState(st);
    return true;
}
void State::OperationChangeState(Context* con)
{
}
///
ConcreteStateA::ConcreteStateA()
{
}
ConcreteStateA::~ConcreteStateA()
{
}
void ConcreteStateA::OperationInterface
    (Context* con)
{
    cout<<"ConcreteStateA::OperationInterface        ......"<<endl;
}
void ConcreteStateA::OperationChangeState(Context* con)
{
    OperationInterface(con);
    this->ChangeState(con,new ConcreteStateB());
}
///
ConcreteStateB::ConcreteStateB()
{
}
ConcreteStateB::~ConcreteStateB()

{
}
void ConcreteStateB::OperationInterface
    (Context* con)
{
    cout<<"ConcreteStateB::OperationInterface......"<<endl;
}
void ConcreteStateB::OperationChangeState
    (Context* con)
{
    OperationInterface(con);
    this->ChangeState(con,new ConcreteStateA());
}

Context::Context()
{
}
Context::Context(State* state)
{
    this->_state = state;
}
Context::~Context()
{
    delete _state;
}
void Context::OprationInterface()
{
    _state->OperationInterface(this);
}
bool Context::ChangeState(State* state)
{
    ///_state->ChangeState(this,state);
    this->_state = state;
    return true;
}
void Context::OperationChangState()
{
    _state->OperationChangeState(this);

}


int main(int argc,char* argv[])
{
    State* st = new ConcreteStateA();
    Context* con = new Context(st);

    // AB 状态互切换 所以不需要参数传递
    con->OperationChangState();
    con->OperationChangState();
    con->OperationChangState();
    if (con != NULL)
        delete con;
    if (st != NULL)
        st = NULL;
    return 0;
}