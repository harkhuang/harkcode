#include  < iostream > 
using   namespace  std;
union U1  
{
	char c;
	int  i;
	double d;
} ;
struct  S1  
{
	char c;
	int  i;
	double d;
} ; 
union U2  
{
	char c;
	int  i;
} ;
struct  S2  
{
	char c;
	int  i;
} ; 
union U3 
{
	char c;
} ;  
struct  S3  
{
	char c;
} ; 
int  main()  
{
	cout << " ������U1��ռ�ֽڴ�СΪ�� " << sizeof (U1) << endl;
	cout << " ������U2��ռ�ֽڴ�СΪ�� " << sizeof (U2) << endl;
	cout << " ������U3��ռ�ֽڴ�СΪ�� " << sizeof (U3) << endl;
	cout << endl;
	cout << " -------------------------------- " << endl;
	cout << " �ṹ��S1��ռ�ֽڴ�СΪ�� " << sizeof (S1) << endl;
	cout << " ���� " << sizeof ( char ) << " + " << sizeof ( int ) << " + " << sizeof ( double ) << " = " << sizeof ( char ) + sizeof ( int ) + sizeof ( double ) << endl;
	cout << " ---------- " << endl;
	cout << " �ṹ��S2��ռ�ֽڴ�СΪ��" << sizeof (S2) << endl;
	cout << " ���� " << sizeof ( char ) << " + " << sizeof ( int ) << " = " << sizeof ( char ) + sizeof ( int ) << endl;
	cout << " -------------------------------- " << endl;
	cout << " �ṹ��S3��ռ�ֽڴ�СΪ��" << sizeof (S3) << endl;
	cout << " -------------------------------- " << endl;
	return   0 ;
} 
