// tesdll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "tesdll.h"
#include <iostream>

// ���ǵ���������һ��ʾ��
TESDLL_API int ntesdll=0;

// ���ǵ���������һ��ʾ����
TESDLL_API int fntesdll(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� tesdll.h
Ctesdll::Ctesdll()
{
	std::cout<< "xxxxxx" <<std::endl;
	return;
}


void Ctesdll::foo()
{
	std::cout<< "xxxxxx" <<std::endl;
	 
}
