class test61 
{	 
	public static void main(String[] args)
	{
		// TODO �Զ����ɵķ������
		System.out.println("show ��");
		MonkeyManager mm = new MonkeyManager();
		mm.add(new Monkey("���",'F'));
		mm.add(new Monkey("�緹",'F'));
		mm.add(new Monkey("����",'F'));
		mm.list();
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
	// ����һ������   ��ηǳ�����Ҫ  ���ĵĶ���monkeys������
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
			System.out.print("��������");
		}
	}
	void list()
	{
		for(int i=0;i<monkeys.length;i++)
		{
			//���������   ��ôֻ�е�ַ��������� ����������ǵ�ַ
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
			}
		}
	}
}