#include <iostream>
using namespace std;
class rectangle 
{
public:
	rectangle():length(3)
	{
		cout<<"����һ��������a!\n";
	}
	
private:
	const int length;
	
};
int main()
{
	rectangle a;
	
	return 0;
}