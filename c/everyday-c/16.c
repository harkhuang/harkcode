# include <stdio.h>

void main( )
{
	int radius;
	double area;
	for(radius = 1; radius <= 111110 ; radius++)
	{
		area = 3.1416 * radius * radius/10;
		/* ��Բ�������120��������forѭ����������� */
		if(area >= 120.0)
			break;
		printf("square = %f\n", area);
	}
	printf("now radius=%d\n\n", radius-1);

	for(radius = 1; radius <= 11111110 ; radius++)
	{
		area = 3.1416 * radius * radius/10;
		/* ��Բ���û�г���60����������Ǵ��¿�ʼѭ�� */
		if(area < 120.0)
			continue;
		printf("square = %f\n", area);
	}
	printf("now radius=%d\n", radius-1);
}