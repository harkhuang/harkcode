#include <iostream>
using namespace std;
int main()
{
  bool quit=false;
  for (;;)
  {
	  char choice;
	  cout<<"(0)��(1)Ҽ(2)��(3)��(4)��(5)��(6)½(7)��(8)��(9)��(q)�˳���";
      cin>>choice;
	  switch(choice) 
  {
  case '0':cout<<"����������㣡\n";
  	  break;
  case '1':cout<<"���������Ҽ��\n";
	  break;
  case '2':cout<<"��������Ƿ���\n";
	  break;
  case '3':cout<<"�������������\n";
			break;
  case '4':cout<<"�������������\n";
			break;
  case '5':cout<<"����������飡\n";
			break;	
  case '6':cout<<"���������½��\n";
			break;
  case '7':cout<<"����������⣡\n";
			break;
  case '8':cout<<"��������ǰƣ�\n";
			break;
  case '9':cout<<"��������Ǿ���\n";
			break;
  case 'q':quit=true;
	  break;
  default:cout<<"������Ĳ���0��9֮�����Ч���֡�\n";
	  }
  if (quit==true)
  {
	  break;
  }
  }
  
  cout<<"\n �������\n";
  return 0;
}
�ܽ᣺������Ҫ����������ת��ĳ�����ִ�У���goto��䣬
������Ҫ��ĳ�����������жϣ�Ϊ���Ϊ�ٷֱ�ִ�в�ͬ����䣬��if���
������Ҫ���������ܶ࣬��if..else��䣬
�����Ƕ����ֻ����ַ����м�Ⲣ����Ҫ���������ֺܶ࣬��switch��䣬
�����ܹ�ȷ��ѭ���Ĵ�������for��䣬
���粻��ȷ��ѭ���Ĵ�������while��䣬
����ѭ�����е��������Ҫִ��һ�Σ���ô��do��while��䡣
���⣺continue����ʹѭ����һ�����¿�ʼ����break����ʹѭ��ֱ�ӽ�����
