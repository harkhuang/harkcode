#include<iostream>
using namespace std;
namespace people_company_boss
{
	int x=9;
}
namespace pcb=people_company_boss;
int main()
{
	cout<<pcb::x;
	cout<<people_company_boss::x<<endl;
	return 0;
}
