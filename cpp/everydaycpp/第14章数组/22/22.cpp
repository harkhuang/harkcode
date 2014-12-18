#include <iostream>
using namespace std;
class get 
{
public:
	int a[5];
};
int main()
{
	get one[5];
    int i;
	for (i=0;i<5;i++)
	{
		cin>>one[i].a[i];
	
	}
	for (i=0;i<5;i++)
	{
		cout<<"one["<<i<<"]:";
		cout<<one[i].a[i]<<endl;
	}
	return 0;
}