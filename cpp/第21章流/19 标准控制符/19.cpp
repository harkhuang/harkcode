//��19����׼���Ʒ���ʹ��
#include <iostream>
using namespace std;
int main()
{
	const int x=703710;				//����һ����������
	cout<<"x:"<<oct<<x<<endl;		//�˽������
    cout<<"x:"<<showbase<<x<<endl;	//�ڰ˽���ǰ���0
	cout<<"x:"<<hex<<x<<endl;		//ʮ���������
	cout<<"x:"<<uppercase<<x<<endl;	//�ô�д��ʾʮ������
	cout<<"x:"<<dec<<x<<endl;		//ʮ�������
	cout<<"x:"<<showpos<<x<<endl;	//������ǰ���+��
	float y=3.56000f;				//����һ��������
	cout.precision(0);				//���þ���Ϊ0
	cout<<"y:"<<scientific<<y<<endl;//�Կ�ѧ���������������
	cout.unsetf(ios::floatfield);
	cout<<"y:"<<showpoint<<y<<endl;	//����Ϊ0ʱ�������������Чλ����(6��7λ)�����Ȳ�Ϊ0ʱ����þ��������ڵ����֣��������ָ�����ܾ��ȣ����������������С����
	cout.unsetf(ios::showpoint);    //ȥ��С�������ʾ
	cout<<"y:"<<fixed<<y<<endl;   //����ָ����С�����ľ��ȣ�Ҳ������С����
	char str1[] = "abc"; 
	char str2[] = "abc"; //���������ַ�����
	const char str3[] = "abc"; 
	const char str4[] = "abc"; //�����������ַ�����
	const char* str5 = "abc"; 
	const char* str6 = "abc"; //���������ַ�ָ��
	cout << boolalpha << ( str1==str2 ) << endl; // str1��str2�����ַ����飬ÿ���������Լ��Ĵ洢�������ǵ�ֵ���Ǹ��洢���׵�ַ����˲���ȡ�
	cout << boolalpha << ( str3==str4 ) << endl; //str3��str4ͬ�ϣ�ֻ�������˸�const��ʾ������ָ��������������޸ġ���˲���ȡ�
	cout << boolalpha << ( str5==str6 ) << endl; //str5��str6������������ַ�ָ�룬��������洢����tr5��str6�е�"abc"�Գ�����ʽ���ڳ����洢ȡ��
	//Ҳ���Ǿ�̬���������������Լ�����ָ������׵�ַ��ָ�룬��� 
	//�ֱ����false,false,true
	//boolalpha �÷�����ʽ(true����false)��ʾ1��0��Ҳ������ͼ١�
	cout.width(20);			//�趨���
	cout<<right<<y<<endl;	//��ָ������Ҷ������
	cout.width(20);			//�ٴ��趨���	
	cout<<left<<y<<endl;	//��ָ�������������
	cout.width(20);			//�ٴ��趨���
	cout<<internal<<y<<endl;//��ָ������м�����������������ֵ����
	return 0;
}
