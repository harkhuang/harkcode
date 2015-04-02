import java.util.Scanner;
/**
	求圆柱型体积
*/
public class yuanzhuti23 
{
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		System.out.println("please input high of  yuanzhuti");
		int h = input.nextInt();
		System.out.println("please input ride of yuanzhuti");
		int r = input.nextInt();

		float pi = 3.14f;
		float result = pi * r * r * h;
		System.out.println(result);
	}
}
