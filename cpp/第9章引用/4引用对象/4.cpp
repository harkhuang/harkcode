#include <iostream>
using namespace std;
class Human
{
public:
	int get(){return i;}
	void set(int x){i=x;}
private:
	int i;
};
int main()
{
	Human Mike;
	Human &rMike=Mike;
	rMike.set(123);
	cout<<rMike.get();
	//Human&rHuman=Human;
	int a;
	int &ra=a;
	return 0;
}