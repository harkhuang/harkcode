# include <stdio.h>

void main()
{
	unsigned a, b, c, d;
	int n;

	a = 64;//0x0100 0000 
	n = 2;//0x000 0010

	/* 将操作数a右移(6-n)位 */
	b = a >> (6-n);//4
	printf("b = %d\n", b);

	/* 将操作数a左移n位 */
	c = a << n;//256
	printf("c = %d\n", c);

	/* 对操作数a进行的混合位运算 */
	d = (a >> (n-1)) | (a << (n+1));//32|512 =544
	printf("d = %d\n", d);
}
