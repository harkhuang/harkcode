#include <iostream>
using namespace std;
template <class T1>
class One 
{
	public:
		One(T1 t,int i):first(t),second(t){}
		template<class T2>
		T2 get(T2 t2,T1 t1)
		{
			cout<<"second.get()返回"<<second.get()<<endl;
			cout<<"first.get()返回"<<first.get()<<endl;
			cout<<"get()函数接受的第一个参数为："<<t2<<endl;
			cout<<"get()函数接受的第二个参数为："<<t1<<endl;
			cout<<"以上4个数相加得：";
			return (second.get()+first.get()+t2+t1);
		}
		void show()const
		{
			cout<<"first.show()调用后输出：";
			first.show();
			cout<<"second.show()调用后输出：";
			second.show();
		}
	private:
		template<class T3>
		class two 
		{	
		public:
			two(T3 t3=0):x(t3){}
			void show()const{cout<<x<<endl;}
			T3 get()const{return x;}
		private:
			T3 x;
		};
		two<T1>first;
		two<int>second;
};
int main()
{
	One<double>one(3.5,4);
	one.show();
	cout<<"\n执行get函数\n";
	cout<<one.get(10,2.3)<<endl;
	return 0;
}
