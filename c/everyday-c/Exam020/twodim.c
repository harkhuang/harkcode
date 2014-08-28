# include <stdio.h>

void main()
{
	int array[16][16];
	int i, j, k, m, n;
	
	/* 变量初始化 */
	m = 1;
	while(m == 1)
	{
		printf("请输入n(0<n<=15)，n是奇数)\n");
		scanf("%d", &n);
		/* 判断n是否是大于0小于等于15的奇数 */
		if((n!=0) && (n<=15) && (n%2!=0))
		{
			printf("矩阵阶数是 %d\n", n);
			m = 0;
		}
	}
	/* 数组赋初值为0 */
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			array[i][j] = 0;

	/* 建立魔方阵 */
	j = n/2 + 1;
	array[1][j] = 1;
	for(k=2; k<=n*n; k++)
	{
		i = i - 1;
		j = j + 1;
		if((i<1) && (j>n))
		{
			i = i + 2;
			j = j - 1;
		}
		else
		{
			if(i < 1)
				i = n;
			if(j > n)
				j = 1;
		}
		if(array[i][j] == 0)
			array[i][j] = k;
		else
		{
			i = i + 2;
			j = j - 1;
			array[i][j] = k;
		}
	}

	/* 输出魔方阵 */
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
			printf("%5d", array[i][j]);
		printf("\n");
	}
}