#include <iostream>
using namespace std;
class father
{
public:		
};

class son:virtual public father
{
public:
};
int main()
{
	father Tom;
	son&p=Tom;
	return 0;
}