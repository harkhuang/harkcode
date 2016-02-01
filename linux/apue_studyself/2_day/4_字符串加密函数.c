#include <unistd.h>
#include "stdio.h"
/*字符串加密函数     crypt       */
int main()
{
	char str[]="123456";//定义一个字符串
	char *pret;//定义一个字符指针

	pret = crypt(str, "123");//以123的方式进行加密  返回值用pret去接  字符指针？？
	printf("%s\n", pret);
	pret = crypt(str, "abc");//以abc的方式对str进行加密  发挥值用pret去接  
	printf("%s\n", pret);
}
