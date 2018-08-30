#include <stdio.h>
#include <time.h>

#define	BUFSIZE	1024

int
main()
{
	time_t	stamp;
	struct tm *tm;
	char buf[BUFSIZE];

	stamp = time(NULL);

	tm = localtime(&stamp);

	strftime(buf, BUFSIZE, "Now: %Y-%m-%d\n", tm);
	printf("%s", buf);

	tm->tm_mday += 200;

	(void)mktime(tm);

	strftime(buf, BUFSIZE, "After: %Y-%m-%d\n", tm);
	printf("%s", buf);

	return 0;
}

