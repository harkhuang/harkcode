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
cout<<"反置函数flip调用"<<bs.flip()<<endl;
bitset<8>bs1( (long) 0 );
if(bs1.none())
{
	cout<<"0的二进制位均为0。\n";
}
else
	cout<<"0的二进制位不全为0。\n";

if(!bs1.any())
{
	cout<<"0的二进制位均为0。\n";
}
else
	cout<<"0的二进制位不全为0。\n";

bitset<8>bs3( (long) 121 );
 bs3.reset();
cout<<"将121的所有位全部重置为0\n";
if(bs3.none())
cout<<"重置成功:";
cout<<bs3<<"\t该数占用内存："<<bs3.size()<<"位"<<endl;
bitset<8>bs4( (long) 121 );
cout<<"121的二进制第3位为："<<bs.test(3)<<endl;
cout << bs4<< endl;
	bs4.set(7,1);
cout <<"将第7位设置为1\n"<<bs4<< endl;
string str=bs4.to_string();
	cout<<str<<endl;

bitset<8>bs5( (long) 10 );
unsigned long ul=bs5.to_ulong();
cout<<bs5<<"的无符号长整数形式:"<<ul<<endl;


bitset<8>bs6( (long) 1 );
	cout<<bs6<<"有"<<bs6.count()<<"位为1"<<endl;

system("pause");
}
