/*
#include <iostream>
using namespace std;
int main()
{
	const float number=-185;
	cout.width(10);
	cout.setf(ios::internal);
	cout<<number<<endl;
	return 0;
}
*/

/*
//��21.15.1	����15����־��ʮ����ֵ
#include <iostream>
using namespace std;
int main()
{
	cout << "boolalpha    " << ios::boolalpha <<endl;  
	
	cout << "fixed        " << ios::fixed << endl; 
	cout << "scientific   " << ios::scientific << endl; 
	
	cout << "hex          " <<ios::hex << endl;
	cout << "oct          " << ios::oct << endl;
	cout << "dec          " << ios::dec << endl;    
	
	cout << "internal     " << ios::internal << endl;
	cout << "right        " << ios::right << endl;   
	cout << "left         " << ios::left << endl;
	cout << "showpos      " << ios::showpos <<endl;
	cout << "showpoint    " << ios::showpoint <<endl;
	cout << "showbase     " << ios::showbase <<endl;
	cout << "uppercase    " << ios::uppercase <<endl;
	cout << "unitbuf      " << ios::unitbuf << endl;
	cout << "skipws       " << ios::skipws << endl;
	cout << endl;	
	return 0;
}
*/


/*
//��21.15.2	  Ĭ��skipws��־�ѿ���
#include <iostream>
using namespace std;
int main()
{
	char ch[10];
	cin>>ch;
	cout<<ch;
	return 0;
} 
*/

//��21.15.4  ��־���ò������ֵĴ���
#include <iostream>
using namespace std;
int main()
{
	const float number=-185;
	cout.width(10);
	cout.setf(ios::left);
	cout<<number<<endl;
	cout.width(10);
	cout.setf(ios::right);
	cout<<number<<endl;
	cout.width(10);
	cout.setf(ios::internal);
	cout<<number<<endl;
	return 0;
} 
