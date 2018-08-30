#include <iostream>
using namespace std;
class Target
{
public:
    Target(){
        cout<<"Target()"<<endl;
    };
    virtual ~Target(){
        cout<<"~Target()"<<endl;
    };
    virtual void Request(){
        cout<<"Target::Request"<<endl;
    };
protected:
private:
};

class Adaptee
{
public:
    Adaptee(){
        cout<<"Adaptee()" <<endl;
    };
    ~Adaptee(){
        cout<<"~Adaptee()" <<endl;
    };
    void SpecificRequest(){
         cout<<"Adaptee::SpecificRequest()" <<endl;
    }
    ;
protected:
private:
};

//ͨ���̳еķ�ʽ����������
class Adapter:public Target,private Adaptee
{
public:

    Adapter(){
        cout<<"Adapter() "<<endl;
    };
    ~Adapter(){
        cout<<"~Adapter() "<<endl;
    };
    void Request(){
        cout<<"Adapter::Request()"<<endl;
        // �������������ͽ�������
        // TODO:���Ը���������Ĳ����������Թ�����ͬ��������
        // ������:1.ʶ������,2.ѡ���Ӧ������
        this->SpecificRequest();
    };
protected:
private:
};

int main(int argc,char* argv[])
{
    //Adapter* adt = new Adapter();
    //�������ͬʱ,������������,��ʱ������ֻ����ʹ�õķ���
    Target* adt = new Adapter();
    adt->Request();
    return 0;
}