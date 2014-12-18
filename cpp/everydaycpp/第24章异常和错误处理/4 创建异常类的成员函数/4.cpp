#include <iostream>
using namespace std;
const int num=5;
class people
{
  public:
   people(int size=num);
   ~people(){delete[]p;}
   int&operator[](int off);
   const int&operator[](int off)const;
   int GetSize()const{return size;}
   class wrong{};
   class offset
    {
     public:
       offset(int Size):size(Size){}
       ~offset(){}
       int Get(){return size;}
     private:
       int size;
    };
  class Big:public offset
  {
    public:
      Big(int Size):offset(Size){}
  };
  class Nav:public offset
  {
    public:
      Nav(int Size):offset(Size){}
  };
  class Small
  {
    public:
      Small(int Size):size(Size){}
      ~Small(){}
      int get(){return size;}
    private:
      int size;
  };
  class Zero:public Small
  {
    public:
      Zero(int Size):Small(Size){}
  };
  private:
  int *p;
  int size;
};
people::people(int Size):size(Size)
{
  cout<<"调用构造函数\n";
  if (Size==0)
  {
    throw Zero(Size);
  }
  if (Size<10)
  {
    throw Small(Size);
  }
  if (Size>10000)
  {
    throw Big(Size);
  }
  if (Size<1)
  {
    throw Nav(Size);
  }
  p=new int[size];
  for (int i=0;i<size;i++)
  {
    p[i]=0;
  }
}
int&people::operator[](int off)
{
  int size=GetSize();
  if (off>=0&&off<GetSize())
  {
    return p[off];
  }
  throw wrong();
  return p[0];
}
const int&people::operator[](int off)const
{
  int Size=GetSize();
  if (off>=0&&off<GetSize())
  {
    return p[off];
  }
  throw wrong();
  return p[0];
}
int main()
{
  try
  {
   people one(9);
   for (int i=0;i<100;i++)
    {
     one[i]=i;
     cout<<"one["<<i<<"]赋值完毕..."<<endl;
    }
  }
  catch (people::wrong)
  {
     cout<<"超过数组长度，不能继续执行赋值操作！\n";
  }
  catch (people::Big big)
  {
    cout<<"下标值太大\n";
  }
  catch (people::Small small)
  {
    cout<<"下标值太小\n";
    cout<<"下标值为："<<small.get()<<endl;
  }
  catch (people::Zero zero)
  {
   cout<<"下标值为0\n";
  }
  catch (people::Nav nav)
  {
   cout<<"下标值为负数\n";
  }
  catch (people::offset) 
  {
    cout<<"下标值过大或为负数\n";
  }
  cout<<"程序结束\b\n";
  return 0;
}
