#include <iostream>
using namespace std;
int main(int argc,char**argv)
{
	cout<<"收到"<<argc<<"参数...\n";
	for(int i=0;i<argc;i++)
		cout<<"参数"<<i<<":"<<argv[i]<<endl;
	return 0;
}
