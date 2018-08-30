#include <iostream>
using namespace std;

class Handle
{
public:
    virtual ~Handle(){
         delete _succ;
    };

    // 算法具体实现在子类  责任链的先后顺序再次定义  基类提供资源获取的接口
    virtual void HandleRequest() = 0;
    void SetSuccessor(Handle* succ){
        _succ = succ;
    };

    Handle* GetSuccessor(){
        return _succ;
    };
protected:
    Handle(){
         _succ = 0;       
    };

    // 构造函数 改变控制权限
    Handle(Handle* succ){
        this->_succ = succ;
    };
private:
    //存放的是后继节点指针   后继节点可以有自己独特的特性  会议dofilter
    Handle* _succ;
};

void Handle::HandleRequest(){
}

class ConcreteHandleA:public Handle
{
public:
    ConcreteHandleA(){
    };
    ~ConcreteHandleA(){
    };
    ConcreteHandleA(Handle* succ);
    void HandleRequest();
protected:
private:
};

class ConcreteHandleB:public Handle
{
public:
    ConcreteHandleB(){
    };
    ~ConcreteHandleB(){
    };
    ConcreteHandleB(Handle* succ);
    void HandleRequest();
protected:
private:
};

ConcreteHandleA::ConcreteHandleA(Handle* succ):Handle(succ){
}
 
void ConcreteHandleA::HandleRequest(){
    if (this->GetSuccessor() != 0)    {
        cout<<"ConcreteHandleA 我把处理权给后继节点....."<<endl;
        this->GetSuccessor()->HandleRequest();
    }
    else    {
        cout<<"ConcreteHandleA 没有后继了， 我必须自己处理...."<<endl;
    }
}

ConcreteHandleB::ConcreteHandleB(Handle* succ):Handle(succ){
}

//处理算法
void ConcreteHandleB::HandleRequest(){
    if (this->GetSuccessor() != 0)    {
        cout<<"ConcreteHandleB 我把处理权给后继节点....."<<endl;
        this->GetSuccessor()->HandleRequest();
    }
    else    {
        cout<<"ConcreteHandleB 没有后继了， 我必须自己处理...."<<endl;
    }
}

int main(int argc,char* argv[])
{
    Handle* h1 = new ConcreteHandleA();
    Handle* h2 = new ConcreteHandleB();
    // h1 处理完毕  递交给h2处理
    h1->SetSuccessor(h2);
    h1->HandleRequest();
    return 0;
}