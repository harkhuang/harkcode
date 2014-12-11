#include <iostream>
using namespace std;
class book 
{
public:
	int num;
	float price;
	 book*next;
};
void main()
{
	book x,y,z,*head,*p;
	x.num=10000;
	x.price=14.5f;
	y.num=20000;
	y.price=23.4f;
	z.num=30000;
	z.price=45.6f;
	head=&x;
	x.next=&y;
	y.next=&z;
	z.next=NULL;
	p=head;
	while (p!=NULL)
	{
		cout<<p->num<<endl<<p->price<<endl;
		p=p->next;
	}
	
}