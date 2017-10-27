#include <stdio.h>
//pragma(杂注; 编译指示;)  
#pragma pack(8)

//相邻的两位可以优化字节长度 ，不相邻的两位不可以优化长度
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



//  对齐的两层含义   结构体内部字符对齐    结构体整体的对齐
int main(int argc, char *argv[])
{
	printf("One = %d,Two = %d ,Three=%d",sizeof(One),sizeof(Two),sizeof(Three));
	
	return 0;
}
