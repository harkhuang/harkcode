//��18.8  string��insert��Ա������ʹ��

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str="12789";
	string str1="3456";
	str.insert(2,str1,0,4);
	cout<<str;
	return 0;
}
