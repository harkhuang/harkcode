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


//������
class AbstractExpression
{
public:
    virtual ~AbstractExpression();
    //ڹ��
    virtual void Interpret(const Context& c);
protected:
    AbstractExpression();
private:
};

//����̨���
class TerminalExpression:public AbstractExpression
{
public:
    TerminalExpression(const string& statement);
    ~ TerminalExpression();
     //ڹ��
    void Interpret(const Context& c);
protected:
private:
    string _statement;
};


//�ǿ���̨���
class NonterminalExpression:public AbstractExpression
{
public:
    NonterminalExpression(AbstractExpression* expression,int times);
    ~ NonterminalExpression();
     //ڹ��
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