public class getthemax  
{
	public static void main(String[] args) 
	{
		int []num = {22,14,23,1,51115,65,60};
		int max = 0;
		int min = 0;
		for (int i = 0;i< num.length ;i++ )
		{			
			if (num[i] > max)
			{
				max = num[i];
			}
			
		}
		for (int i = 0;i< num.length ;i++ )
		{
			
			if (num[i] < min)
			{
				min = num[i];
			}
			
		}
		System.out.println("min:"+min);
		System.out.println("max:"+max);
	}
}
