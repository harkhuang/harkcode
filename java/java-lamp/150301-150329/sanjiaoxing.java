import java.util.Scanner;
public class sanjiaoxing 
{
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		int []sum = {1,2,4,5,6,7,8};
		System.out.println("猜数游戏开始:");
		System.out.println("请输入第一个数字:");

		int value = input.nextInt();
		boolean flag = false;
		for (int i= 0;i<sum.length ;i++ )
		{
			if(sum[i]==value)
			{	
				flag = true;
				break;
			}	
		}

		if(flag)
		{
			System.out.println("恭喜,,猜对了!");
		}
		else 
		{
			System.out.println("Sorry,猜错了");
		}
	}
}
