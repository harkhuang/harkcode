#include <iostream>
#include <bitset>
using namespace std;
int main()
{
bitset<8>bs( (float) 131 );
//for(int i=(int) bs.size()-1;i>=0;i--) {
//cout << bs[i] << " ";
//}
cout<<bs;
cout << endl;
bs<<=4;
cout<<bs<<endl;
//cout<<~bs<<endl;
cout<<"���ú���flip����"<<bs.flip()<<endl;
bitset<8>bs1( (long) 0 );
if(bs1.none())
{
	cout<<"0�Ķ�����λ��Ϊ0��\n";
}
else
	cout<<"0�Ķ�����λ��ȫΪ0��\n";

if(!bs1.any())
{
	cout<<"0�Ķ�����λ��Ϊ0��\n";
}
else
	cout<<"0�Ķ�����λ��ȫΪ0��\n";

bitset<8>bs3( (long) 121 );
 bs3.reset();
cout<<"��121������λȫ������Ϊ0\n";
if(bs3.none())
cout<<"���óɹ�:";
cout<<bs3<<"\t����ռ���ڴ棺"<<bs3.size()<<"λ"<<endl;
bitset<8>bs4( (long) 121 );
cout<<"121�Ķ����Ƶ�3λΪ��"<<bs.test(3)<<endl;
cout << bs4<< endl;
	bs4.set(7,1);
cout <<"����7λ����Ϊ1\n"<<bs4<< endl;
string str=bs4.to_string();
	cout<<str<<endl;

bitset<8>bs5( (long) 10 );
unsigned long ul=bs5.to_ulong();
cout<<bs5<<"���޷��ų�������ʽ:"<<ul<<endl;


bitset<8>bs6( (long) 1 );
	cout<<bs6<<"��"<<bs6.count()<<"λΪ1"<<endl;

system("pause");
}
