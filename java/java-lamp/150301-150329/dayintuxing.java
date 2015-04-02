public class	dayintuxing
{
	public static void main(String[] args) 
	{
		char [] cs = {'A','B','C','D','E','F','G'};
		//打印行数
		for (int i = 0;i<cs.length;i++ )
		{
			//打印每行的空格
			for(int j =i;j<cs.length-1;j++)
			{
				System.out.print(" ");
			}
			//打印每行字母
			for(int j =0;j<=i*2;j++)
			{
				System.out.print(cs[i]);
			}
			System.out.println();
		}

		//System.out.println("Hello World!");
	}
}
