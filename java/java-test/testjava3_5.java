public class testjava3_5
{
	public static void main(String args[])
	{
		int x = java.lang.Integer.MAX_VALUE;

		System.out.println("x="+x);

		System.out.println("x+1"+(x+1));
		System.out.println("x+1"+(x+2L));
		System.out.println("x+1"+((long)x+1));
	}
}
