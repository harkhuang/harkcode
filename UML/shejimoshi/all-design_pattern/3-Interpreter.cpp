#include <iostream>
#include <string>
using namespace std;
class Context
{
public:
    Context();
    ~Context();
protected:
private:
};

Context::Context()
{
}
Context::~Context()
{
}


//抽象表达
class AbstractExpression
{
public:
    virtual ~AbstractExpression();
    //诠释
    virtual void Interpret(const Context& c);
protected:
    AbstractExpression();
private:
};

//控制台表达
class TerminalExpression:public AbstractExpression
{
public:
    TerminalExpression(const string& statement);
    ~ TerminalExpression();
     //诠释
    void Interpret(const Context& c);
protected:
private:
    string _statement;
};


//非控制台表达
class NonterminalExpression:public AbstractExpression
{
public:
    NonterminalExpression(AbstractExpression* expression,int times);
    ~ NonterminalExpression();
     //诠释
    void Interpret(const Context& c);
protected:
  
private:
    AbstractExpression* _expression;
    int _times;
};


AbstractExpression::AbstractExpression()
{
}
AbstractExpression::~AbstractExpression()
{
}
void AbstractExpression::Interpret(const Context& c)
{
}
TerminalExpression::TerminalExpression(const string& statement)
{
    this->_statement = statement;
}
TerminalExpression::~TerminalExpression()
{
}
void TerminalExpression::Interpret(const Context& c)
{
    cout<<this->_statement<<" TerminalExpression"<<endl;
}
NonterminalExpression::NonterminalExpression(AbstractExpression*
    expression,int times)

{
    this->_expression = expression;
    this->_times = times;
}
NonterminalExpression::~NonterminalExpression()
{
}
void NonterminalExpression::Interpret(const Context& c)
{
    for (int i = 0; i < _times ; i++)
    {
        this->_expression->Interpret(c);
    }
}

int main(int argc,char* argv[])
{
    Context* c = new Context();
    AbstractExpression* te = new TerminalExpression("hello");
    AbstractExpression* nte = new NonterminalExpression(te,2);
    nte->Interpret(*c);
    return 0;
}