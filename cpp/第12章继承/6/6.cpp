#include <iostream>
using namespace std;
class father
{
public:
	int a,b;
};
class son:public father
{

};
int main()
{
	son a;
	a.a=1;
	a.b=2;
	cout<<a.a<<"\t"<<a.b<<endl;
	return 0;
}
����Ĺ��г�Ա������������Ȼ�ǹ��е�.