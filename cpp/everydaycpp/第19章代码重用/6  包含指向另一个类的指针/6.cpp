#include <iostream>
using namespace std;
enum{small,larger,same};//enum提供了三个常量,值分别为0、1、2
class Date //定义一个数据类Date
{
public:
	Date(int i):date(i){}//带一个参数的构造函数
	~Date(){}      //析构函数
	int compare(const Date&);//比较函数
	void print(){cout<<date<<endl;}//输出函数，输出date的值
private:
	int date; //私有成员变量date。
};
int Date::compare(const Date&two)//比较函数的定义部分，接受一个Date类const对象的别名
{
	if(date<two.date)//假如调用该函数的数据成员date小于传递进来的对象的数据成员
		return small;//返回enum变量small。
	if(date>two.date)//假如调用该函数的数据成员date大于传递进来的对象的数据成员
		return larger;//返回larger
	else              //其他
		return same;  //返回same，也就是相同
}

class Node //定义节点类Node，该类是个抽象类,只做接口使用
{
public:
	Node(){}     //声明默认构造函数
	virtual ~Node(){}   //将析构函数声明为虚函数
	virtual Node*insert(Date*one)=0;//将按指针返回Node对象的insert函数声明为纯虚函数
	virtual void print()=0; //将输出函数声明为纯虚函数
};
class InterNode:public Node //中间节点类InterNode从节点类Node派生而出
{
public:
	InterNode(Date*one,Node*next);//构造函数的两个参数为数据类Date和节点类Node的指针
	~InterNode(){delete Next;delete thisdate;}//在析构函数中删除Date类的指针成员thisdate和		Node类的指针成员Next。
	virtual Node*insert(Date*one);  //声明一个按指针方式传递与返回的虚函数insert()
	virtual void print(){thisdate->print();Next->print();}//覆盖基类Node的纯虚函数print，并用			Date类的指针thisdate和Node类的指针Next调用各自的输出函数print()输出Date类和Node		类的数据。
private:      //中间节点类InterNode的私有成员
    Date*thisdate; //指向数据类Date的指针thisdate
    Node*Next; //指向基类Node的指针Next
};
InterNode::InterNode(Date*one,Node*next):thisdate(one),Next(next) {}//中间节点类InterNode的构	造函数用传递给它的Date类对象初始化了自己的Date的指针，并用	传递给它的next指针初始	化它的Next指针，由于第一次在TailNode尾结点中传递给它的指针是指向TailNode对象(尾节		点)的指针，因此第一次初始化时它的next指针指向TailNode对象(尾节点)。
Node*InterNode::insert(Date*one)		//定义插入虚函数insert，该函数接受一个指向数据类Date								的指针。
{
	int result=thisdate->compare(*one);//用InterNode类的指针成员thisdate调用比较函数			compare()比较上一次与本次插入数据的大小。
//thisdate是指向Date类的指针，因此可以调用Date类的成员函数compare()。
// thisdate指针指向上次插入到InterNode的Date类对象，传递进compare()函数中的*one代		表本次待插入链表的Date类对象，该对象的成员变量date保存着本次用户的输入。
	switch(result)//将比较结果作为Switch语句的选择条件
	{
	case same:
	case larger: //假如上次插入的数据大于或者等于本次插入
		{
			InterNode*NodeDate=new InterNode(one,this);//继续在堆中新建一个InterNode类				对象(中间节点)并初始化它的两个成员。
	//one用来初始化该对象的指针成员thisdate，这样thisdate就指向本次待插入链表	的Date类对象，该对象的成员变量date保存着本次用户的输入。
	//将当前InterNode类对象(当前中间节点)的this指针赋给新建InterNode对象(新		中间节点)的next指针则表示新中间节点的next指针指向当前中间节点
			return NodeDate;  //返回指向刚在堆中创建的InterNode对象（新中间节点）的					NodeDate指针，该返回值会返回给执行调用该函数的HeadNode类对象的insert()				成员函数。
		}
	case small: //假如上次插入的数据小于本次插入
     Next=Next->insert(one); //第一次执行该语句时由于已创建的第1个中间节点InterNode
//的Next指针指向TailNode对象(尾节点)，因此用Next指针来调用insert函数会自动
//调用TailNode对象的insert函数，TailNode对象的insert函数会创建第2个中间节点，
//该节点保存了新的Date对象的地址以及指向TailNode对象(尾节点)的Next指针，
//TailNode对象的insert函数返回了第2个中间节点的地址，该地址赋给当前InterNode
//的Next指针，也就是第1个中间节点的Next指针。表示保存上次用户插入数据的节
//点的下一个节点是刚创建的新节点。而新节点的Next指针则指向尾节点。
//第二次执行该语句由于此时的Next指针指向上次创建的InterNode对象，即第2个中
//间节点，因此用Next指针来调用InterNode类的insert函数会将上次创建的InterNode
//对象中的数据与本次用户输入的数据相比较，假如上次比本次输入的数据小，那么重
//复第一次操作，开辟一个新节点，用来保存本次输入的数据，然后将新节点放置到上
//个节点之后。假如上次比本次输入的数据大，那么重复case为large时的操作，再
//创建一个中间节点，该节点指向上次创建的中间节点(第2个中间节点)。这样就将新
//节点放到了上个节点的前面。具体的实现是当Next->insert(one)调用结束后将本次创
//建的中间节点(第3个中间节点)返回给Next指针，这个Next指针是第1个中间节点
//的Next指针，这个Next指针原先指向第2个中间节点，现在我们要它指向第3个中
//间节点，而第3个中间节点则指向第2个中间节点，它们的关系是：第1个中间节点
//->第3个中间节点->第2个中间节点。

		return this;//返回指向第一个InterNode类对象(第一个中间节点)的指针
	}
	return this;
}
class TailNode:public Node
{
public:
	virtual Node*insert(Date*one);
	virtual void print(){}
private:
};
Node*TailNode::insert(Date*one)		//接受指向Date类的指针，由于我们传递给该函数的是指									向Data类对象的指针，因此它接受的是Date类对象
{
	InterNode*datanode=new InterNode(one,this);	//创建一个InterNode对象(中间节点)，将			Date对象(该对象保存了用户输入的数据)和TailNode对象(尾节点)传递进去，
	//这将调用InterNode类对象的构造函数，同时返回指向InterNode类对象(中间节点)的指针，		该指针初始化了datanode指针。
	return datanode;	//返回指向InterNode类对象(中间节点)的指针datanode。
}
class HeadNode :public Node
{
public:
	HeadNode();
	~HeadNode(){delete Next;}
	virtual Node*insert(Date*one);
	virtual void print(){Next->print();}
private:
	Node*Next;
};
HeadNode::HeadNode()
{
	Next=new TailNode;//在堆中创建一个TailNode类对象(尾节点),并由在HeadNode头节类中						创建的指向基类Node的Next指针来指向它
}
Node*HeadNode::insert(Date*one)
{
	Next=Next->insert(one); 
//用one来接收Date类对象的地址，也就是将Date类对象的地址
//插入头节点中，该对象的成员变量date保存了用户的输入。
//第一次调用该函数时由于Next指针指向TailNode类对象(尾节点),而insert()函数又是个虚函		数，因此这会自动调用TailNode类的insert()函数。
//TailNode类的insert()函数返回指向InterNode类对象(中间节点)的指针datanode，该指针赋给		HeadNode(头节点)的Next指针后，HeadNode(头节点)的Next指针就指向InterNode类对象		(中间节点)。
//第二次调用该函数时由于Next指针此时已经指向了InterNode类对象(中间节点)，因此这会			自动调用InterNode类对象的insert()函数，该insert()函数返回指向新创建的中间节点的指
//针datanode，该指针最终会返回到HeadNode(头节点)的insert函数中，然后交给该类的Next
//指针来保存，这样HeadNode(头节点)的Next指针就指向新的InterNode类对象(新中间节
//点)。再次调用头节点的insert函数执行插入工作时就会从这个新中间节点开始。

	return this;		//返回指向HeadNode类对象(头节点)的指针
}
class linkelist 		//定义标签类
{
public:
	linkelist();  //声明该类的默认构造函数
	~linkelist(){delete Head;} 	//该类的析构函数用于删除成员指针Head，该指针指向								HeadNode类。
	void insert(Date*one);         //插入函数接受指向数据类Date的指针
	void printall(){Head->print();}	//输出所有函数用指向HeadNode类的指针来调用print()输								出函数。
private:
	HeadNode*Head;  //声明一个指向HeadNode类的指针Head
};
linkelist::linkelist()  //linkelist类默认构造函数的定义
{
	Head=new HeadNode; //Head指针指向一个HeadNode类的对象
}
void linkelist::insert(Date*pdate)//插入函数的定义部分，该函数接受一个指向数据类Date的指针
{
	Head->insert(pdate); 	//用指向HeadNode类对象的Head指针调用insert()函数，由于insert()						函数是个虚函数，这会自动调用HeadNode类的insert()函数。
					//HeadNode类的insert()函数返回后，由于linkedlist类的insert()函数							并无任何操作，因此返回值被抛弃。
}
int main()
{
	Date*pdate; //定义一个指向Date类的指针
	int val;
	linkelist ll;	//创建一个标签类对象ll，这会调用该类的默认构造函数，执行的结果是在堆中					创建了一个HeadNode类对象，并由该类的指针Head来指向它。
	for (;;)  	//无穷循环
	{
		cout<<"什么值？(0为停止):";
		cin>>val;   	//输入一个整数并由val保存
		if(!val)    	//假如val为0，该表达式相当于if(val==0)
			break;  	//退出循环
		pdate=new Date(val); //否则在堆中创建一个Date类对象并由该类的指针pdate来指向			它。构造该对象调用了Date类带一个参数的构造函数，用户输入的数值用来初始化				该对象的成员变量date。
		ll.insert(pdate);   	//调用标签类linkelist的成员函数insert，该函数会向头节点							   HeadNode中插入刚创建的对象，也就是pdate指向的Date对象。
	}//第一步是创建Date对象，第二步是将其插入到标签中，linkelist标签类就起了这个作用。
	ll.printall();
	return 0;
}
