#include <iostream>
using namespace std;
void show()
{
	cout<<"��������ں�����Ϊ��"<<__FUNCDNAME__<<endl;
	cout<<"��ǰ�ļ�Ϊ��"<<__FILE__<<endl;
	cout<<"��ǰ����������Ϊ��"<<__LINE__<<endl;
}
int main()
{
	cout<<"��ǰ�ļ�Ϊ��"<< __FILE__ <<endl;
	cout<<"��������Ϊ��"<<__DATE__<<endl;
	cout<<"����ʱ��Ϊ��"<<__TIME__<<endl;
	cout<<"��ǰ����������Ϊ��"<<__LINE__<<endl;
	cout<<"��������ں�����Ϊ��"<<__FUNCTION__<<endl;
	show();
	return 0;
}
