 #include <iostream>
using namespace std;
class A 
{
public:
	A(int i){cout<<"ִ�й��캯������һ������\n";x=i;}
	A(const A&a){x=a.x;cout<<"ִ�и��ƹ��캯������һ������\n";}
	~A(){cout<<"ִ����������!\n";}
	int get(){return x;}
private:
	int x;
};
A &func();
int main()
{
   A&r=func();//r��Ϊ*p�ı�����Ҳ���Ƕ��ж���ı���
   cout<<"&r:"<<&r<<endl;//r�ĵ�ַ���Ƕ��ж���ĵ�ַ��
   cout<<r.get()<<endl;//ʹ��r�������������get()������
   A*pa=&r;//���������ڴ��ַ��Ҳ���Ƕ��ж���ĵ�ַ����pa
   delete pa;//ɾ��paָ��Ķ��ж�����ڴ�ռ䡣
   cout<<r.get()<<endl;//����r���˸�������
   return 0;
}
A &func()//��ֵ���ص�func����
 {
  A *p=new A(99);//����һ�����ж�����pָ����ͬʱ��ʼ��
  //�ö���ĳ�Ա����x��ֵΪ99
  cout<<"p:"<<p<<endl;//���p�б�����ڴ��ַ��
  return *p;//���ض��ж���
}
