//��21.39   ʹ�������д����ļ�����
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc,char*argv[] )
{
	if (argc==1)
	{
		cerr<<"�ó���"<<argv[0]<<"δ�����ļ���\n";
		exit(EXIT_FAILURE);//exit()���������˳����򣬴���Ĳ����ǳ����˳�ʱ��״̬�룬0��ʾ�����˳���������ʾ�������˳���
		//��׼C����EXIT_SUCCESS��EXIT_FAILURE�����꣬���ǿ����ڱ�������ѡ��EXIT_FAILURE����EXIT_SUCCESS�����Ҽ���Go To Definition������һ�����ǵ�ֵ�����£�
		//#define EXIT_SUCCESS    0
		//#define EXIT_FAILURE    1
		//����exit(EXIT_FAILURE)�ͱ�ʾ���������˳�����
	}
	ifstream fin;
	long count;
	long total=0;
	char ch;
	for (int file=1;file<argc;file++)
	{
		fin.open(argv[file]);
		if (!fin.is_open())
		{
			cerr<<"���ܴ��ļ�"<<argv[file]<<endl;
			fin.clear();
			continue;
		}
		count=0;
		while (fin.get(ch))
		{
			count++;
		}
		cout<<count<<"�ַ���"<<argv[file]<<endl;
		total+=count;
		fin.clear();
		fin.close();
	}
	cout<<total<<"�����ļ��е��ַ��ϼ�\n";
	return 0;
}
