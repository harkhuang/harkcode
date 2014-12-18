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
	cout<<"请输入图书的编号，以0结束"<<endl;
	string str;
	cin>>str;
	while(!check(str))
	{
		cout<<"输入的不是数字，请重新输入，按0返回！！！"<<endl;
		cin>>str;
	}
    p1->num=atoi(str.c_str());
	
	if (p1->num!=0)
	{
		cout<<"请输入图书的价格"<<endl;
		cin>>str;
		while(!check(str))
		{
			cout<<"输入的不是数字，请重新输入，按0返回！！！"<<endl;
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
		cout<<"请输入图书的编号，以0结束"<<endl;
		cin>>str;
		while(!check(str))
		{
			cout<<"输入的不是数字，请重新输入，按0返回！！！"<<endl;
			cin>>str;
		}
		p1->num=atoi(str.c_str());
		if (p1->num!=0)
		{
			cout<<"请输入图书的价格"<<endl;
			cin>>str;
			while(!check(str))
			{
				cout<<"输入的不是数字，请重新输入，按0返回！！！"<<endl;
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
	cout<<"图书信息如下："<<endl;
	while(head)
	{
		cout<<"图书编号："<<head->num<<"\t";
		cout<<"价格："<<head->price<<endl;
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
		cout<<"操作成功"<<endl;
		return;
	}
	while(head)
	{
		if (head->next==NULL)
		{
			cout<<"找不到要删除的编号。"<<endl;
			return;
		}
		if (head->next->num==num)
		{
			l=head->next;
			head->next=l->next;
			delete l;
			cout<<"操作成功"<<endl;
			return;
		}
		head=head->next;
	}
	cout<<"找不到要删除的编号。"<<endl;
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
	cout<<"请输入您要删除的图书编号：";
	int BookNum;
	cin>>BookNum;
	Delete(head,BookNum);
	showbook(head);
	cout<<"请输入您要插入的图书编号：";
	cin>>BookNum;
	cout<<"请输入您要插入的图书价格：";
	float BookPrice;
	cin>>BookPrice;
	insert(head,BookNum,BookPrice);
	showbook(head);
	return 0;
}