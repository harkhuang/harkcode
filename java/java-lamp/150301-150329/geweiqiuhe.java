
public class geweiqiuhe
{

	public static void main(String[] args) 
	{
		int num =12345;
		int gewei  = num%10;
		int shiwei = num%100/10;
		int baiwei = num%1000/100;
		int qianwei = num%10000/1000;
		int wanwei = num/10000;

		int res = gewei + shiwei + baiwei + qianwei + wanwei;

		System.out.println(res);
	}
}
