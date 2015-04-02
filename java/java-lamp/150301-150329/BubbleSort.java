/*public class BubbleSort
{
     public static void main(String[] args)
     {
         int score[] = {67, 69, 75, 87, 89, 90, 99, 100};
         for (int i = 0; i < score.length -1; i++)
		 {    //最多做n-1趟排序
             for(int j = 0 ;j < score.length - i - 1; j++)
		     {    //对当前无序区间score[0......length-i-1]进行排序(j的范围很关键，这个范围是在逐步缩小的)
                 if(score[j] < score[j + 1])
			     {    //把小的值交换到后面
                     int temp = score[j];
                     score[j] = score[j + 1];
                     score[j + 1] = temp;
                 }
             }            
             System.out.print("第" + (i + 1) + "次排序结果：");
             for(int a = 0; a < score.length; a++)
		     {
                 System.out.print(score[a] + "\t");
             }
             System.out.println("");
         }
             System.out.print("最终排序结果：");
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
		System.out.print("第0次排序结果：");
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
				//从小到大  为啥用 i不能实现 用j才可以实现呢
				if(num[j]< num[j+1])
				{
					// 这里只有j才能定位比较的数字 而 i不能~~
					int temp = num[j];
					num[j] = num[j+1];
					num[j+1] = temp;
					//int temp = score[j];
					//score[j] = score[j + 1];
					//score[j + 1] = temp;
				}
				System.out.print("第" + (i + 1) + "次排序结果：");
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

