#include <iostream>
using namespace std;

//适配接口
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
        std::cout<<"Target::Request()"<<std::endl;
    };
protected:
private:
};

//适配器方法
class Adaptee
{
public:
    Adaptee(){
        cout<<"Adaptee()"<<endl;
    };
    ~Adaptee(){
        cout<<"~Adaptee()"<<endl;
    };
    void SpecificRequest(){
        std::cout<<"Adaptee::SpecificRequest()"<<std::endl;
    };
protected:
private:
};

//适配器
class Adapter:public Target
{
public:
    Adapter(Adaptee* ade){
        std::cout<<"Adapter(Adaptee* ade)"<<std::endl;
        this->_ade = ade;
    };
    ~Adapter(){
         std::cout<<"~Adapter()"<<std::endl;
    };
    void Request(){
        _ade->SpecificRequest();
    }
;
protected:
private:
    Adaptee* _ade;
};

int main(int argc,char* argv[])
{
    //用户根据类型名称自己适配
    Adaptee* ade = new Adaptee;
    Target* adt = new Adapter(ade);
    adt->Request();
    return 0;
}