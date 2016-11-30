import java.util.Arrays;

 
class MonkeyArry 
{	 
	public static void main(String[] args)
	{
		// TODO �Զ����ɵķ������
		System.out.println("show ��");
		
		
		System.out.print("-------------------------");
		MonkeyManager mm = new MonkeyManager();
		mm.add(new Monkey("���",'1'));
		mm.add(new Monkey("����",'2'));
		mm.add(new Monkey("�ú�",'3'));
		mm.add(new Monkey("⨺�",'3'));
		System.out.print("-------------------------");
		mm.del("�緹");
		mm.del("⨺�");
		mm.list();

	
		//��������Ǵ����
		//mm.find("����").print()
		// Exception in thread "main" java.lang.NullPointerException
		// ���ʵ���nullָ�����Ա���
		System.out.print("-------------------------");
		Monkey retMonkey = mm.find("����") ;
		retMonkey.print(); 

		System.out.print("-------------------------");
		Monkey m2 = new Monkey("����",'g');
		mm.update(m2);
		mm.list();

		System.out.print("-------------------------");
		mm.add(new Monkey("ˣ��",'f'));
		mm.add(new Monkey("ˣ��",'f'));
		mm.add(new Monkey("ˣ��",'f'));
		mm.add(new Monkey("ˣ��",'f'));
		mm.add(new Monkey("ˣ��",'f'));
		mm.add(new Monkey("ˣ��",'f'));
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
	public char getSex()
	{
		return sex;
	}
	public void setSex(char sex)
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
	private Monkey[] monkeys = new Monkey[5];
	private int count = 0;
	
	void add(Monkey m)
	{
		if(count < monkeys.length)
		{
			int newLen = ((monkeys.length * 3)/2) + 1;
			monkeys = (Monkey[]) Arrays.copyOf(monkeys, newLen);
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
		for(int i=0;i<count;i++)
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

				//�ҵ����һ��Ԫ��
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
		//����ȱ�ٷ������
		return null;
	}
	public Monkey  update(Monkey monkey)
	{ 
		Monkey m  = find(monkey.getName()); 
		if( m != null)
		m.setSex(monkey.getSex());
		return m;
	}
}