/*public class BubbleSort
{
     public static void main(String[] args)
     {
         int score[] = {67, 69, 75, 87, 89, 90, 99, 100};
         for (int i = 0; i < score.length -1; i++)
		 {    //�����n-1������
             for(int j = 0 ;j < score.length - i - 1; j++)
		     {    //�Ե�ǰ��������score[0......length-i-1]��������(j�ķ�Χ�ܹؼ��������Χ��������С��)
                 if(score[j] < score[j + 1])
			     {    //��С��ֵ����������
                     int temp = score[j];
                     score[j] = score[j + 1];
                     score[j + 1] = temp;
                 }
             }            
             System.out.print("��" + (i + 1) + "����������");
             for(int a = 0; a < score.length; a++)
		     {
                 System.out.print(score[a] + "\t");
             }
             System.out.println("");
         }
             System.out.print("������������");
             for(int a = 0; a < score.length; a++){
                 System.out.print(score[a] + "\t");
        }
     }
 }
 */

public class BubbleSort  
{
	public static void main(String[] args) 
	{
		int []num = {1,3,5,7,9};
		System.out.print("��0����������");
		for(int a = 0; a < num.length; a++)
		{
			System.out.print(num[a] + "\t");
		}
		System.out.println("");
		//for (int i = 0; i < num.length - 1 ;i++ )
		for (int i = 0; i < num.length  -1; i++)
		{
			//for(int j = 0; j < num.length - i -1;j++)
			 for(int j = 0 ;j < num.length - i - 1; j++)
			{
				//��С����  Ϊɶ�� i����ʵ�� ��j�ſ���ʵ����
				if(num[j]< num[j+1])
				{
					// ����ֻ��j���ܶ�λ�Ƚϵ����� �� i����~~
					int temp = num[j];
					num[j] = num[j+1];
					num[j+1] = temp;
					//int temp = score[j];
					//score[j] = score[j + 1];
					//score[j + 1] = temp;
				}
				System.out.print("��" + (i + 1) + "����������");
				for(int a = 0; a < num.length; a++)
				{
					System.out.print(num[a] + "\t");
				}
				System.out.println("");
			}
		}
		 
		 for(int a = 0; a < num.length; a++)
		 {
			 System.out.print(num[a] + "\t");
		 }
		//System.out.println("Hello World!");
	}
}

