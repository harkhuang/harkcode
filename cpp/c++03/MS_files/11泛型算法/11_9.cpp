
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
	*�������д�������һ������,����ȥ��������ظ�    ���е�����ԭ�������Ҫ���㷨����������   �㷨��ֱ�Ӹı�������С
	*/
	
		
		
	// sort   ���������� �Ա���ȥ���ظ�����
	sort ( strVec.begin(), strVec.end() 
	// ���µ������ҷ���һ��������
	vector<string>::iterator end_unique = unique ( strVec.begin(), strVec.end() );
	// ɾ���ظ�
	strVec.erase( end_unique, strVec.end() );//����Ǹı�������С�ĺ���
	
	
	//�ú����ʺ����Ҫ��(��������˿��ӷ�ƨ   �Ѿ����� �����αȽ� ��ȫ�����ڵ���������  ����ָ����������)
	//������������
	stable_sort( strVec.begin(), strVec.end(), isShorter );
	
	//������������
	vector<string>::size_type wc = count_if ( strVec.begin(), strVec.end(), GT4 );
	cout << wc << "  " << make_plural ( wc, "word", "s" ) << " 4 letters or longer. " << endl;

	
	//һ���򵥵ı���
	cout << "\n\t Unique words: " << endl;
	for ( vector<string>::iterator it = strVec.begin();  it != strVec.end(); ++it )
		cout << *it << "  ";
	cout << endl;

	system("pause");
	return 0;
}