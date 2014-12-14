#include <stdio.h>
#include <getopt.h>
char *l_opt_arg;
char* const short_options = "nbl:";//???
struct option long_options[] = {
{ "name",     0,   NULL,    'n'     },
{ "bf_name",  0,   NULL,    'b'     },
{ "love",     1,   NULL,    'l'     },//第二个参数1表示选项后面要跟参数   -l   forever  
{      0,     0,     0,     0},
};
int main(int argc, char *argv[])
{
	int c;
	while((c = getopt_long (argc, argv, short_options, long_options, NULL)) != -1)
	{
		switch (c)
		{
			case 'n':
			printf("My name is XL.\n");
			break;
			case 'b':
			printf("His name is ST.\n");
			break;
			case 'l':
			l_opt_arg = optarg;//当处理一个带参数的选项时，全局变量optarg会指向它的参数.
			printf("Our love is %s!\n", l_opt_arg);
			break;
		}
	}
return 0;
}
