# include <stdio.h>

void main()
{
	int x, y, num1, num2, temp;
	printf("please  input  two  numbers:\n");
	scanf("%d %d", &num1, &num2);

	if(num1 < num2)
	{
		temp = num1;
		num1 = num2;
		num2 = temp;
	}
	x = num1;
	y = num2;
	while(y != 0)
	{
		temp = x%y;
		x = y;
		y = temp;
	}
	printf("tamende   zuida   gongyueshu:%d\n", x);
	printf("tamende  zuixiao  gongbeishu:%d\n", num1*num2/x);
}