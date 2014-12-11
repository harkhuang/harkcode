#include <iostream>
using namespace std;
enum{small,larger,same};//enum�ṩ����������,ֵ�ֱ�Ϊ0��1��2
class Date //����һ��������Date
{
public:
	Date(int i):date(i){}//��һ�������Ĺ��캯��
	~Date(){}      //��������
	int compare(const Date&);//�ȽϺ���
	void print(){cout<<date<<endl;}//������������date��ֵ
private:
	int date; //˽�г�Ա����date��
};
int Date::compare(const Date&two)//�ȽϺ����Ķ��岿�֣�����һ��Date��const����ı���
{
	if(date<two.date)//������øú��������ݳ�ԱdateС�ڴ��ݽ����Ķ�������ݳ�Ա
		return small;//����enum����small��
	if(date>two.date)//������øú��������ݳ�Աdate���ڴ��ݽ����Ķ�������ݳ�Ա
		return larger;//����larger
	else              //����
		return same;  //����same��Ҳ������ͬ
}

class Node //����ڵ���Node�������Ǹ�������,ֻ���ӿ�ʹ��
{
public:
	Node(){}     //����Ĭ�Ϲ��캯��
	virtual ~Node(){}   //��������������Ϊ�麯��
	virtual Node*insert(Date*one)=0;//����ָ�뷵��Node�����insert��������Ϊ���麯��
	virtual void print()=0; //�������������Ϊ���麯��
};
class InterNode:public Node //�м�ڵ���InterNode�ӽڵ���Node��������
{
public:
	InterNode(Date*one,Node*next);//���캯������������Ϊ������Date�ͽڵ���Node��ָ��
	~InterNode(){delete Next;delete thisdate;}//������������ɾ��Date���ָ���Աthisdate��		Node���ָ���ԱNext��
	virtual Node*insert(Date*one);  //����һ����ָ�뷽ʽ�����뷵�ص��麯��insert()
	virtual void print(){thisdate->print();Next->print();}//���ǻ���Node�Ĵ��麯��print������			Date���ָ��thisdate��Node���ָ��Next���ø��Ե��������print()���Date���Node		������ݡ�
private:      //�м�ڵ���InterNode��˽�г�Ա
    Date*thisdate; //ָ��������Date��ָ��thisdate
    Node*Next; //ָ�����Node��ָ��Next
};
InterNode::InterNode(Date*one,Node*next):thisdate(one),Next(next) {}//�м�ڵ���InterNode�Ĺ�	�캯���ô��ݸ�����Date������ʼ�����Լ���Date��ָ�룬����	���ݸ�����nextָ���ʼ	������Nextָ�룬���ڵ�һ����TailNodeβ����д��ݸ�����ָ����ָ��TailNode����(β��		��)��ָ�룬��˵�һ�γ�ʼ��ʱ����nextָ��ָ��TailNode����(β�ڵ�)��
Node*InterNode::insert(Date*one)		//��������麯��insert���ú�������һ��ָ��������Date								��ָ�롣
{
	int result=thisdate->compare(*one);//��InterNode���ָ���Աthisdate���ñȽϺ���			compare()�Ƚ���һ���뱾�β������ݵĴ�С��
//thisdate��ָ��Date���ָ�룬��˿��Ե���Date��ĳ�Ա����compare()��
// thisdateָ��ָ���ϴβ��뵽InterNode��Date����󣬴��ݽ�compare()�����е�*one��		���δ����������Date����󣬸ö���ĳ�Ա����date�����ű����û������롣
	switch(result)//���ȽϽ����ΪSwitch����ѡ������
	{
	case same:
	case larger: //�����ϴβ�������ݴ��ڻ��ߵ��ڱ��β���
		{
			InterNode*NodeDate=new InterNode(one,this);//�����ڶ����½�һ��InterNode��				����(�м�ڵ�)����ʼ������������Ա��
	//one������ʼ���ö����ָ���Աthisdate������thisdate��ָ�򱾴δ���������	��Date����󣬸ö���ĳ�Ա����date�����ű����û������롣
	//����ǰInterNode�����(��ǰ�м�ڵ�)��thisָ�븳���½�InterNode����(��		�м�ڵ�)��nextָ�����ʾ���м�ڵ��nextָ��ָ��ǰ�м�ڵ�
			return NodeDate;  //����ָ����ڶ��д�����InterNode�������м�ڵ㣩��					NodeDateָ�룬�÷���ֵ�᷵�ظ�ִ�е��øú�����HeadNode������insert()				��Ա������
		}
	case small: //�����ϴβ��������С�ڱ��β���
     Next=Next->insert(one); //��һ��ִ�и����ʱ�����Ѵ����ĵ�1���м�ڵ�InterNode
//��Nextָ��ָ��TailNode����(β�ڵ�)�������Nextָ��������insert�������Զ�
//����TailNode�����insert������TailNode�����insert�����ᴴ����2���м�ڵ㣬
//�ýڵ㱣�����µ�Date����ĵ�ַ�Լ�ָ��TailNode����(β�ڵ�)��Nextָ�룬
//TailNode�����insert���������˵�2���м�ڵ�ĵ�ַ���õ�ַ������ǰInterNode
//��Nextָ�룬Ҳ���ǵ�1���м�ڵ��Nextָ�롣��ʾ�����ϴ��û��������ݵĽ�
//�����һ���ڵ��Ǹմ������½ڵ㡣���½ڵ��Nextָ����ָ��β�ڵ㡣
//�ڶ���ִ�и�������ڴ�ʱ��Nextָ��ָ���ϴδ�����InterNode���󣬼���2����
//��ڵ㣬�����Nextָ��������InterNode���insert�����Ὣ�ϴδ�����InterNode
//�����е������뱾���û������������Ƚϣ������ϴαȱ������������С����ô��
//����һ�β���������һ���½ڵ㣬�������汾����������ݣ�Ȼ���½ڵ���õ���
//���ڵ�֮�󡣼����ϴαȱ�����������ݴ���ô�ظ�caseΪlargeʱ�Ĳ�������
//����һ���м�ڵ㣬�ýڵ�ָ���ϴδ������м�ڵ�(��2���м�ڵ�)�������ͽ���
//�ڵ�ŵ����ϸ��ڵ��ǰ�档�����ʵ���ǵ�Next->insert(one)���ý����󽫱��δ�
//�����м�ڵ�(��3���м�ڵ�)���ظ�Nextָ�룬���Nextָ���ǵ�1���м�ڵ�
//��Nextָ�룬���Nextָ��ԭ��ָ���2���м�ڵ㣬��������Ҫ��ָ���3����
//��ڵ㣬����3���м�ڵ���ָ���2���м�ڵ㣬���ǵĹ�ϵ�ǣ���1���м�ڵ�
//->��3���м�ڵ�->��2���м�ڵ㡣

		return this;//����ָ���һ��InterNode�����(��һ���м�ڵ�)��ָ��
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
Node*TailNode::insert(Date*one)		//����ָ��Date���ָ�룬�������Ǵ��ݸ��ú�������ָ									��Data������ָ�룬��������ܵ���Date�����
{
	InterNode*datanode=new InterNode(one,this);	//����һ��InterNode����(�м�ڵ�)����			Date����(�ö��󱣴����û����������)��TailNode����(β�ڵ�)���ݽ�ȥ��
	//�⽫����InterNode�����Ĺ��캯����ͬʱ����ָ��InterNode�����(�м�ڵ�)��ָ�룬		��ָ���ʼ����datanodeָ�롣
	return datanode;	//����ָ��InterNode�����(�м�ڵ�)��ָ��datanode��
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
	Next=new TailNode;//�ڶ��д���һ��TailNode�����(β�ڵ�),������HeadNodeͷ������						������ָ�����Node��Nextָ����ָ����
}
Node*HeadNode::insert(Date*one)
{
	Next=Next->insert(one); 
//��one������Date�����ĵ�ַ��Ҳ���ǽ�Date�����ĵ�ַ
//����ͷ�ڵ��У��ö���ĳ�Ա����date�������û������롣
//��һ�ε��øú���ʱ����Nextָ��ָ��TailNode�����(β�ڵ�),��insert()�������Ǹ��麯		�����������Զ�����TailNode���insert()������
//TailNode���insert()��������ָ��InterNode�����(�м�ڵ�)��ָ��datanode����ָ�븳��		HeadNode(ͷ�ڵ�)��Nextָ���HeadNode(ͷ�ڵ�)��Nextָ���ָ��InterNode�����		(�м�ڵ�)��
//�ڶ��ε��øú���ʱ����Nextָ���ʱ�Ѿ�ָ����InterNode�����(�м�ڵ�)��������			�Զ�����InterNode������insert()��������insert()��������ָ���´������м�ڵ��ָ
//��datanode����ָ�����ջ᷵�ص�HeadNode(ͷ�ڵ�)��insert�����У�Ȼ�󽻸������Next
//ָ�������棬����HeadNode(ͷ�ڵ�)��Nextָ���ָ���µ�InterNode�����(���м��
//��)���ٴε���ͷ�ڵ��insert����ִ�в��빤��ʱ�ͻ��������м�ڵ㿪ʼ��

	return this;		//����ָ��HeadNode�����(ͷ�ڵ�)��ָ��
}
class linkelist 		//�����ǩ��
{
public:
	linkelist();  //���������Ĭ�Ϲ��캯��
	~linkelist(){delete Head;} 	//�����������������ɾ����Աָ��Head����ָ��ָ��								HeadNode�ࡣ
	void insert(Date*one);         //���뺯������ָ��������Date��ָ��
	void printall(){Head->print();}	//������к�����ָ��HeadNode���ָ��������print()��								��������
private:
	HeadNode*Head;  //����һ��ָ��HeadNode���ָ��Head
};
linkelist::linkelist()  //linkelist��Ĭ�Ϲ��캯���Ķ���
{
	Head=new HeadNode; //Headָ��ָ��һ��HeadNode��Ķ���
}
void linkelist::insert(Date*pdate)//���뺯���Ķ��岿�֣��ú�������һ��ָ��������Date��ָ��
{
	Head->insert(pdate); 	//��ָ��HeadNode������Headָ�����insert()����������insert()						�����Ǹ��麯��������Զ�����HeadNode���insert()������
					//HeadNode���insert()�������غ�����linkedlist���insert()����							�����κβ�������˷���ֵ��������
}
int main()
{
	Date*pdate; //����һ��ָ��Date���ָ��
	int val;
	linkelist ll;	//����һ����ǩ�����ll�������ø����Ĭ�Ϲ��캯����ִ�еĽ�����ڶ���					������һ��HeadNode����󣬲��ɸ����ָ��Head��ָ������
	for (;;)  	//����ѭ��
	{
		cout<<"ʲôֵ��(0Ϊֹͣ):";
		cin>>val;   	//����һ����������val����
		if(!val)    	//����valΪ0���ñ��ʽ�൱��if(val==0)
			break;  	//�˳�ѭ��
		pdate=new Date(val); //�����ڶ��д���һ��Date������ɸ����ָ��pdate��ָ��			��������ö��������Date���һ�������Ĺ��캯�����û��������ֵ������ʼ��				�ö���ĳ�Ա����date��
		ll.insert(pdate);   	//���ñ�ǩ��linkelist�ĳ�Ա����insert���ú�������ͷ�ڵ�							   HeadNode�в���մ����Ķ���Ҳ����pdateָ���Date����
	}//��һ���Ǵ���Date���󣬵ڶ����ǽ�����뵽��ǩ�У�linkelist��ǩ�������������á�
	ll.printall();
	return 0;
}
