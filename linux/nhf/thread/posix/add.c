#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define	FNAME	"/tmp/count"

#define	THRNUM	20

#define	LINESIZE	100
static void *add(void *ptr)
{
	char *fname = ptr;
	FILE *fp;
	char linebuf[LINESIZE];

	fp = fopen(fname, "r+");
	if (fp==NULL) {
		perror("fopen()");
		exit(1);
	}

	fgets(linebuf, LINESIZE, fp);

	fseek(fp, 0, SEEK_SET);

	fprintf(fp, "%ld\n", atoi(linebuf)+1);

	fclose(fp);
}

int
main()
{
	pthread_t tid[THRNUM];
	int i, err;

	for (i=0;i<THRNUM;++i) {
		err = pthread_create(tid+i, NULL, add, FNAME);
		if (err) {
			fprintf(stderr, "pthread_create(): %s\n", strerror(err));
			exit(1);
		}
	}

	for (i=0;i<THRNUM;++i) {
		pthread_join(tid[i], NULL);
	}

	return 0;
}

