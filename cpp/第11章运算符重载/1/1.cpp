#include <iostream>
using namespace std;
class num 
{
public:
	num(){n=1;}
	~num(){}
	int get()const{return n;}
	void set(int x){n=x;}
private:
	int n;
};
int main()
{
	num i;
	cout<<"i:"<<i.get()<<endl;
	i++;
	return 0;
}