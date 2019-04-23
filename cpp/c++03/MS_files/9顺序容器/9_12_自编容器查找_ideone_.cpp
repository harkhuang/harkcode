#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
/*
 *1.容器使用
 *2.一级指针参数传入的仅仅是一个拷贝的副本
 *3
*/
int func(vector <int>::iterator  beg,vector <int>::iterator  end, int bbb)
{
	printf("in the fun before ");
	cout<<*beg<<endl;
	while(beg!=end)
		if(*beg == bbb)//找到
		break;
		else
			++beg;
	
	printf("in the fun after ");
	cout<<*beg<<endl;
	if(beg != end)
		return true;//找到 1
	else 
		return false;//没找到 0
}

int main() {
	// your code goes here
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	vector <int> vec_a(a,a+10);
	vector <int>::iterator beg = vec_a.begin();
	printf("befor the beg is  ");
	cout<<*beg<<endl;
	
	vector <int>::iterator end = vec_a.end();
	int ret = func(beg,end,5);
	printf("after the beg is  ");  //在函数里面修改的话  没有能够达到修改值的目的
	cout<<*beg<<endl;
	//cout<<ret;
	return 0;
}