#include <iostream>
#include <list>
using namespace std;


int main() {
	// your code goes here
	int a [5]= {5,4,3,2,1};
	list <int >  lst1(a,a+5);
	list <int >::iterator iter1 = lst1.begin(),
						  iter2 = lst1.end();//����Ǳ�ʾ������λ��  ���������һ��Ԫ��!!!!!!!
						 // cout <<" lst1.end()";
						 // cout << *iter2;
	while(iter2!=iter1)
		cout <<endl  <<*(--iter2); //�����end -- �õ�������һ��Ԫ��
 
		
	return 0;
}