#include <iostream>
using namespace std;
class father
{
  public:
  father(int height);	//父类构造函数带有一个参数height
  virtual ~father(){cout<<"析构父亲...\n";}
  virtual void smart()const{cout<<"父亲很聪明"<<endl;}
  virtual int getheight()const{return itsheight;} //通过成员函数访问私有变量并设置私有变量的值，该函数被说明为虚函数
  private:
  int itsheight; //私有成员itsheight
};
father::father(int height):itsheight(height)	//通过构造函数来设置私有变量的值
{
  cout<<"创建父亲\n";
}
class mother
{
  public:
  mother(bool sex); 	//母类的构造函数有一个布尔型参数sex
  virtual ~mother(){cout<<"析构母亲\n";}
  virtual void beautiful()const{cout<<"母亲很漂亮\n";}
  virtual bool getsex()const{return itsex;}	//通过布尔型成员函数访问私有变量并设置私有变量的值，该函数被说明为虚函数
  private:
  bool itsex; 	//私有布尔变量itsex
};
mother::mother(bool sex):itsex(sex) 	//定义母类的布尔型构造函数sex并设置私有成员的值
{
  cout<<"创建母亲\n";
}
class son:public father,public mother //子类分别继承母类和父类，继承权限为公有
{
  public:
  ~son(){cout<<"析构小儿子..."<<endl;}
  son(int,bool,long);  //子类的构造函数带有三个参数，类型为int，bool和long。
  virtual long getnum()const 	//通过long型成员函数getnum访问并返回私有变量num的值。
  {
    return num;
  }
  private:
  long num;
};
son::son(int height,bool sex,long number):father(height),mother(sex),
num(number)		//子类在构造函数的同时进行初始化，初始化的顺序由程序员指定，这里是首先初始化父类height参数，然后初始化母类的sex参数，最后初始化子类的number参数。
{                   //所有这些初始化工作完成后
  cout<<"创建小儿子\n";	//方才执行son的构造函数
}
int main()
{
  son*ps=new son(5,true,3);	//在堆中创建一个son类对象并初始化构造函数的三个参数，同时声明一个son类的指针使其指向这个新建的堆
  ps->beautiful(); 	//用该指针访问从母类继承来的虚函数
  ps->smart();    	//用该指针访问从父类继承来的虚函数
  cout<<"\n小儿子有"<<ps->getheight();	//用该指针访问从父类继承来的虚函数
  cout<<"英尺高\n";
  if(ps->getsex()) 			//用该指针访问从母类继承来的布尔函数
    cout<<"性别：男";
  else
    cout<<"性别：女";
  cout<<"\n在家排行：第"<<ps->getnum()<<endl;	//用该指针访问子类的getnum函数
  delete ps;								//删除这个指向son类对象的指针
  system("pause");
  return 0;
}
