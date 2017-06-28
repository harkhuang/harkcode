#include <iostream>
#include <string>
using namespace std;

// �������
class Beverage
{
public:
    Beverage()
    {
        m_description = string("Unknown Beverage");
        cout << "Beverage()" << endl;
    }

    virtual string getDescription()
    {
        cout << "Beverage::getDescription()" << endl;
        return m_description;
    }

    virtual double cost() = 0;

public:
    string m_description;
};

// ����װ����
class CondimentDecorator : public Beverage
{
public:
    virtual string getDescription() = 0;
};

// ���������Espresso
class Espresso : public Beverage
{
public:
    Espresso()
    {
        m_description = string("Espresso");
        cout << "Espresso()" << endl;
    }

    virtual double cost()
    {
        return 1.99;
    }
};

// ���������HouseBlend
class HouseBlend : public Beverage
{
public:
    HouseBlend()
    {
        m_description = string("HouseBlend");
    }

    virtual double cost()
    {
        return 0.89;
    }
};

// ���������DarkRoast
class DarkRoast : public Beverage
{
public:
    DarkRoast()
    {
        m_description = string("DarkRoast");
    }

    virtual double cost()
    {
        return 1.01;
    }
};

// ���������Decaf
class Decaf : public Beverage
{
public:
    Decaf()
    {
        m_description = string("Decaf");
    }

    virtual double cost()
    {
        return 0.57;
    }
};

// ����װ���ߣ�Mocha
class Mocha : public CondimentDecorator
{
public:
    Mocha(Beverage *p_beverage)
    {
        m_beverage = p_beverage;
        cout << "Mocha()" << endl;
    }

    virtual string getDescription()
    {
        return m_beverage->getDescription() + ", Mocha";
    }

    virtual double cost()
    {
        return 0.20 + m_beverage->cost();
    }
private:
    Beverage *m_beverage;
};

// ����װ���ߣ�Milk
class Milk : public CondimentDecorator
{
public:
    Milk(Beverage *p_beverage)
    {
        m_beverage = p_beverage;
        cout << "Milk()" << endl;
    }

    virtual string getDescription()
    {
        return m_beverage->getDescription() + ", Milk";
    }

    virtual double cost()
    {
        return 0.50 + m_beverage->cost();
    }
private:
    Beverage *m_beverage;
};

// ����װ���ߣ�Soy
class Soy : public CondimentDecorator
{
public:
    Soy(Beverage *p_beverage)
    {
        m_beverage = p_beverage;
        cout << "Soy()" << endl;
    }

    virtual string getDescription()
    {
        return m_beverage->getDescription() + ", Soy";
    }

    virtual double cost()
    {
        return 0.15 + m_beverage->cost();
    }
private:
    Beverage *m_beverage;
};

// ����װ���ߣ�Whip
class Whip : public CondimentDecorator
{
public:
    Whip(Beverage *p_beverage)
    {
        m_beverage = p_beverage;
        cout << "Whip()" << endl;
    }

    virtual string getDescription()
    {
        return m_beverage->getDescription() + ", Whip";
    }

    virtual double cost()
    {
        return 0.15 + m_beverage->cost();
    }
private:
    Beverage *m_beverage;
};


int main(void)
{
    Beverage *p_beverage = new Espresso;
    p_beverage = new Mocha(p_beverage);
    p_beverage = new Milk(p_beverage);
    p_beverage = new Soy(p_beverage);
    p_beverage = new Whip(p_beverage);
    p_beverage->getDescription();
    p_beverage->cost() ;
 //   cout << p_beverage->getDescription() << " " << p_beverage->cost() << 
endl;
    return 0;
}

