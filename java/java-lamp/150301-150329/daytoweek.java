import java.util.Scanner;

class  daytoweek
{
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		System.out.println("����������");
		int days = input.nextInt();
		int week = days/7;
		int day = days%7;
		System.out.println("���������"+days+"��"+week+"��,"+"��"+day+"��");

	}
}
