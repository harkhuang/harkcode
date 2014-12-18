#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1="155";
	string s2="52";
	char c[]="34";
	int i,j,k,l,m,n;
	i=s1.compare(s2);//将s2与s1比较，返回0为相等，1为s1大于s2，-1为s1小于s2
	j=s2.compare(c);//将char型字符串c与s2比较
	k=s1.compare(0,2,s2);//取s1前两个字符与s1做比较，参数1表示取的s1的字符长度
	l=s1.compare(1,1,s2,0,1);//取s1[1]与s2[0]做比较，参数2和4分别表示取的s1和s2的字符长度
	m=s1.compare(1,1,c,0,1);//取s1[1]与c[0]做比较，参数2和4分别表示取的s1和c的字符长度
	n=s1.compare(1,1,c,1);//取s1[1]与c[0]做比较，参数1表示取的s1的字符长度
	cout<<s1<<":"<<s2<<"="<<i<<endl; //依次输出各次比较
	cout<<s2<<":"<<c<<"="<<j<<endl;
	cout<<s1[0]<<s1[1]<<":"<<s2<<"="<<k<<endl;
	cout<<s1[1]<<":"<<s2[0]<<"="<<l<<endl;
	cout<<s1[1]<<":"<<c[0]<<"="<<m<<endl;
	cout<<s1[1]<<":"<<c[0]<<"="<<n<<endl;
	return 0;
} 
