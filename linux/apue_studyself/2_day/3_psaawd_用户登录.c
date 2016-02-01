#include <unistd.h>
#include "../apue.h"
#include <shadow.h>
/*用户登录的实现           注意编译的时候加-lcrypt*/
int main()
{
	char *passwd=NULL;//定义密码
	char usr[10];//定义用户名字
	char *pret = NULL;//第一个字符串指针
	struct spwd *pwd;//结构体  文件密码结构体  指针
	int ret;//返回值

	scanf("%s", usr);//root   接一个用户名子
	passwd = getpass("input usr passwd:");//123456    接一个用户密码  并且用一个字符窜指针去接 这个函数实现的是  隐藏的输入

	//usr->/etc/shadow
	pwd = getspnam(usr);//获得spwd结构体的指针

	pret = crypt(passwd, pwd->sp_pwdp);//将输入的密码以pwd->sp_pwdp的加密方式加密 返回字符串指针    pwd->sp_pwdp这是一个加密的方式  结构体中的方式

	ret = strcmp(pwd->sp_pwdp, pret);//用ret去接比较后的密码
	printf("ret=%d\n", ret);


	
}




