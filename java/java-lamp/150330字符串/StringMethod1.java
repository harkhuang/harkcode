public class StringMethod1 
{
	public static void main(String[] args) 
	{
		String info = "��椾�����ʺ,��ʱ���Ѿ���Ŭ���˳�����ȴ��ʺ";
		boolean b1 = info.contains("ƨ");
		if(b1)
		System.out.println("contains(\"ƨ\"):��ʺ");
		else
		System.out.println("contains(\"ƨ\"): ƨ,ûʺ");

		int index = info.indexOf("ʺ");
		System.out.println("indexOf() :"+index);

		int indexlast  = info.lastIndexOf("ʺ");
		System.out.println("lastIndexOf() :"+indexlast);
	}
}
