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
			cout<<"second.get()����"<<second.get()<<endl;
			cout<<"first.get()����"<<first.get()<<endl;
			cout<<"get()�������ܵĵ�һ������Ϊ��"<<t2<<endl;
			cout<<"get()�������ܵĵڶ�������Ϊ��"<<t1<<endl;
			cout<<"����4������ӵã�";
			return (second.get()+first.get()+t2+t1);
		}
		void show()const
		{
			cout<<"first.show()���ú������";
			first.show();
			cout<<"second.show()���ú������";
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
	cout<<"\nִ��get����\n";
	cout<<one.get(10,2.3)<<endl;
	return 0;
}
