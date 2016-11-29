class test61 
{	 
	public static void main(String[] args)
	{
		// TODO 自动生成的方法存根
		System.out.println("show 类");
		MonkeyManager mm = new MonkeyManager();
		mm.add(new Monkey("悟空",'1'));
		mm.add(new Monkey("妖猴",'2'));
		mm.add(new Monkey("泼猴",'3'));
		mm.add(new Monkey("猕猴",'3'));
		//mm.del("午饭");
		mm.del("猕猴");
		mm.list();


		//这个方法是错误的
		//mm.find("猴子").print()

		// Exception in thread "main" java.lang.NullPointerException
		// 访问的是null指针所以报错
		Monkey retMonkey = mm.find("猕猴") ;
		retMonkey.print();
	}
}


 
class Monkey
{
	private String name;
	private char sex;
	public Monkey(String name, char sex)
	{
		this.name = name;
		this.sex = sex;
	}
	public void setName(String name )
	{
		this.name = name;
	}
	public String getName()
	{
		return name;
	}
	public void setName(char sex)
	{
		this.sex =  sex;
	}
	public void print()
	{
		System.out.print(name);
		System.out.print("  ");
		System.out.println(sex);
	}
}

class MonkeyManager
{
	// 定义一个数组   这段非常的重要  核心的都在monkeys上面了
	private Monkey[] monkeys = new Monkey[3];
	private int count = 0;
	
	void add(Monkey m)
	{
		if(count < monkeys.length)
		{
			monkeys[count] = m;
			count++;
		}
		else
		{
			System.out.print("数组满了");
		}
	}
	void list()
	{
		for(int i=0;i<count;i++)
		{
			//输出的是类   那么只有地址是有意义的 所以输出的是地址
			System.out.println(monkeys[i]);
			monkeys[i].print();
		}
	}
	public void del(String name)
	{
		for(int i=0;i<count;i++)
		{
			if(monkeys[i].getName().equals(name))
			{
				for(int j=i;j<count-1;j++)
				{
					monkeys[j]=monkeys[j+1];
				}

				//找到最后一个元素
				monkeys[count-1] = null;
				count--;
				break;
			}
		}
	}
	public Monkey  find(String name)
	{
		for(int i=0;i<count;i++)
		{
			if(monkeys[i].getName().equals(name))
			{
				return monkeys[i];
			}
		}

		//报错缺少返回语句
		return null;
	}
	public Monkey  update(String name)
	{
		Monkey m  = find(monkey.getName());
		if(m!=null)
		{
			m.setSex('x');
		}
	}
}