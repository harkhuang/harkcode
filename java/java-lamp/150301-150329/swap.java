import java.util.Scanner;


//��������


public  class  swap
{
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		System.out.println("�������һ����a:");
		int a = input.nextInt();
		System.out.println("������ڶ�����");
		int b = input.nextInt();
		System.out.println("������ĵ�һ����a=:"+a+",������ĵڶ�������b="+b);
		System.out.println("a= "+a+ '\n'+ "b ="+b+ '\n' +'\n');
		int c = a;
		a = b;
		b = c;
		System.out.println("a= "+a+ '\n'+ "b ="+b+ '\n' );

	}
}
