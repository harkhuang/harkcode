# include <stdio.h>

void main()
{
	int i, j, k;
	int m, n, p;

	i = 8;
	j = 10;
	k = 12;
    
	/* 自增在操作数之前 */
	m = ++i;
    printf("i = %d\n", i);//9
	printf("m = %d\n", m);//9

	/* 自减在操作数之后 */
	n = j--;
	printf("j = %d\n", j);	//9
	printf("n = %d\n", n);//  先将j原来的值带入赋值运算   所以  n是10  不是9

	/* 自增、自减的混合运算 */
	p = (++m)*(n++)+(--k);
	printf("k = %d\n", k);	//11
	printf("p = %d\n", p);	//102       (9+1)*(10)+11
}
