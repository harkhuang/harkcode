#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define	FNAME	"/tmp/count"

#define	PROCNUM	20

#define	LINESIZE	100
static void *add(void *ptr)
{
	FILE *fp;
	char linebuf[LINESIZE];

	fp = fopen(FNAME, "r+");
	if (fp==NULL) {
		perror("fopen()");
		exit(1);
	}

	/* LOCK */
	lockf(fileno(fp), F_LOCK, 0);

	fgets(linebuf, LINESIZE, fp);
	fseek(fp, 0, SEEK_SET);
	fprintf(fp, "%ld\n", atoi(linebuf)+1);
	fseek(fp, 0, SEEK_SET);
	fflush(fp);
	/* UNLOCK */
	lockf(fileno(fp), F_ULOCK, 0);

	fclose(fp);
}

int
main()
{
	int i;
	pid_t pid;

	for (i=0;i<PROCNUM;++i) {
		pid = fork();
		if (pid<0) {
			perror("fork()");
			exit(1);
		}
		if (pid==0) {
			add(NULL);
			exit(0);
		}
	}

	for (i=0;i<PROCNUM;++i) {
		wait(NULL);
	}

	return 0;
}

