public class StringMethod2 
{
	public static void main(String[] args) 
	{
		String info = " Time�ǰ�ɱ �� ��,����ľ��,��������,�����㽶,";

		boolean bool = info.isEmpty();
		if (bool)
		{
			System.out.println("���ַ���!");
		}
		else
		{			
			System.out.println("�ǿ��ַ���!");		
			int length = info.length();
			System.out.println("�ַ�������"+length);	
			String s1 = info.toLowerCase();
			String s2 = info.toUpperCase();
			String s3 = info.trim();//�ӿ�ͷȥ��ȥ�ո�
			String s4 = info.concat("��Ҫ��ϧ!!!!");
			System.out.println("s1:"+s1);
			System.out.println("s2:"+s2);
			System.out.println("s3:"+s3);
			System.out.println("s4:"+s4);

		}
	}
		
}
