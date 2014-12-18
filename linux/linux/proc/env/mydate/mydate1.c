#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define	BUFSIZE	1024

int
main(int argc, char **argv)
{
	time_t	stamp;
	struct tm *tm;
	char buf[BUFSIZE];
	char fmt[BUFSIZE];
	int c;

	stamp = time(NULL);

	tm = localtime(&stamp);

	fmt[0]='\0';
	while (1) {
		c = getopt(argc, argv, "h:msY:MD");
		if (c==-1) {
			break;
		}
		switch (c) {
			case 'h':
				if (strcmp(optarg, "12")==0) {
					strncat(fmt, "%I%P ", BUFSIZE);
				} else if (strcmp(optarg, "24")==0) {
					strncat(fmt, "%H ", BUFSIZE);
				} else {
					fprintf(stderr, "Invalid argument of -h\n");
				}
				break;
			case 'm':
				strncat(fmt, "%M ", BUFSIZE);
				break;
			case 's':
				strncat(fmt, "%S ", BUFSIZE);
				break;
			case 'Y':
				if (strcmp(optarg, "2")==0) {
					strncat(fmt, "%y ", BUFSIZE);
				} else if (strcmp(optarg, "4")==0) {
					strncat(fmt, "%Y ", BUFSIZE);
				} else {
					fprintf(stderr, "Invalid argument of -y\n");
				}
				break;
			case 'M':
				strncat(fmt, "%m ", BUFSIZE);
				break;
			case 'D':
				strncat(fmt, "%d ", BUFSIZE);
				break;
		}
	}

	strftime(buf, BUFSIZE, fmt, tm);
	printf("%s\n", buf);

	return 0;
}

