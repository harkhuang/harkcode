#include <iostream>
#include <list>
using namespace std;


int main() {
	// your code goes here
	int a [5]= {5,4,3,2,1};
	list <int >  lst1(a,a+5);
	list <int >::iterator iter1 = lst1.begin(),
						  iter2 = lst1.end();//这个是表示结束的位置  而不是最后一个元素!!!!!!!
						 // cout <<" lst1.end()";
						 // cout << *iter2;
	while(iter2!=iter1)
		cout <<endl  <<*(--iter2); //这里对end -- 得到倒数第一个元素
 
		
	return 0;
}