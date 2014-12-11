/*
#include <iostream>
using namespace std;
int main(void)
{
	char ch1[15] = "abcdefghijklmn";
	char ch2[] = "1234567890";
	cout<<"Ô´×Ö·û´®"<<ch1;
	memmove(ch1, ch2, 10);
	cout<<"¿½±´ºó:" <<ch1;
	return 0;
}
*/

//Àý18.7.2  stringÐÍ×Ö·û´®µÄ¿½±´

#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string str = "abcd";
	char ch []= "1234";
	int n;
	cout<<"Ô´×Ö·û´®"<<ch<<endl;
	n=str.copy(ch, 4,0);
	cout<<"¿½±´ÁË"<<n<<"×Ö·û"<<endl;
	cout<<"¿½±´ºó:" <<ch<<endl;
	return 0;
}

