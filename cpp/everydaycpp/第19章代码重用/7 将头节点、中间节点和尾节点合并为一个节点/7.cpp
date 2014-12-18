//19.7.11  重写的药品管理全部程序


//全部程序如下：

#include <iostream>
using namespace std;
class Date 
{
public:
	Date():date(1){}
	Date(int number):date(number){}
	virtual ~Date(){};
	int GetDate()const{return date;}
	virtual void print()const =0;
private:
	int date;
};
class Book:public Date
{
public:
	Book():Price(94){}
	Book(float Price,int number);
	virtual void print()const
	{
		cout<<"图书编号为:"<<Book::GetDate()<<endl;
		cout<<"图书价格为:"<<Price<<endl;
	}
private:
	float Price;
};
Book::Book(float price,int number):Price(price),Date(number){}
class medica:public Date
{
public :
	medica():Price(1){};
	medica(float Price,int number);
	virtual void print()const
	{
		cout<<"药品编号为:"<<medica::GetDate()<<endl;
		cout<<"药品价格为:"<<Price<<endl;
	}
private:
	float Price;
};
medica::medica(float price,int number):Price(price),Date(number){}
class Node
{
	public:
	Node(Date*);
	~Node();
	void setnext(Node*node){itsnext=node;}
	Node*getnext()const;
	Date*getDate()const;
	private:
	Date*itsDate;
	Node*itsnext;
};
Node::Node(Date*pDate):itsDate(pDate),itsnext(0){}
Node::~Node()
{
	delete itsDate;
	itsDate=0;
	delete itsnext;
	itsnext=0;
}
Node*Node::getnext()const
{
	return itsnext;
}
Date*Node::getDate()const
{
	if(itsDate)
		return itsDate;
	else
		return NULL;
}
class List
{
public:
	List();
	~List();
	Date*find(int number)const;
	int getcount()const{return count;}
	Date*getfirst()const;
	void insert(Date*);
	void repeat()const;
	Date*operator[](int)const;
private:
	Node*head;
	int count;
};
List::List():head(0),count(0){}
List::~List()
{
	delete head;
}
Date*List::getfirst()const
{
	if (head)
		return head->getDate();
	else
		return NULL;
}
Date*List::operator[](int offset)const
{
	Node*pn=head;
	if(!head)
		return NULL;
	if(offset>count)
		return NULL;
	for(int i=0;i<offset;i++)
		pn=pn->getnext();
	return pn->getDate();
}
Date*List::find(int number)const
{
	Node*pn=0;
	for(pn=head;pn!=NULL;pn=pn->getnext())
	{
		if(pn->getDate()->GetDate()==number)
			break;
	}
	if(pn==NULL)
		return NULL;
	else
		return pn->getDate();
}
void List::repeat()const
{
	if(!head)
		return;
	Node*pn=head;
	do 
	pn->getDate()->print();
	while(pn=pn->getnext());
}
void List::insert(Date*pDate)
{
	Node*pn=new Node(pDate);
	Node*pNow=head;
	Node*pNext=0;
	int New=pDate->GetDate();
	int next=0;
	count++;
	if(!head)
	{
		head=pn;
		return;
	}
	if(head->getDate()->GetDate()>New)
	{
		pn->setnext(head);
		head=pn;
		return;
	}
	for(;;)
	{
		if(!pNow->getnext())
		{
			pNow->setnext(pn);
			return;
		}
		pNext=pNow->getnext();
		next=pNext->getDate()->GetDate();
		if(next>New)
		{
			pNow->setnext(pn);
			pn->setnext(pNext);
			return;
		}
		pNow=pNext;
	}
}
int main()
{
	List pl;
	Date*pDate=0;
	int number;
	float value;
	int choice;
	while (1)
	{
		cout<<"(0)退出(1)图书(2)药品:";
		cin>>choice;
		if(!choice)
			break;
		cout<<"请输入编号:";
		cin>>number;
		if(choice==1)
		{
			cout<<"请输入图书价格:";
			cin>>value;
			pDate=new Book(value,number);
		}
		else
		{
			cout<<"请输入药品价格:";
			cin>>value;
			pDate=new medica(value,number);
		}
		pl.insert(pDate);
	}
		if(pl.getfirst()==0)
	{
		cout<<"程序结束\n";
	}
	else
	{
	pl.repeat();
	cout<<"请输入所要查找的编号："<<endl;
	cin>>number;
	if(pl.find(number)==0)
		cout<<"找不到该编号。\n";
	else
		pl.find(number)->print();
	}
	cout<<"该链表共有"<<pl.getcount()<<"节点\n";
    return 0;
}
