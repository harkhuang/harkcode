#include <iostream>   
#include <locale>   
using namespace  std;   
int main()   
{   
	cin.imbue(locale(""));   
	cout.imbue(locale("ALBANIAN"));   
	double M;   
	cin>>M;   
	cout<<M;   
	return 0;   
} 
