/*
//��18.5.1  strncat������ʹ��

#include <iostream>
using namespace std;
int main()
{
	char ch1[10] = "ab";
	char ch2[]= "abcdef";
	strncat(ch1,ch2,3);
	cout <<ch1<<endl;
	return 0;
}
*/

//��18.5.2  string��append��Ա������ʹ��

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1 = "ab";
	string str2 = "abcdef";
	str1.append(str2,2,3);
	cout <<str1<<endl;
	return 0;
}
