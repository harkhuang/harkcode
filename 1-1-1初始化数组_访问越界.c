#include<stdio.h>

int main()
{
	int arr[4];
	int i;
	
	int fool = 4;
	//����ǳ���Ȥ����  ���  Խ�� �ĸ� int  �����ݴ�  Խ�������ͽ�����ѭ��
	//��  fool<4  ��������  4<fool<8�������Ż�Խ��   fool>8���ʱ�����δ�Ż����ڴ�
	for(i=0; i<=fool; i++)
	{
		arr[i] = 0;
		printf("%d\n",arr[i]);
	}
	return 0;
}
