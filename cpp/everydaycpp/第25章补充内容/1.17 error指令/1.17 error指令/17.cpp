#include <iostream>
#define Test
using namespace std;
int main()
{
#ifndef Test
#error  Testδ���嵼�±���ʧ��
#endif
	cout<<"�������"<<endl;
}
