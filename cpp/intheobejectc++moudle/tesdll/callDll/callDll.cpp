//// callDll.cpp : 定义控制台应用程序的入口点。
////
//
//#include "stdafx.h"
//#include "../tesdll/tesdll.h"
//#include<omp.h>  
//
//#include<iostream>  
//
//using namespace std;  
////循环测试函数  
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
//	std::cout<<"这是一个串行测试程序!\n";  
//	double start = omp_get_wtime( );//获取起始时间  
//	#pragma ompparallel for  
//	for(int i = 0; i < 10000; i++)  
//	{   
//		test();  
//	}  
//
//	double end = omp_get_wtime( );  
//
//	cout<<"计算耗时为："<<end -start<<"\n";  
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


//循环测试函数  
void test()  
{  
	for(int i=0;i<10000;i++)  
	{  

	}  
}  


void test1()
{
	double start = omp_get_wtime( );//获取起始时间  


#pragma ompparallel for  
	for(int i = 0; i < 10000; i++)   
	{  
		test();  
	}  


	double end = omp_get_wtime( );  

	cout<<"计算耗时为："<<end -start<<"\n";  

}



void cal(void * ptr)
{
	void * ptr1 = malloc(4); 
	*(int *)ptr  =  110;
}
int _tmain(int argc, _TCHAR* argv[])  
{  
	cout<<"这是一个并行测试程序!\n";  

	void *ptr = malloc(4);


	*(int *)ptr  =  100;
	cal(ptr);
	
	int a = (int )ptr;

	return 0;  
}  