#pragma warning(disable : 4786) 
#include <iostream> 
#include <string> 
#include <vector> 
using namespace std; 
void main() 
{ 
	const string str1 = "Please write down the numbers 1--10 in English:"; 
	const string str2 = "one, two, three,four,five,six,seven"; 
	const string str3 = "and eight,nine,ten"; 
	const string sentence = str1 + ' ' + str2 + ' ' + str3; 
	const char *p = sentence.data(); 
	vector< string > vect, vMin, vMax; 
	string str = ""; 
	unsigned int i; 
	
	for(i = 0; i <= strlen(p); i++) 
	{ 
		if(isalpha(p[i])) 
		{ 
			str += p[i]; 
		} 
		else if(!str.empty()) 
		{ 
			vect.push_back(str); 
			str = ""; 
		} 
	} 
	
	if(!vect.size()) 
	{ 
		cout<<"�Ҳ�������!"<<endl; 
		return; 
	} 
	
	vMin.push_back(vect[0]); 
	vMax.push_back(vect[0]); 
	
	for(i = 1; i < vect.size(); i++) 
	{ 
		if(vMin[0].length() > vect[i].length()) 
		{ 
			vMin.clear(); 
			vMin.push_back(vect[i]); 
		} 
		else if(vMin[0].length() == vect[i].length()) 
		{ 
			vMin.push_back(vect[i]); 
		} 
		
		if(vMax[0].length() < vect[i].length()) 
		{ 
			vMax.clear(); 
			vMax.push_back(vect[i]); 
		} 
		else if(vMax[0].length() == vect[i].length()) 
		{ 
			vMax.push_back(vect[i]); 
		} 
	} 
	
	cout<<"ԭ�ַ���:"<<endl<<p<<endl<<endl; 
	cout<<"���ҵ�����" 
		<<vect.size()<<"��,�ֱ���:"<<endl; 
	for(i = 0; i < vect.size(); i++) 
		cout<<vect[i]<<endl; 
	
	cout<<endl<<endl<<"�ҵ�����̵ĵ��ʹ���" 
		<<vMin.size()<<"��,�ֱ���:"<<endl; 
	for(i = 0; i < vMin.size(); i++) 
		cout<<vMin[i]<<endl; 
	
	cout<<endl<<endl<<"�ҵ�����ĵ��ʹ���" 
		<<vMax.size()<<"��,�ֱ���:"<<endl; 
	for(i = 0; i < vMax.size(); i++) 
		cout<<vMax[i]<<endl; 
}
