#include <iostream>
#include <string>
using namespace std;
class book 
{
public:
	int num;
	float price;
	book *next;
};
book*head=NULL;
bool check(string str)
{
	for(int i=0;i<str.length();i++)
	{
		if((str[i]>'9'||str[i]<'0')&&(str[i]!='.'))
			return false;
	}
	return true;
}
book*creat()
{
	book*p1,*p2;
	p1=new book;
	head=p1;
	p2=p1;
	cout<<"������ͼ��ı�ţ���0����"<<endl;
	string str;
	cin>>str;
	while(!check(str))
	{
		cout<<"����Ĳ������֣����������룬��0���أ�����"<<endl;
		cin>>str;
	}
    p1->num=atoi(str.c_str());
	
	if (p1->num!=0)
	{
		cout<<"������ͼ��ļ۸�"<<endl;
		cin>>str;
		while(!check(str))
		{
			cout<<"����Ĳ������֣����������룬��0���أ�����"<<endl;
			cin>>str;
		}
		p1->price=atof(str.c_str());
	}
	else
	{
		delete p1;p2=NULL;p2->next=NULL;head=NULL;return head;
	}
	while (p1->num!=0)
	{
		p2=p1;
		p1=new book;
		cout<<"������ͼ��ı�ţ���0����"<<endl;
		cin>>str;
		while(!check(str))
		{
			cout<<"����Ĳ������֣����������룬��0���أ�����"<<endl;
			cin>>str;
		}
		p1->num=atoi(str.c_str());
		if (p1->num!=0)
		{
			cout<<"������ͼ��ļ۸�"<<endl;
			cin>>str;
			while(!check(str))
			{
				cout<<"����Ĳ������֣����������룬��0���أ�����"<<endl;
				cin>>str;
			}
			p1->price=atof(str.c_str());
			
		}
		p2->next=p1;
	}
	delete p1;
	p2->next=NULL;
	return head;
}
void showbook(book*head)
{
	cout<<endl;
	cout<<"ͼ����Ϣ���£�"<<endl;
	while(head)
	{
		cout<<"ͼ���ţ�"<<head->num<<"\t";
		cout<<"�۸�"<<head->price<<endl;
		head=head->next;
	}
}
void Delete(book*head,int num)
{
	book*l;
	if (head->num==num)
	{
		l=head;
		head=head->next;
		::head=head;
		delete l;
		cout<<"�����ɹ�"<<endl;
		return;
	}
	while(head)
	{
		if (head->next==NULL)
		{
			cout<<"�Ҳ���Ҫɾ���ı�š�"<<endl;
			return;
		}
		if (head->next->num==num)
		{
			l=head->next;
			head->next=l->next;
			delete l;
			cout<<"�����ɹ�"<<endl;
			return;
		}
		head=head->next;
	}
	cout<<"�Ҳ���Ҫɾ���ı�š�"<<endl;
}
void insert(book*head,int num,float price)
{
	book*list=new book;
	list->num=num;
	list->price=price;
	list->next=head;
	::head=list;
}
int main()
{

	
	head=creat();
	showbook(head);
	cout<<"��������Ҫɾ����ͼ���ţ�";
	int BookNum;
	cin>>BookNum;
	Delete(head,BookNum);
	showbook(head);
	cout<<"��������Ҫ�����ͼ���ţ�";
	cin>>BookNum;
	cout<<"��������Ҫ�����ͼ��۸�";
	float BookPrice;
	cin>>BookPrice;
	insert(head,BookNum,BookPrice);
	showbook(head);
	return 0;
}