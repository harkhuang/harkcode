class  test
{
	public static void main(String[] args) 
	{
		Student sdt = new Student();
		sdt.func1();
		sdt.func2();//����û�еķ���Ĭ��ȥ���ø���
		sdt.func3();
		sdt.func4();
/*
		Person per = new Student();
		per.func1();
		per.func2();//����û�еķ���Ĭ��ȥ���ø���
		per.func4();
		//���಻���Ե���������еķ���
		//per.func3();
	
 */
	} 

	static class  Person
	{
		public void func1()
		{
			System.out.println(" ���෽��1 ");
		}
		public void func2()
		{
			System.out.println(" ���෽��2 ");
		}

		//������п��Ա��������
		public void func4()
		{
			System.out.println(" ���෽��4 ");
		}
		public  void funcInter()
		{
			System.out.println(" ���෽��2 ");
		}
	}


	//�����class��
	static  class Student extends Person
	{
		public void func1()
		{
			System.out.println(" ���෽��1 ");
		}
		public void func3()
		{
			System.out.println(" ���෽��2 ");
		}
		public void funcSon()
		{
			System.out.println(" ���෽�� funcFather ");
		}
	}
}
		
