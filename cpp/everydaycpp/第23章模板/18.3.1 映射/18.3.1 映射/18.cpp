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
	string str="�人";
	map<string,string>name,name1;
	name["��ΰ"]=str;
	name1["ţ����"]="�ൺ";
	name1.insert(name1.end(),cit("��Ȼ","����"));
	name.insert(name1.begin(),name1.end());
	cout<<"ӳ������name�й���"<<name.size()<<"��Ԫ��\n";
	CIT cit;
	show(cit,name);
	cout<<"���ҹؼ���Ϊ����Ȼ�����������ݲ����\n";
	cit=name.find("��Ȼ");
	if (cit==name.end())
	{
		cout<<"�Բ���û������ؼ��֡�\n";
	}
	else
		cout<<cit->first<<"\t"<<cit->second<<endl;
	cout<<"�ؼ��ֵ��ڡ���ΰ����Ԫ�صĸ���Ϊ��"<<name.count("��ΰ")<<endl;
	cout<<"ɾ���ؼ���Ϊ����ΰ��������Ԫ�ء�\n";
	name.erase("��ΰ");
	cout<<"�ٴ����ӳ������name�е�����Ԫ�ء�\n";
	show(cit,name);
	cout<<"ɾ��ӳ������name������Ԫ�ء�\n";
	name.clear();
	if (name.empty())
	{
		cout<<"ӳ������nameΪ��\n";
	}
	else
		show(cit,name);
	system("pause");
	return 0;
}
