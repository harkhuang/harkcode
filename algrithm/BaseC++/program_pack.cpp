#include <stdio.h>
//pragma(��ע; ����ָʾ;)  
#pragma pack(8)

//���ڵ���λ�����Ż��ֽڳ��� �������ڵ���λ�������Ż�����
struct One{
    double d; // 8 
    char c; // 4
    int i;   // 4
};


struct Two{
    char c;// 8
    double d; // 8
    int i; //8
};

struct Three{
	char c;//1
	char ca;//1
	char ca1;//1
	char ca3;//1
	char ca2;//1
	char ca11;//1
};



//  ��������㺬��   �ṹ���ڲ��ַ�����    �ṹ������Ķ���
int main(int argc, char *argv[])
{
	printf("One = %d,Two = %d ,Three=%d",sizeof(One),sizeof(Two),sizeof(Three));
	
	return 0;
}
