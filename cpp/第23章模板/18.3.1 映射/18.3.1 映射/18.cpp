#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef map<string,string>::const_iterator CIT;
typedef map<string,string>::value_type cit;
template<class T1,class T2>
void show(CIT &c,map<T1,T2>&n)
{
	for(c =n. begin(); c!= n.end(); ++c) 
	{ 
		cout<<c->first<<"\t"<<c->second<<endl; 
	} 

}
int main()
{
	string str="武汉";
	map<string,string>name,name1;
	name["范伟"]=str;
	name1["牛若军"]="青岛";
	name1.insert(name1.end(),cit("朱然","长春"));
	name.insert(name1.begin(),name1.end());
	cout<<"映射容器name中共有"<<name.size()<<"个元素\n";
	CIT cit;
	show(cit,name);
	cout<<"查找关键字为“朱然”的所有内容并输出\n";
	cit=name.find("朱然");
	if (cit==name.end())
	{
		cout<<"对不起，没有这个关键字。\n";
	}
	else
		cout<<cit->first<<"\t"<<cit->second<<endl;
	cout<<"关键字等于“范伟”的元素的个数为："<<name.count("范伟")<<endl;
	cout<<"删除关键字为“范伟”的所有元素。\n";
	name.erase("范伟");
	cout<<"再次输出映射容器name中的所有元素。\n";
	show(cit,name);
	cout<<"删除映射容器name中所有元素。\n";
	name.clear();
	if (name.empty())
	{
		cout<<"映射容器name为空\n";
	}
	else
		show(cit,name);
	system("pause");
	return 0;
}
