 /********************************************************************
 # File Name:    10_单词出现次数.cpp
 # Version:      1.0
 # Mail:         shiyanhk@gmail.com 
 # Created Time: 2015-08-07
 *********************************************************************/

#include <iostream>
#include <map>
#include <utility>
#include <string>

using namespace std;

int main()
{
	map <string , int> wordCount;
	string word;
	cout<< "Enter some words (Ctrl+D to end):"<<endl;
	while(cin>>word)
	//for(int k=0 ;k<5 ;k++)
	{

	//	cin>>word;
		pair <map <string ,int >::iterator,bool > ret = 
			wordCount.insert(make_pair(word,1));//这里的1表示第一次出现  如果有的话创建失败不改变value值
		if(!ret.second)//单词存在
		{
			++ret.first->second;//次数加1
		}
	}

	cout<<"word \t\t"<<"times"<<endl;
	for(map<string, int>::iterator iter = wordCount.begin();
		iter != wordCount.end();++iter)
	{
		cout << (*iter).first<<"\t\t"
			<<(*iter).second <<endl;
	}
	return 0;	
}

