//例18.18	结构体的赋值

#include <iostream>
#include <string>
using namespace std;
struct people
{
	double weight;
	double tall;
};
int main()
{
	people Mike={185.2,178.1};
	people Jack={65.4,165.2};
	Mike=Jack;
	cout<<Mike.tall<<" "<<Mike.weight<<endl;
	cout<<Jack.tall<<" "<<Jack.weight<<endl;
	return 0;
}
