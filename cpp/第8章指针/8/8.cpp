#include <iostream>
using namespace std;
int main()
{
			int i=10;
			int j=20;
			int *p=&i;
			cout<<"i:"<<"\t"<<i<<endl;
			cout<<"&i"<<"\t"<<&i<<endl;
			cout<<"j:"<<"\t"<<j<<endl;
			cout<<"&j"<<"\t"<<&j<<endl;
			cout<<"p"<<"\t"<<p<<endl;
			cout<<"*p"<<"\t"<<*p<<endl;
			p=&j;
			cout<<"¸ü»»µØÖ·ºó\n";
	        cout<<"i:"<<"\t"<<i<<endl;
			cout<<"&i"<<"\t"<<&i<<endl;
			cout<<"j:"<<"\t"<<j<<endl;
			cout<<"&j"<<"\t"<<&j<<endl;
			cout<<"p"<<"\t"<<p<<endl;
			cout<<"*p"<<"\t"<<*p<<endl;
			return 0;
}