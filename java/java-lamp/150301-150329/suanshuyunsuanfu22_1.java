public class suanshuyunsuanfu22_1
{
	public static void main(String[] args) 
	{
		int a = 10;
		int b = 5;
		int c = ++a;
		int d = b--;
		int e = ++a - b--;
		System.out.println("a="+a);//12
		System.out.println("b="+b);//3
		System.out.println("c="+c);//11
		System.out.println("d="+d);//4
		System.out.println("e="+e);//12 - 4 =8// 输出结果是字符串  所以用  ""+e 都是字符串 相加而已
	}
}
