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

//通过继承的方式绑定了适配器
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
        // 适配器调整类型进行适配
        // TODO:可以根据生成类的参数或者属性构建不同的适配器
        // 举例子:1.识别类型,2.选择对应适配器
        this->SpecificRequest();
    };
protected:
private:
};

int main(int argc,char* argv[])
{
    //Adapter* adt = new Adapter();
    //创建类的同时,构建了适配器,这时候我们只关心使用的方法
    Target* adt = new Adapter();
    adt->Request();
    return 0;
}