public class homework2
{
     //public void static  main(String[] args)
     public static void  main(String[] args)
     {
          String info = "����:hark|�Ա�:��|����:��һ�ɶҲû����...";
          //Stirng s1 = info.spilt("\\|");
		  String[] s1 = info.split("\\|");//����б�ܱ������Ҫת��,������Ҫ����б��
		  for (int i=0 ;i<s1.length;i++)
          {
               System.out.println(s1[i]);
          }
     }
     
}

