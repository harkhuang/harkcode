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
		delete p1;p2=NULL;head=NULL;return head;
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
	cout<<"1->�ؽ�ͼ��2->��ʾͼ��3->����ͼ��4->ɾ��ͼ��5->ͼ����ĿQ->�˳�"<<endl;
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
			cout<<"����ͼ�������ǿյģ�������ͼ��"<<endl<<"���س�������������"<<endl;
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
			cout<<"����ͼ�������ǿյģ�������ͼ��"<<endl<<"���س�������������"<<endl;
			cin.get();
			cin.get();
			system("cls");
			goto begin;
		}
		cout<<"������Ҫ�����ͼ���ţ���0����"<<endl;
		string str;
		float price;
		int num;
		cin>>str;
		
		while(!check(str))
		{
			cout<<"����Ĳ������֣����������룬��0���أ�����"<<endl;
			cin>>str;
		}
		
	    num=atoi(str.c_str());
		
		if (num!=0)
		{
			cout<<"������ͼ��ļ۸�"<<endl;
			cin>>str;
			while(!check(str))
			{
				cout<<"����Ĳ������֣����������룬��0���أ�����"<<endl;
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
	   cout<<"������ϣ����س�������������"<<endl;
	}
	else if(str[0]=='4')
	{
		if (head==NULL)
		{
			cout<<"����ͼ�������ǿյģ�������ͼ��"<<endl<<"���س�������������"<<endl;
			cin.get();
			cin.get();
			system("cls");
			goto begin;
		}
		cout<<"������Ҫɾ����ͼ���ţ���0����"<<endl;
		string str;
	
		int num;
		cin>>str;
		
		while(!check(str))
		{
			cout<<"����Ĳ������֣����������룬��0���أ�����"<<endl;
			cin>>str;
		}
		
		num=atoi(str.c_str());
		
		
		Delete(head,num);
		cout<<"������ϣ����س�������������"<<endl;
	}
    else if(str[0]=='5')
	{
		cout<<"ͼ����Ŀ�ǣ�"<<getBookNum(head)<<endl<<"���س�������������"<<endl;
		cin.get();
		cin.get();
		system("cls");
		goto begin;
	}
	else
	{
		if (str[0]!='Q'&&str[0]!='q')
		{
			cout<<"���������֣����س������ؼ�������";
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