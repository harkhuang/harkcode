
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

bool isShorter(  const string &s1, const string &s2 )
{
	return s1.size() < s2.size();
}

bool GT4( const string &s )
{
	return s.size() >= 4;
}

string make_plural( size_t i, const string &s1, const string &s2 )
{
	return ( i == 1 ) ? s1 : s1 + s2;
}

int main(int argc, char* argv[])
{
	cout << "\tInput some words ( ctrl + z to end):\n\t ";
	vector<string> strVec;
	string strVal;
	while ( cin >> strVal )
		strVec.push_back( strVal );

		
	/*
	*以下三行代码做了一件事情,就是去掉尼玛的重复    三行的真正原因是设计要输算法和容器分离   算法不直接改变容器大小
	*/
	
		
		
	// sort   对输入排序 以便于去除重复单词
	sort ( strVec.begin(), strVec.end() 
	// 重新迭代并且返回一个迭代器
	vector<string>::iterator end_unique = unique ( strVec.begin(), strVec.end() );
	// 删除重复
	strVec.erase( end_unique, strVec.end() );//这才是改变容器大小的函数
	
	
	//让函数适合你的要求(这里就脱了裤子放屁   已经排序 再来次比较 完全可以在第三个参数  函数指针做点文章)
	//根据条件排序
	stable_sort( strVec.begin(), strVec.end(), isShorter );
	
	//根据条件数数
	vector<string>::size_type wc = count_if ( strVec.begin(), strVec.end(), GT4 );
	cout << wc << "  " << make_plural ( wc, "word", "s" ) << " 4 letters or longer. " << endl;

	
	//一个简单的遍历
	cout << "\n\t Unique words: " << endl;
	for ( vector<string>::iterator it = strVec.begin();  it != strVec.end(); ++it )
		cout << *it << "  ";
	cout << endl;

	system("pause");
	return 0;
}