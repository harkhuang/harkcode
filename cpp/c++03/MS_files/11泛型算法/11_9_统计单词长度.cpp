 /********************************************************************
 # File Name:    11_9_统计单词长度.cpp
 # Version:      1.0
 # Mail:         shiyanhk@gmail.com 
 # Created Time: 2015-08-11
 *********************************************************************/

#include <iostream>
#include <string>

#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>


using namespace std;

class T
{
public:
protected:
private:
};


bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

bool GT4(const string &s)
{
	return s.size() >= 4;
}

string make_plural( size_t i, const string &s1, const string &s2 )
{
	return ( i == 1 ) ? s1 : s1 + s2;
}


int main(int argc,char *argv[])
{
	if(argc<2)
	{
		cerr<< "no input file"<<endl;
	}

	ifstream inFile;
	inFile.open(argv[1]);
	if(!inFile)
	{
		cerr<<"cant open input file"<<endl;
		return EXIT_FAILURE;
	}

	vector <string > words;
	string word;
	while(inFile >>word);
	sort(word.begin(),word.end());
	vector<string>::iterator end_unique = unique ( words.begin(), words.end() );
	words.erase(unique(words.begin(),words.end(),words.end()));
	stable_sort(words.beign(),words.end(),isShorter);
	
	//计算得出小于4个字母的长度
	vector<string>::size_type wc = count_if(words.begin(),words.end(),GT4);

	for(vector<string>::iterator  iter = words.begin();iter!=words.end();++iter)
	{
		cout << *iter<<"";
		cout<<endl;
	}
		









	return 0;
}
