public class homework1
{
     public  static void main(String[] args)
     {
          String email = "shiyanhk@qq.com";
          boolean flag;
          int at = email.indexOf('@');          
          int point = email.lastIndexOf('.');
          
          if(at > 0 && at < point)
          {
               System.out.println("��һ��email��ַ:"+email);
          }
          else
          {
               System.out.println("email��ʽ���Ϸ� ..");
          }
          
     }
     
}
