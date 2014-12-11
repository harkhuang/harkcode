#include <iostream>
using namespace std;
int main()
{
  int choice;
  cout<<"请输入一个整数：";
  cin>>choice;
  switch(choice) 
  {
  case 0:cout<<"您输入的是零！";
  	  //break;
  case 1:cout<<"您输入的是壹！";
	  //break;
  case 2:cout<<"您输入的是贰！";
	  //break;
  case 3:cout<<"您输入的是叁！";
			//break;
  case 4:cout<<"您输入的是肆！";
			//break;
  case 5:cout<<"您输入的是伍！";
			//break;	
  case 6:cout<<"您输入的是陆！";
			//break;
  case 7:cout<<"您输入的是柒！";
		//	break;
  case 8:cout<<"您输入的是捌！";
		//	break;
  case 9:cout<<"您输入的是玖！";
			//break;

  default:cout<<"您输入的不是0到9之间的有效数字。";
  }
  cout<<"\n 程序结束\n";
  return 0;
}