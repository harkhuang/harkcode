public class  StringMethod
{
	public static void main(String[] args) 
	{
		String info = "���ž�����,ʱ�����,���ܿ�����";
		String[] value = info.split(",");
		for (String s:value)
		{
			System.out.println(s);
		}
		value = info.split(",",5);
		int i = 0;
		for (String s:value)
		{
			i++;
			System.out.print(i);
			System.out.println(s);
		}
	}
}
