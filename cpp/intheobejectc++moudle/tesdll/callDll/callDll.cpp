//// callDll.cpp : �������̨Ӧ�ó������ڵ㡣
////
//
//#include "stdafx.h"
//#include "../tesdll/tesdll.h"
//#include<omp.h>  
//
//#include<iostream>  
//
//using namespace std;  
////ѭ�����Ժ���  
//void test()  
//{  
//	for(int i=0;i<10000;i++)  
//	{  
//
//	}  
//}  
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//
//	Ctesdll a;
//	//a.foo();
//
//
//	std::cout<<"����һ�����в��Գ���!\n";  
//	double start = omp_get_wtime( );//��ȡ��ʼʱ��  
//	#pragma ompparallel for  
//	for(int i = 0; i < 10000; i++)  
//	{   
//		test();  
//	}  
//
//	double end = omp_get_wtime( );  
//
//	cout<<"�����ʱΪ��"<<end -start<<"\n";  
//
//	getchar();
//
//	return 0;
//}
//
#include "stdafx.h"  

#include<omp.h>  

#include <iostream>  

using namespace std;  


//ѭ�����Ժ���  
void test()  
{  
	for(int i=0;i<10000;i++)  
	{  

	}  
}  


void test1()
{
	double start = omp_get_wtime( );//��ȡ��ʼʱ��  


#pragma ompparallel for  
	for(int i = 0; i < 10000; i++)   
	{  
		test();  
	}  


	double end = omp_get_wtime( );  

	cout<<"�����ʱΪ��"<<end -start<<"\n";  

}



void cal(void * ptr)
{
	void * ptr1 = malloc(4); 
	*(int *)ptr  =  110;
}
int _tmain(int argc, _TCHAR* argv[])  
{  
	cout<<"����һ�����в��Գ���!\n";  

	void *ptr = malloc(4);


	*(int *)ptr  =  100;
	cal(ptr);
	
	int a = (int )ptr;

	return 0;  
}  