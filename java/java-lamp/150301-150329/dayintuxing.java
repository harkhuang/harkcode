public class	dayintuxing
{
	public static void main(String[] args) 
	{
		char [] cs = {'A','B','C','D','E','F','G'};
		//��ӡ����
		for (int i = 0;i<cs.length;i++ )
		{
			//��ӡÿ�еĿո�
			for(int j =i;j<cs.length-1;j++)
			{
				System.out.print(" ");
			}
			//��ӡÿ����ĸ
			for(int j =0;j<=i*2;j++)
			{
				System.out.print(cs[i]);
			}
			System.out.println();
		}

		//System.out.println("Hello World!");
	}
}
