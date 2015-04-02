import java.util.Scanner;


//交换数据


public  class  swap
{
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		System.out.println("请输入第一个数a:");
		int a = input.nextInt();
		System.out.println("请输入第二个数");
		int b = input.nextInt();
		System.out.println("你输入的第一个数a=:"+a+",你输入的第二个数是b="+b);
		System.out.println("a= "+a+ '\n'+ "b ="+b+ '\n' +'\n');
		int c = a;
		a = b;
		b = c;
		System.out.println("a= "+a+ '\n'+ "b ="+b+ '\n' );

	}
}
