/*
//Àý18.13.1  charÐÍ×Ö·û´®µÄ½»»»

#include <iostream>
using namespace std;
char ch1[15] = "ofru";
char ch2[15]="";
int main(void)
{
	swab(ch1, ch2, strlen(ch1));
	cout<<ch2<<endl;
	cout<<ch1<<endl;
	return 0;
}
*/

//Àý18.13.2   stringÐÍ×Ö·û´®µÄ½»»»

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str="give me";
	string str1="a cup";
	str.swap(str1);
	cout<<str<<endl;
	cout<<str1<<endl;
	return 0;
}
