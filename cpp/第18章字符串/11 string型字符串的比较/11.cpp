#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1="155";
	string s2="52";
	char c[]="34";
	int i,j,k,l,m,n;
	i=s1.compare(s2);//��s2��s1�Ƚϣ�����0Ϊ��ȣ�1Ϊs1����s2��-1Ϊs1С��s2
	j=s2.compare(c);//��char���ַ���c��s2�Ƚ�
	k=s1.compare(0,2,s2);//ȡs1ǰ�����ַ���s1���Ƚϣ�����1��ʾȡ��s1���ַ�����
	l=s1.compare(1,1,s2,0,1);//ȡs1[1]��s2[0]���Ƚϣ�����2��4�ֱ��ʾȡ��s1��s2���ַ�����
	m=s1.compare(1,1,c,0,1);//ȡs1[1]��c[0]���Ƚϣ�����2��4�ֱ��ʾȡ��s1��c���ַ�����
	n=s1.compare(1,1,c,1);//ȡs1[1]��c[0]���Ƚϣ�����1��ʾȡ��s1���ַ�����
	cout<<s1<<":"<<s2<<"="<<i<<endl; //����������αȽ�
	cout<<s2<<":"<<c<<"="<<j<<endl;
	cout<<s1[0]<<s1[1]<<":"<<s2<<"="<<k<<endl;
	cout<<s1[1]<<":"<<s2[0]<<"="<<l<<endl;
	cout<<s1[1]<<":"<<c[0]<<"="<<m<<endl;
	cout<<s1[1]<<":"<<c[0]<<"="<<n<<endl;
	return 0;
} 
