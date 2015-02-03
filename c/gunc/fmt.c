#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#define _vsnprintf vsnprintf 

#if 0
int mon_log(char* format, ...)
{
	char str_tmp[50];
	int i=0;
	va_list vArgList; //����һ��va_list�͵ı���,���������ָ�������ָ��.
	//���������б�
	va_start (vArgList, format); //��va_start���ʼ������,�����ĵڶ��������ǵ�һ���ɱ������ǰһ���� //��,��һ���̶��Ĳ���.
	i=vsnprintf(str_tmp, 50, format, vArgList); //ע��,��Ҫ©��ǰ���_(vc��  _vsnprintf)(gunc�� vsnprintf)
	va_end(vArgList); //��va_end������ɱ�����Ļ�ȡ
	
	return i; //���ز������ַ������м��ж��ż��
}
//��������ĺ���
void main()
{
	int i=mon_log("%s,%d,%d,%d","asd",2,3,4);
	printf("%d\n",i);
}

//��� 9��


//����:
//asd,2,3,4
//123456789 ����9���ַ�����������ż������ڣ�
//����ֵ�÷���

#else
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

//���������������messgae
char *make_message(const char *fmt, ...) 
{
	/* ��ʼʱ��������ֻ��Ҫ������100�ֽڴ�С�Ŀռ� */
	int n, size = 100;//���ñ���
	char *p;//ָ�����p
	va_list ap;//�б����  ap
	if ( (p = (char *) malloc(size*sizeof(char))) == NULL)//Ϊָ�������ڴ�ռ�
	{
		return NULL;//����ڴ�û������ɹ�
	}
	while (1)
	{
				/* ����������Ŀռ��н��д�ӡ���� */
				va_start(ap, fmt);//��ʼ�����б�
				n = vsnprintf (p, size, fmt, ap);//
				va_end(ap);
				/* ���vsnprintf���óɹ������ظ��ַ��� */
				if (n > -1 && n < size)
				{
					return p;
				}
				/* vsnprintf����ʧ��(n<0)������p�Ŀռ䲻�㹻����size��С���ַ���(n>=size)�������������Ŀռ�*/
				size *= 2; /* ����ԭ����С�Ŀռ� */
				if ((p = (char *)realloc(p, size*sizeof(char))) == NULL)
				{
					return NULL;
				}
	}
}
int main() 
{
	/* ��������ĺ��� */
	char* str = make_message("%d,%d,%d,%d",5,6,7,8);
	printf("%s\n",str);
	free(str);
	/* we allocate the memory in the make_message function, so we should release it by caller(main function). */
	return 0;
}
#endif
