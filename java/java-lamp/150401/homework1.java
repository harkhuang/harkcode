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
               System.out.println("是一个email地址:"+email);
          }
          else
          {
               System.out.println("email格式不合法 ..");
          }
          
     }
     
}
