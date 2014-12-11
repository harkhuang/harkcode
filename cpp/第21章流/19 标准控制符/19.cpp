//例19：标准控制符的使用
#include <iostream>
using namespace std;
int main()
{
	const int x=703710;				//定义一个正整数。
	cout<<"x:"<<oct<<x<<endl;		//八进制输出
    cout<<"x:"<<showbase<<x<<endl;	//在八进制前添加0
	cout<<"x:"<<hex<<x<<endl;		//十六进制输出
	cout<<"x:"<<uppercase<<x<<endl;	//用大写表示十六进制
	cout<<"x:"<<dec<<x<<endl;		//十进制输出
	cout<<"x:"<<showpos<<x<<endl;	//在正数前添加+号
	float y=3.56000f;				//定义一个浮点数
	cout.precision(0);				//设置精度为0
	cout<<"y:"<<scientific<<y<<endl;//以科学计数法输出浮点数
	cout.unsetf(ios::floatfield);
	cout<<"y:"<<showpoint<<y<<endl;	//精度为0时输出浮点数的有效位数字(6或7位)，精度不为0时输出该精度限制内的数字，这个精度指的是总精度，这两种情况均包括小数点
	cout.unsetf(ios::showpoint);    //去掉小数点的显示
	cout<<"y:"<<fixed<<y<<endl;   //精度指得是小数点后的精度，也不包括小数点
	char str1[] = "abc"; 
	char str2[] = "abc"; //定义两个字符数组
	const char str3[] = "abc"; 
	const char str4[] = "abc"; //定义两个常字符数组
	const char* str5 = "abc"; 
	const char* str6 = "abc"; //定义两个字符指针
	cout << boolalpha << ( str1==str2 ) << endl; // str1和str2都是字符数组，每个都有其自己的存储区，它们的值则是各存储区首地址，因此不相等。
	cout << boolalpha << ( str3==str4 ) << endl; //str3和str4同上，只不过多了个const表示它们所指向的数据区不能修改。因此不相等。
	cout << boolalpha << ( str5==str6 ) << endl; //str5和str6并非数组而是字符指针，并不分配存储区，tr5和str6中的"abc"以常量形式存于常量存储取，
	//也就是静态数据区，而它们自己仅是指向该区首地址的指针，相等 
	//分别输出false,false,true
	//boolalpha 用符号形式(true或者false)表示1和0，也就是真和假。
	cout.width(20);			//设定宽度
	cout<<right<<y<<endl;	//按指定宽度右对齐输出
	cout.width(20);			//再次设定宽度	
	cout<<left<<y<<endl;	//按指定宽度左对齐输出
	cout.width(20);			//再次设定宽度
	cout<<internal<<y<<endl;//按指定宽度中间对齐输出，符号在左，值靠右
	return 0;
}
