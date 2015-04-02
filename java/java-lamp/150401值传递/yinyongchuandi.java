public class yinyongchuandi
{
     public static void  main(String[] args)
     {
		Cat c =new Cat();
		method(c);
		System.out.println("Cat age="+c.age );
	 }
     public static  void method(Cat cat)
     {
          cat.age = 5;
     }
}

class Cat 
{
	int age = 2;
}