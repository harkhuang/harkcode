public class StringMethod2 
{
	public static void main(String[] args) 
	{
		String info = " Time是吧杀 猪 刀,黑了木耳,紫了葡萄,软了香蕉,";

		boolean bool = info.isEmpty();
		if (bool)
		{
			System.out.println("空字符串!");
		}
		else
		{			
			System.out.println("非空字符串!");		
			int length = info.length();
			System.out.println("字符串长度"+length);	
			String s1 = info.toLowerCase();
			String s2 = info.toUpperCase();
			String s3 = info.trim();//从开头去掉去空格
			String s4 = info.concat("你要珍惜!!!!");
			System.out.println("s1:"+s1);
			System.out.println("s2:"+s2);
			System.out.println("s3:"+s3);
			System.out.println("s4:"+s4);

		}
	}
		
}
