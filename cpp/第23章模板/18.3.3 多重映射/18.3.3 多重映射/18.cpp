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
	phone.insert(CIT ("��Ȼ","0108225634"));
	phone.insert(CIT("��Ȼ","8708532"));
	phone.insert(CIT("��Ȼ","13583852314"));
	IT ii;
	cout<<"�������������Ԫ��...\n";
	show(ii,phone);
	cout<<"���ҹؼ���Ϊ����Ȼ�����������ݣ�\n";
	ii=phone.find("��Ȼ");
	typedef pair<IT, IT> PAIR;
	PAIR p=phone.equal_range("��Ȼ");
	for(IT i=p.first; i!=p.second; ++i)
	{
		cout<<i->first<<"\t"<<i->second<<endl;
	}
	system("pause");
	return 0;
}
