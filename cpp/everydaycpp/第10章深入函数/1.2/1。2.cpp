#include <iostream>
using namespace std;
class cube
{
public:
	void sum();
	void sum(int x,int y);
private:
	int i;
	int j;
};
int main()
{
	cube a;
	a.sum(2,3);
	a.sum();
	return 0;
}
void cube::sum()
{
	cout<<"i的立方："<<i*i*i<<"\t"<<"j的立方:"<<j*j*j<<endl;
}
void cube::sum(int x,int y)
{
	i=x;
	j=y;
	cout<<"i:"<<i<<"\t\t"<<"j:"<<j<<endl;
}