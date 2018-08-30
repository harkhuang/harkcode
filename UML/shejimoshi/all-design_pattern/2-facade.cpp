
#include <iostream>
using namespace std;
class AirConditioner
{
public:
    AirConditioner();
    ~AirConditioner();
    void Operation();
   
protected:
private:
};
class Light
{
public:
    Light();
    ~Light();
    void Operation();
protected:
private:
};
class Facade
{
public:
    Facade();
    ~Facade();
    void OperationWrapper();
protected:
   
private:
    AirConditioner* _subs1;
    Light* _subs2;
};


AirConditioner::AirConditioner()
{
}
AirConditioner::~AirConditioner()
{
}
void AirConditioner::Operation()
{
    cout<<"AirConditioner open.."<<endl;
}

Light::Light()
{
}
Light::~Light()
{
}
void Light::Operation()
{
    cout<<"Light open.."<<endl;
}
Facade::Facade()
{
    cout<<"Facade open "<<endl;
    this->_subs1 = new AirConditioner();
    this->_subs2 = new Light();
}
Facade::~Facade()
{
    delete _subs1;
    delete _subs2;
}

void Facade::OperationWrapper()
{
    this->_subs1->Operation();
    this->_subs2->Operation();
}

int main(int argc,char* argv[])
{
    Facade* f = new Facade();
    f->OperationWrapper();
    return 0;
}