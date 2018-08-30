#include <iostream>
using namespace std;

//访问者模式: 举例超市商品   有顾客和收银员对其进行访问  而且顾客和收银员对其访问动作都是不同的  商品被组合到顾客类和收银员类





class ConcreteElementA;//根据商品属性派生出来的商品
class ConcreteElementB;
class Element;  //理解为超市的商品

//VisitConcreteElementA   理解为顾客对商品Element的访问
//VisitConcreteElementB   理解为收银员对商品Element的访问
class Visitor
{
public:
    virtual ~Visitor();
    virtual void VisitConcreteElementA(Element* elm) = 0;
    virtual void VisitConcreteElementB(Element* elm) = 0;
    
protected:
    Visitor();
private:
};



//这里我们看作商品
class ConcreteVisitorA:public Visitor
{
public:
    ConcreteVisitorA();
    virtual ~ConcreteVisitorA();
    virtual void VisitConcreteElementA(Element* elm);
    virtual void VisitConcreteElementB(Element* elm);
protected:
private:
};
class ConcreteVisitorB:public Visitor
{
public:
    ConcreteVisitorB();
    virtual ~ConcreteVisitorB();
    virtual void VisitConcreteElementA(Element* elm);
    virtual void VisitConcreteElementB(Element* elm);
protected:
   
private:
};

Visitor::Visitor()
{
}
Visitor::~Visitor()
{
}
ConcreteVisitorA::ConcreteVisitorA()
{
}
ConcreteVisitorA::~ConcreteVisitorA()
{
}


void ConcreteVisitorA::VisitConcreteElementA(Element* elm)
{
    cout<<"i will visit ConcreteElementA..."<<endl;
}
void ConcreteVisitorA::VisitConcreteElementB(Element* elm)
{
    cout<<"i will visit ConcreteElementB..."<<endl;
}
ConcreteVisitorB::ConcreteVisitorB()
{
}
ConcreteVisitorB::~ConcreteVisitorB()
{
}
void ConcreteVisitorB::VisitConcreteElementA(Element* elm)
{
    cout<<"i will visit ConcreteElementA..."<<endl;
}
void ConcreteVisitorB::VisitConcreteElementB(Element* elm)
{
   
    cout<<"i will visit ConcreteElementB..."<<endl;
}
 
class Visitor;
class Element
{
public:
    virtual ~Element();
    virtual void Accept(Visitor* vis) = 0;
protected:
    Element();
private:
};
class ConcreteElementA:public Element
{
public:
    ConcreteElementA();
    ~ConcreteElementA();
    void Accept(Visitor* vis);
   
protected:
private:
};
class ConcreteElementB:public Element
{
public:
    ConcreteElementB();
    ~ConcreteElementB();
    void Accept(Visitor* vis);
protected:
private:
};
 
 
Element::Element()
{
}
 
Element::~Element()
{
}
void Element::Accept(Visitor* vis)
{
}
ConcreteElementA::ConcreteElementA()
{
}
ConcreteElementA::~ConcreteElementA()
{
}
void ConcreteElementA::Accept(Visitor* vis)
{
    vis->VisitConcreteElementA(this);
    cout<<"visiting ConcreteElementA..."<<endl;
}
ConcreteElementB::ConcreteElementB()
{
}
 
ConcreteElementB::~ConcreteElementB()
{
}
void ConcreteElementB::Accept(Visitor* vis)
{
    cout<<"visiting ConcreteElementB..."<<endl;
    vis->VisitConcreteElementB(this);
}
 
 
int main(int argc,char* argv[])
{
    Visitor* vis = new ConcreteVisitorA();
    Element* elm = new ConcreteElementA();
    elm->Accept(vis);
    return 0;
}