#include <iostream>
using namespace std;

class Iterator;
typedef int Object;
class Interator;

class Aggregate
{
public:
    virtual ~Aggregate();
    virtual Iterator* CreateIterator() = 0;
    virtual Object GetItem(int idx) = 0;
    virtual int GetSize() = 0;
protected:
    Aggregate();
private:
};

class Aggregate;
typedef int Object;
class Iterator
{
public:
    virtual ~Iterator();
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
    virtual Object CurrentItem() = 0;
protected:
    Iterator();
private:
};

class ConcreteIterator:public Iterator
{
public:
    ConcreteIterator(Aggregate* ag , int idx = 0);

    ~ConcreteIterator();
    void First();

    void Next();
    bool IsDone();
    Object CurrentItem();
protected:
private:
    Aggregate* _ag;
    int _idx;
};

class ConcreteAggregate:public Aggregate
{
public:
    enum {SIZE = 3};
    ConcreteAggregate();
    ~ConcreteAggregate();
    Iterator* CreateIterator();
    Object GetItem(int idx);
    int GetSize();
protected:

private:
    Object _objs[SIZE];
};


Aggregate::Aggregate()
{
}
Aggregate::~Aggregate()
{
}
ConcreteAggregate::ConcreteAggregate()
{
    for (int i = 0; i < SIZE; i++)
        _objs[i] = i;
}
ConcreteAggregate::~ConcreteAggregate()
{
}
Iterator* ConcreteAggregate::CreateIterator()
{
    return new ConcreteIterator(this);
}
Object ConcreteAggregate::GetItem(int idx)
{
    if (idx < this->GetSize())
        return _objs[idx];
    else

        return -1;
}
int ConcreteAggregate::GetSize()
{
    return SIZE;
}


Iterator::Iterator()
{
}
Iterator::~Iterator()
{
}
ConcreteIterator::ConcreteIterator(Aggregate* ag , int idx)
{
    this->_ag = ag;
    this->_idx = idx;
}
ConcreteIterator::~ConcreteIterator()
{
}

Object ConcreteIterator::CurrentItem()
{
    return _ag->GetItem(_idx);
}
void ConcreteIterator::First()
{
    _idx = 0;
}
void ConcreteIterator::Next()
{
    if (_idx < _ag->GetSize())        
        _idx++;
}
bool ConcreteIterator::IsDone()
{
    return (_idx == _ag->GetSize());
}


int main(int argc,char* argv[])
{
    Aggregate* ag = new ConcreteAggregate();
    Iterator* it = new ConcreteIterator(ag);
    for (; !(it->IsDone()) ; it->Next())    {
        cout<<it->CurrentItem()<<endl;
    }
    return 0;
}