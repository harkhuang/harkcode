# include <stdio.h>
	
void main()
{
		int x1, x2, x3, mid;
		printf("请任意输入三个整数：\n");
		scanf("%d %d %d", &x1, &x2, &x3);

		if(x1 < x2)
		{
			mid = x1; x1 = x2; x2 = mid; 
		}//让x y互换位置
		if(x1 < x3)
		{
			mid = x1; x1 = x3; x3 = mid; 
		}//让 x  z  互换位置
		if(x2 < x3)
		{
			mid = x2; x2 = x3; x3 = mid; 
		}//让  y  z 互换位置
		printf("%d %d %d\n",x1,x2,x3);//由大到小排列   如果x1不小于x2和x3的时候就不换位置
		printf("请输入一个整数，程序根据其正负判断输出：\n");
		//scanf("%d", &dec);
		//if(dec >= 0)	
		printf("最大整数为：%d\n", x1);
		//else	
		printf("最小整数为：%d\n", x3);
}

