#include <iostream>
using namespace std;
int main(int argc,char**argv)
{
	cout<<"�յ�"<<argc<<"����...\n";
	for(int i=0;i<argc;i++)
		cout<<"����"<<i<<":"<<argv[i]<<endl;
	return 0;
}
