#include <iostream>
using namespace std;

class Handle
{
public:
    virtual ~Handle(){
         delete _succ;
    };

    // �㷨����ʵ��������  ���������Ⱥ�˳���ٴζ���  �����ṩ��Դ��ȡ�Ľӿ�
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

    // ���캯�� �ı����Ȩ��
    Handle(Handle* succ){
        this->_succ = succ;
    };
private:
    //��ŵ��Ǻ�̽ڵ�ָ��   ��̽ڵ�������Լ����ص�����  ����dofilter
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
        cout<<"ConcreteHandleA �ҰѴ���Ȩ����̽ڵ�....."<<endl;
        this->GetSuccessor()->HandleRequest();
    }
    else    {
        cout<<"ConcreteHandleA û�к���ˣ� �ұ����Լ�����...."<<endl;
    }
}

ConcreteHandleB::ConcreteHandleB(Handle* succ):Handle(succ){
}

//�����㷨
void ConcreteHandleB::HandleRequest(){
    if (this->GetSuccessor() != 0)    {
        cout<<"ConcreteHandleB �ҰѴ���Ȩ����̽ڵ�....."<<endl;
        this->GetSuccessor()->HandleRequest();
    }
    else    {
        cout<<"ConcreteHandleB û�к���ˣ� �ұ����Լ�����...."<<endl;
    }
}

int main(int argc,char* argv[])
{
    Handle* h1 = new ConcreteHandleA();
    Handle* h2 = new ConcreteHandleB();
    // h1 �������  �ݽ���h2����
    h1->SetSuccessor(h2);
    h1->HandleRequest();
    return 0;
}