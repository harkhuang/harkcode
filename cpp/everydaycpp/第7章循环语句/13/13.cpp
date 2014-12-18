#include <iostream>
using namespace std;
int main()
{
  bool quit=false;
  for (;;)
  {
	  char choice;
	  cout<<"(0)零(1)壹(2)贰(3)叁(4)肆(5)伍(6)陆(7)柒(8)捌(9)玖(q)退出：";
      cin>>choice;
	  switch(choice) 
  {
  case '0':cout<<"您输入的是零！\n";
  	  break;
  case '1':cout<<"您输入的是壹！\n";
	  break;
  case '2':cout<<"您输入的是贰！\n";
	  break;
  case '3':cout<<"您输入的是叁！\n";
			break;
  case '4':cout<<"您输入的是肆！\n";
			break;
  case '5':cout<<"您输入的是伍！\n";
			break;	
  case '6':cout<<"您输入的是陆！\n";
			break;
  case '7':cout<<"您输入的是柒！\n";
			break;
  case '8':cout<<"您输入的是捌！\n";
			break;
  case '9':cout<<"您输入的是玖！\n";
			break;
  case 'q':quit=true;
	  break;
  default:cout<<"您输入的不是0到9之间的有效数字。\n";
	  }
  if (quit==true)
  {
	  break;
  }
  }
  
  cout<<"\n 程序结束\n";
  return 0;
}
总结：假如想要无条件的跳转到某条语句执行，用goto语句，
假如想要对某种条件进行判断，为真或为假分别执行不同的语句，用if语句
假如需要检测的条件很多，用if..else语句，
假如是对数字或者字符进行检测并且需要检测的条件又很多，用switch语句，
假如能够确定循环的次数，用for语句，
假如不能确定循环的次数，用while语句，
假如循环体中的语句至少要执行一次，那么用do…while语句。
另外：continue可以使循环又一次重新开始，而break可以使循环直接结束。
