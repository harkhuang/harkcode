
#include <iostream>
using namespace std;

class Reciever
{
public:
Reciever();
~Reciever();
void Action();
protected:
private:

};

//class Reciever;
class Command
{
public:
    virtual ~Command();
    virtual void Excute() = 0;
protected:
    Command();
private:

};
Reciever::Reciever()
{
}
Reciever::~Reciever()
{
}
void Reciever::Action()
{
std::cout<<"Reciever action......."<<std::endl;
}


class ConcreteCommand:public Command
{
public:
ConcreteCommand(Reciever* rev);
~ConcreteCommand();
void Excute();
protected:
private:
Reciever* _rev;
};


Command::Command()
{
}
Command::~Command()
{
}
void Command::Excute()
{
}
ConcreteCommand::ConcreteCommand(Reciever* rev)
{
this->_rev = rev;

}
ConcreteCommand::~ConcreteCommand()
{
delete this->_rev;
}
void ConcreteCommand::Excute()
{
_rev->Action();
std::cout<<"ConcreteCommand..."<<std::endl;
}

class Command;
class Invoker
{
public:
Invoker(Command* cmd);
~Invoker();
void Invoke();
protected:
private:
Command* _cmd;
};


Invoker::Invoker(Command* cmd)
{
_cmd = cmd;
}
Invoker::~Invoker()
{
delete _cmd;
}
void Invoker::Invoke()
{
_cmd->Excute();
}

int main(int argc,char* argv[])
{
    
    Reciever* rev = new Reciever();
    Command* cmd = new ConcreteCommand(rev);
    Invoker* inv = new Invoker(cmd);
    inv->Invoke();
    return 0;
}