#include <map>
#include <iostream>
#include <string>
using namespace std;
typedef multimap<string,string>::value_type CIT;
typedef multimap<string,string>::const_iterator IT;
template<class T1,class T2>
void show(IT&it,multimap<T1,T2>&r)
{
	for (it=r.begin();it!=r.end();++it)
	{
		cout<<it->first<<"\t"<<it->second<<"\n";
	}
}
int main()
{
	multimap<string,string>phone;
	phone.insert(CIT ("朱然","0108225634"));
	phone.insert(CIT("朱然","8708532"));
	phone.insert(CIT("朱然","13583852314"));
	IT ii;
	cout<<"遍历并输出所有元素...\n";
	show(ii,phone);
	cout<<"查找关键字为“朱然”的所有数据：\n";
	ii=phone.find("朱然");
	typedef pair<IT, IT> PAIR;
	PAIR p=phone.equal_range("朱然");
	for(IT i=p.first; i!=p.second; ++i)
	{
		cout<<i->first<<"\t"<<i->second<<endl;
	}
	system("pause");
	return 0;
}
