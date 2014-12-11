/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int num=2;
int main()
{
	vector<double>price(num);
	vector<string>book(num);
	cout<<"��ʼ¼��"<<num<<"���������"<<endl;
	for (int i=0;i<num;i++)
	{
		cout<<"�������"<<i+1<<"�����������";
		getline(cin,book[i]);
		cout<<"���������ļ۸�";
		cin>>price[i];
		cin.ignore();
	}
	
	for (int i=0;i<num;i++)
	{
		cout<<"��"<<i+1<<"�����������";
		cout<<book[i]<<"\t"<<"�۸�"<<price[i]<<endl;
	}
	return 0;
}
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class people
{
  public:
   people();
   people(const string&name,const int age);
   people(const people&r);
   ~people();
   void SetName(const string&name);
   string GetName()const;
   void SetAge(const int age);
   int GetAge()const;
   people&operator=(const people&r);
  private:
   string theName;
   int theAge;
};
people::people():theName("Ĭ�ϴ���������"),theAge(52){}
people::people(const string&name,const int age):theName(name),theAge(age){}
people::people(const people&r):theName(r.GetName()),theAge(r.GetAge())
{
  cout<<"���ƹ��캯��ִ��...\n";
}
people::~people(){cout<<"��������ִ��\n";}
void people::SetName(const string&r)
{
  theName=r;
}
string people::GetName()const
{
  return theName;
}
void people::SetAge( const int age)
{
  theAge=age;
}
int people::GetAge()const
{
  return theAge;
}
people&people::operator =(const people&r)
{
  cout<<"operator=����ִ��...\n";
  theName=r.GetName();
  theAge=r.GetAge();
  return*this;
}
ostream &operator<<(ostream&out,const people&r)
{
  out<<r.GetName()<<"������Ϊ��"<<r.GetAge()<<endl;
  return out;
}
template<class T>
void show(const vector<T>&v);
typedef vector<people>man;
int main()
{
  people Jack;
  people Mary("Mary",24);
  people Tom("Tom",18);
  people Jesson("Jesson",29);
  man non;
  cout<<"non:\n";
  show(non);
  man manyMan(3);
  cout<<"manyMan(3):\n";
  show(manyMan);
  manyMan[0]=Mary;
  manyMan[1]=Tom;
  manyMan[2]=Jesson;
  cout<<"Ϊ����manyMan(3)������˺�:\n";
  show(manyMan);
  people Ketty("Ketty",58);manyMan.push_back(Ketty);manyMan.push_back(Jack);
  cout<<"manyMan()����2���˺�:\n";
  show(manyMan);
  manyMan[0].SetName("Rose");
  manyMan[0].SetAge(16);
  cout<<"����manyMan[0]��:\n";
  system("pause");
  return 0;
}
template <class T>
void show(const vector<T>&v)
{
  cout<<"max_size()="<<v.max_size();
  cout<<"\tsize()="<<v.size();
  cout<<"\t capacity()="<<v.capacity();
  cout<<"\t"<<(v.empty()?"��":"��Ϊ��");
  cout<<"\n";
  for (int i=0;i<v.size();++i)
  {
   cout<<v[i]<<"\n";
   }
  cout<<endl;
}
