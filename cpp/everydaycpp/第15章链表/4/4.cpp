#include <iostream>
using namespace std;
struct book 
{
	int num;
	float price;
	struct book*next;
};
void main()
{
	void*p=malloc(sizeof(book));
	free(p);
	book*p=new book;
	delete p;

}