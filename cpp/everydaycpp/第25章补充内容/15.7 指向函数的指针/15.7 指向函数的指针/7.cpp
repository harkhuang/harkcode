#include <iostream>
using namespace std;
void show()
{
  cout<<"hello world\n";
}
int main()
{
	void(*p)();
	p=show;
	(*p)();
	return 0;
} 
