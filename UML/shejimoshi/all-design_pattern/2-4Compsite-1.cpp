#include <iostream>
#include <vector>
using namespace std;
class Component
{
public:
	Component();
	virtual ~Component();
public:
	virtual void Operation() = 0;
	virtual void Add(const Component& );
	virtual void Remove(const Component& );
	virtual Component* GetChild(int );
	
protected:
private:
};


Component::Component()
{
}
Component::~Component()
{
}
void Component::Add(const Component& com)
{
}
Component* Component::GetChild(int index)
{
	return 0;
}
void Component::Remove(const Component& com)
{
}


class Composite:public Component
{
public:
	Composite();
	~Composite();
public:
	void Operation();
	void Add(Component* com);
	void Remove(Component* com);
	Component* GetChild(int index);
protected:
private:
	vector<Component*> comVec;
};
 
Composite::Composite()
{
	vector<Component*>::iterator itend = comVec.begin();
}
Composite::~Composite()
{
}
void Composite::Operation()
{
	vector<Component*>::iterator comIter = comVec.begin();
	for (;comIter != comVec.end();comIter++)
	{
		(*comIter)->Operation();
	}
}
void Composite::Add(Component* com)
{
	comVec.push_back(com);
}
void Composite::Remove(Component* com)
{
	for (vector<Component *>::iterator it; it != comVec.end(); it++)
	{
		if (*it == com)
		{
			comVec.erase(it);
		}
	}
}
Component* Composite::GetChild(int index)
{
	return comVec[index];
}

class Leaf:public Component
{
public:
	Leaf();
	~Leaf();
	void Operation();
protected:
private:
};

Leaf::Leaf()
{
}
Leaf::~Leaf()
{
}
void Leaf::Operation()
{
	cout<<"Leaf operation....."<<endl;
}


int main(int argc,char* argv[])
{
	Leaf* l = new Leaf();
	l->Operation();
	Composite* com = new Composite();
	com->Add(l);
	com->Operation();
	Component* ll = com->GetChild(0);
	ll->Operation();
	return 0;
}
