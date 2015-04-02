public class StringMethod1 
{
	public static void main(String[] args) 
	{
		String info = "泡妞就像拉屎,有时候已经很努力了出来的却是屎";
		boolean b1 = info.contains("屁");
		if(b1)
		System.out.println("contains(\"屁\"):有屎");
		else
		System.out.println("contains(\"屁\"): 屁,没屎");

		int index = info.indexOf("屎");
		System.out.println("indexOf() :"+index);

		int indexlast  = info.lastIndexOf("屎");
		System.out.println("lastIndexOf() :"+indexlast);
	}
}
