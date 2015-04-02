import java.util.Scanner;

class  daytoweek
{
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		System.out.println("请输入天数");
		int days = input.nextInt();
		int week = days/7;
		int day = days%7;
		System.out.println("输入的天数"+days+"共"+week+"周,"+"零"+day+"天");

	}
}
