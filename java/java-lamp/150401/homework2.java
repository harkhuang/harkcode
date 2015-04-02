public class homework2
{
     //public void static  main(String[] args)
     public static void  main(String[] args)
     {
          String info = "姓名:hark|性别:男|描述:这家伙啥也没留下...";
          //Stirng s1 = info.spilt("\\|");
		  String[] s1 = info.split("\\|");//由于斜杠本身就需要转译,所以需要两个斜杠
		  for (int i=0 ;i<s1.length;i++)
          {
               System.out.println(s1[i]);
          }
     }
     
}

