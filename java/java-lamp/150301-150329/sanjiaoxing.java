import java.util.Scanner;
public class sanjiaoxing 
{
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		int []sum = {1,2,4,5,6,7,8};
		System.out.println("������Ϸ��ʼ:");
		System.out.println("�������һ������:");

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
			System.out.println("��ϲ,,�¶���!");
		}
		else 
		{
			System.out.println("Sorry,�´���");
		}
	}
}
