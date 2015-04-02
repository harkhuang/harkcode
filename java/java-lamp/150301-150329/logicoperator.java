public class  logicoperator
{
	public static void main(String[] args) 
	{

		int a = 1,b = 2;
		System.out.println(a & b);//
		System.out.println(a | b);
		System.out.println(a ^ b);
		//System.out.println(a && b);
		//System.out.println(!b);
		System.out.println((a>b) || (a<b));

		int x[];
		int []y = new int [3];
		int []z = new int []{3,4,5};
		int []p = {1,2,3,4};
		System.out.println(p.length+p[1]);

		//数组使用的两个问题
		String[] names = null;
		
		System.out.println(names[0]);//空指针异常
		System.out.println(names);//输出是null
	}
}
