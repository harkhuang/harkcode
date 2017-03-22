#include "apue.h"
#include <pwd.h>

int
main(void)       /* FreeBSD/Mac OS X version */
{
     struct passwd    *ptr;

     if ((ptr = getpwnam("hk")) == NULL)
         err_sys("getpwnam error");
     printf("pw_passwd = %s\n", ptr->pw_passwd == NULL ||
       ptr->pw_passwd[0] == 0 ? "(null)" : ptr->pw_passwd);
     exit(0);
}


