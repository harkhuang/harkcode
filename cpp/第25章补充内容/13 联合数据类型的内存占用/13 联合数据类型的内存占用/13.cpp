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
	cout << " 联合体U1所占字节大小为： " << sizeof (U1) << endl;
	cout << " 联合体U2所占字节大小为： " << sizeof (U2) << endl;
	cout << " 联合体U3所占字节大小为： " << sizeof (U3) << endl;
	cout << endl;
	cout << " -------------------------------- " << endl;
	cout << " 结构体S1所占字节大小为： " << sizeof (S1) << endl;
	cout << " 其中 " << sizeof ( char ) << " + " << sizeof ( int ) << " + " << sizeof ( double ) << " = " << sizeof ( char ) + sizeof ( int ) + sizeof ( double ) << endl;
	cout << " ---------- " << endl;
	cout << " 结构体S2所占字节大小为：" << sizeof (S2) << endl;
	cout << " 其中 " << sizeof ( char ) << " + " << sizeof ( int ) << " = " << sizeof ( char ) + sizeof ( int ) << endl;
	cout << " -------------------------------- " << endl;
	cout << " 结构体S3所占字节大小为：" << sizeof (S3) << endl;
	cout << " -------------------------------- " << endl;
	return   0 ;
} 
