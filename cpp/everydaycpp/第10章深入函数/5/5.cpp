#include <iostream>
using namespace std;
class A 
{
public:
	A(int a, int b):num(a),total(b)
	{
		
	}
private:
	const int num;
	int &total;
};
int main()
{
	A a(3,4);
	return 0;
}