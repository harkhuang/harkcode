public class leixingzhuanhuan19_1
{
	public static void main(String[] args) 
	{
		byte b = 10;
		float f = b; //自动类型转换

		System.out.println(f);
		System.out.println("Hello World!");
		
		long g = 1000;
		int i = (int)g; //强制类型转换
		System.out.println(i);

		char c = 'a';
		int i_temp = c;
		System.out.println(i_temp);
	}
}
