#include <iostream>
using namespace std;
class book 
{
public:
	int num;
	float price;
	book *next;
};
book*head=NULL;
book*creat()
{
  book*p1,*p2;
  p1=new book;
  head=p1;
  p2=p1;
  cout<<"������ͼ��ı�ţ���0����"<<endl;
  cin>>p1->num;
  if (p1->num!=0)
  {
	  cout<<"������ͼ��ļ۸�"<<endl;
	  cin>>p1->price;
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
	  cin>>p1->num;
	  if (p1->num!=0)
	  {
		  cout<<"������ͼ��ļ۸�"<<endl;
		  cin>>p1->price;
	  }
	  p2->next=p1;
  }
  delete p1;
  p2->next=NULL;
  return head;
}
int main()
{
	creat();
	return 0;
}

