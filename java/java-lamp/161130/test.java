class  test
{
	public static void main(String[] args) 
	{
		Student sdt = new Student();
		sdt.func1();
		sdt.func2();//子类没有的方法默认去调用父类
		sdt.func3();
		sdt.func4();
/*
		Person per = new Student();
		per.func1();
		per.func2();//子类没有的方法默认去调用父类
		per.func4();
		//父类不可以调用子类独有的方法
		//per.func3();
	
 */
	} 

	static class  Person
	{
		public void func1()
		{
			System.out.println(" 父类方法1 ");
		}
		public void func2()
		{
			System.out.println(" 父类方法2 ");
		}

		//父类独有可以被子类调用
		public void func4()
		{
			System.out.println(" 父类方法4 ");
		}
		public  void funcInter()
		{
			System.out.println(" 父类方法2 ");
		}
	}


	//这里的class是
	static  class Student extends Person
	{
		public void func1()
		{
			System.out.println(" 子类方法1 ");
		}
		public void func3()
		{
			System.out.println(" 子类方法2 ");
		}
		public void funcSon()
		{
			System.out.println(" 父类方法 funcFather ");
		}
	}
}
		
