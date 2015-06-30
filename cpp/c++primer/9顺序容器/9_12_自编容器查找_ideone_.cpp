#include <iostream>
#include <vector>

using namespace std;


int func(vector <int>::iterator  beg,vector <int>::iterator  end, int bbb)
{
	while(beg!=end)
		if(*beg == bbb)//找到
		break;
		else
			++beg;
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
	vector <int>::iterator end = vec_a.end();
	int ret = func(beg,end,10);
	cout<<ret;
	return 0;
}