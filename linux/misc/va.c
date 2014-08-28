#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void myprintf(const char *fmt, ...)
{
	va_list va;
	int i;

	va_start(va, fmt);

	for (i=0;fmt[i]!='\0';++i) {
		if (fmt[i]=='%') {
			switch (fmt[i+1]) {
				case 'd':
					printf("%d", va_arg(va, int));
					break;
				case 'f':
					printf("%f", va_arg(va, double));
					break;
				case 'c':
					putchar(va_arg(va, int));
					break;
				case 's':
					fputs(va_arg(va, char*), stdout);
					break;
				default:
					break;
			}
			++i;
		} else {
			putchar(fmt[i]);
		}
	}

	va_end(va);
}


int
main()
{
	myprintf("int=%d\tfloat=%f\tchar=%c\tstr=%s\n", 5, 6.0, 'c', "hello", NULL, 1234);

	return 0;
}

