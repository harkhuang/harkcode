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
		delete p1;p2=NULL;head=NULL;return head;
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
	if (num<=head->num)
	{
		list->next=head;
	    ::head=list;
		return;
	}
	book*temp=NULL;
	while((num>head->num)&&(head->next!=NULL))
	{
		temp=head;
		head=head->next;
	}
	if (num>head->num)
	{
		head->next=list;
		list->next=NULL;
	}
	else
	{
		temp->next=list;
		list->next=head;
	}
}
int getBookNum(book*head)
{
	int num=0;
	while(head)
	{
		num++;
		head=head->next;
	}
	return num;
}
int main()
{
	
	string str;
begin:
	cout<<"1->重建图书2->显示图书3->插入图书4->删除图书5->图书数目Q->退出"<<endl;
	cin>>str;
	if (str[0]=='1')
	{
		::head=creat();
		system("cls");
		goto begin;
	}
	else if (str[0]=='2')
	{
		if (head==NULL)
		{
			cout<<"您的图书现在是空的，请增加图书"<<endl<<"按回车键返回主程序"<<endl;
			cin.get();
			cin.get();
			system("cls");
			goto begin;
		}
		showbook(head);
	}
	else if(str[0]=='3')
	{
		if (head==NULL)
		{
			cout<<"您的图书现在是空的，请增加图书"<<endl<<"按回车键返回主程序"<<endl;
			cin.get();
			cin.get();
			system("cls");
			goto begin;
		}
		cout<<"请输入要插入的图书编号，以0返回"<<endl;
		string str;
		float price;
		int num;
		cin>>str;
		
		while(!check(str))
		{
			cout<<"输入的不是数字，请重新输入，按0返回！！！"<<endl;
			cin>>str;
		}
		
	    num=atoi(str.c_str());
		
		if (num!=0)
		{
			cout<<"请输入图书的价格"<<endl;
			cin>>str;
			while(!check(str))
			{
				cout<<"输入的不是数字，请重新输入，按0返回！！！"<<endl;
				cin>>str;
			}
		    
			price=atof(str.c_str());
		}
		else
		{
			system("cls");
			goto begin;
		}
       insert(head,num,price);
	   cout<<"操作完毕，按回车键返回主程序"<<endl;
	}
	else if(str[0]=='4')
	{
		if (head==NULL)
		{
			cout<<"您的图书现在是空的，请增加图书"<<endl<<"按回车键返回主程序"<<endl;
			cin.get();
			cin.get();
			system("cls");
			goto begin;
		}
		cout<<"请输入要删除的图书编号，以0返回"<<endl;
		string str;
	
		int num;
		cin>>str;
		
		while(!check(str))
		{
			cout<<"输入的不是数字，请重新输入，按0返回！！！"<<endl;
			cin>>str;
		}
		
		num=atoi(str.c_str());
		
		
		Delete(head,num);
		cout<<"操作完毕，按回车键返回主程序"<<endl;
	}
    else if(str[0]=='5')
	{
		cout<<"图书数目是："<<getBookNum(head)<<endl<<"按回车键返回主程序"<<endl;
		cin.get();
		cin.get();
		system("cls");
		goto begin;
	}
	else
	{
		if (str[0]!='Q'&&str[0]!='q')
		{
			cout<<"请输入数字！按回车键返回继续操作";
		}
	}
	if (str[0]!='Q'&&str[0]!='q')
	{
		cin.get();
		cin.get();
		system("cls");
		goto begin;
	}
	return 0;
}