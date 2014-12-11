//例21.39   使用命令行处理文件例程
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc,char*argv[] )
{
	if (argc==1)
	{
		cerr<<"该程序"<<argv[0]<<"未操作文件名\n";
		exit(EXIT_FAILURE);//exit()函数就是退出程序，传入的参数是程序退出时的状态码，0表示正常退出，其他表示非正常退出。
		//标准C里有EXIT_SUCCESS和EXIT_FAILURE两个宏，我们可以在编译器里选中EXIT_FAILURE或者EXIT_SUCCESS单击右键用Go To Definition来查阅一下它们的值，如下：
		//#define EXIT_SUCCESS    0
		//#define EXIT_FAILURE    1
		//这样exit(EXIT_FAILURE)就表示不正常的退出程序
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
			cerr<<"不能打开文件"<<argv[file]<<endl;
			fin.clear();
			continue;
		}
		count=0;
		while (fin.get(ch))
		{
			count++;
		}
		cout<<count<<"字符在"<<argv[file]<<endl;
		total+=count;
		fin.clear();
		fin.close();
	}
	cout<<total<<"所有文件中的字符合计\n";
	return 0;
}
