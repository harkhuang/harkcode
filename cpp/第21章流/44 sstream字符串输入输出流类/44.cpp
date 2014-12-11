/*
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
	ostringstream out;
	char*str="hello world";
	float num=314.57f;
	out.precision(2);
	out<<fixed;
	out<<num<<str<<endl;
	string ch=out.str();
	cout<<ch;
	return 0;
} 
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
	string str="Next morning I will stay at home.";
	istringstream in(str);
	char ch;
	while(in.get(ch))
		cout<<ch;
	return 0;
}
