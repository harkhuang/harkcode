#include<stdio.h>
#include<string.h>
void mystrcmp(char *a,char *b);
void mystrrev(char *a,int length);
void mystrupr(char *pa);
 void mystrlwr(char *pa);
 void mystrncat(char *pa,char *pb,int len);
int main()
{
	char a[50]="BiosBCX";
	char b[50]="BioaB";
	int c=strlen(a);
	mystrcmp(a,b);
	mystrupr(a);
	mystrlwr(a);
	mystrrev(a,c);
	mystrncat(a,b,3);
	getchar();
}
void mystrcmp(char *a,char *b)/*ʵ��strcmp()����*/
{
      char *pa=a;
      char *pb=b;
      int num;
      while(*pa==*pb&&(*pa)!='\0')
      {
      	pa++;
      	pb++;
      }
        if(*pa=='\0'&&*pb=='\0')
         printf("�����ַ������");
         else if(*pa>*pb)
     	printf("��һ���ַ�����");
         else
	     printf("�ڶ����ַ�����");
      	
}
void mystrrev(char *a,int length)/*ʵ��strrev()����*/
{
	char *pa=a;
	for(int i=0; i<(length/2); i++)
	{
		char ch=pa[length-i-1];
	    pa[length-1-i]=pa[i];
	    pa[i]=ch;
	}
	printf("%s",pa);
}	
 void mystrupr(char *pa)/*ʵ��strupr()����*/
 {
 	while(*pa!='\0')
 	{
 	if (*pa>='a'&&*pa<='b')
 	{
       *pa=*pa-32;
       pa++;
 	}
 	}
 	printf("%s",pa);
 }
 void mystrlwr(char *pa)/*ʵ��strlwr()����*/
 {
 		while(*pa!='\0')
 	{
 	if (*pa>='A'&&*pa<='Z')
 	{
       *pa=*pa+32;
       pa++;
 	}
 	}
 	printf("%s",pa);
 }
	void mystrncat(char *pa,char *pb,int len)/*ʵ��strncat()����*/
	{
		while(*pa!='\0')
		{
			pa++;
		}
		for(int i=0;i<len;i++)
		{
			*pa=*pb;
			pa++;
			pb++;
		}
		printf("%s",pa);
	}
