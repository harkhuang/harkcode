#include <iostream>
using namespace std;

//������ģʽ: ����������Ʒ   �й˿ͺ�����Ա������з���  ���ҹ˿ͺ�����Ա������ʶ������ǲ�ͬ��  ��Ʒ����ϵ��˿��������Ա��





class ConcreteElementA;//������Ʒ����������������Ʒ
class ConcreteElementB;
class Element;  //���Ϊ���е���Ʒ

//VisitConcreteElementA   ���Ϊ�˿Ͷ���ƷElement�ķ���
//VisitConcreteElementB   ���Ϊ����Ա����ƷElement�ķ���
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



//�������ǿ�����Ʒ
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