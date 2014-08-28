/* Countdown program. */
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>

void main(int argc, char* argv[])
{

	int a;
	a=atoi(argv[1]);
	printf("%d\n",a);
	for(argc;argc--; argc>0)
			a=atoi(argv[argc]),
			printf("%d\n", a);

	putchar('\a');    /* ½«²úÉú·äÃù */
	printf("Down");

	return;
}