 #include <iostream>
using namespace std;
class A 
{
public:
	A(int i){cout<<"执行构造函数创建一个对象\n";x=i;}
	A(const A&a){x=a.x;cout<<"执行复制构造函数创建一个对象\n";}
	~A(){cout<<"执行析构函数!\n";}
	int get(){return x;}
private:
	int x;
};
A &func();
int main()
{
   A&r=func();//r作为*p的别名，也就是堆中对象的别名
   cout<<"&r:"<<&r<<endl;//r的地址就是堆中对象的地址。
   cout<<r.get()<<endl;//使用r这个别名来访问get()函数。
   A*pa=&r;//将别名的内存地址，也就是堆中对象的地址赋给pa
   delete pa;//删除pa指向的堆中对象的内存空间。
   cout<<r.get()<<endl;//别名r成了个空引用
   return 0;
}
A &func()//按值返回的func函数
 {
  A *p=new A(99);//创建一个堆中对象并用p指向它同时初始化
  //该对象的成员变量x的值为99
  cout<<"p:"<<p<<endl;//输出p中保存的内存地址。
  return *p;//返回堆中对象
}
