#include <iostream>
using namespace std;
class father
{
  public:
  father(int height);	//���๹�캯������һ������height
  virtual ~father(){cout<<"��������...\n";}
  virtual void smart()const{cout<<"���׺ܴ���"<<endl;}
  virtual int getheight()const{return itsheight;} //ͨ����Ա��������˽�б���������˽�б�����ֵ���ú�����˵��Ϊ�麯��
  private:
  int itsheight; //˽�г�Աitsheight
};
father::father(int height):itsheight(height)	//ͨ�����캯��������˽�б�����ֵ
{
  cout<<"��������\n";
}
class mother
{
  public:
  mother(bool sex); 	//ĸ��Ĺ��캯����һ�������Ͳ���sex
  virtual ~mother(){cout<<"����ĸ��\n";}
  virtual void beautiful()const{cout<<"ĸ�׺�Ư��\n";}
  virtual bool getsex()const{return itsex;}	//ͨ�������ͳ�Ա��������˽�б���������˽�б�����ֵ���ú�����˵��Ϊ�麯��
  private:
  bool itsex; 	//˽�в�������itsex
};
mother::mother(bool sex):itsex(sex) 	//����ĸ��Ĳ����͹��캯��sex������˽�г�Ա��ֵ
{
  cout<<"����ĸ��\n";
}
class son:public father,public mother //����ֱ�̳�ĸ��͸��࣬�̳�Ȩ��Ϊ����
{
  public:
  ~son(){cout<<"����С����..."<<endl;}
  son(int,bool,long);  //����Ĺ��캯��������������������Ϊint��bool��long��
  virtual long getnum()const 	//ͨ��long�ͳ�Ա����getnum���ʲ�����˽�б���num��ֵ��
  {
    return num;
  }
  private:
  long num;
};
son::son(int height,bool sex,long number):father(height),mother(sex),
num(number)		//�����ڹ��캯����ͬʱ���г�ʼ������ʼ����˳���ɳ���Աָ�������������ȳ�ʼ������height������Ȼ���ʼ��ĸ���sex����������ʼ�������number������
{                   //������Щ��ʼ��������ɺ�
  cout<<"����С����\n";	//����ִ��son�Ĺ��캯��
}
int main()
{
  son*ps=new son(5,true,3);	//�ڶ��д���һ��son����󲢳�ʼ�����캯��������������ͬʱ����һ��son���ָ��ʹ��ָ������½��Ķ�
  ps->beautiful(); 	//�ø�ָ����ʴ�ĸ��̳������麯��
  ps->smart();    	//�ø�ָ����ʴӸ���̳������麯��
  cout<<"\nС������"<<ps->getheight();	//�ø�ָ����ʴӸ���̳������麯��
  cout<<"Ӣ�߸�\n";
  if(ps->getsex()) 			//�ø�ָ����ʴ�ĸ��̳����Ĳ�������
    cout<<"�Ա���";
  else
    cout<<"�Ա�Ů";
  cout<<"\n�ڼ����У���"<<ps->getnum()<<endl;	//�ø�ָ����������getnum����
  delete ps;								//ɾ�����ָ��son������ָ��
  system("pause");
  return 0;
}
