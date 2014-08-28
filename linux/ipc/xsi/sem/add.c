#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

#define	FNAME	"/tmp/count"

#define	PROCNUM	20

static int semid;

static void p(void)
{
	struct sembuf op;

	op.sem_num = 0;
	op.sem_op = -1;
	op.sem_flg = 0;

	while (semop(semid, &op, 1)<0) {
		if (errno!=EINTR) {
			perror("semop()");
			exit(1);
		}
	}
}

static void v(void)
{
	struct sembuf op;

	op.sem_num = 0;
	op.sem_op = 1;
	op.sem_flg = 0;

	if (semop(semid, &op, 1)<0) {
		perror("semop()");
		exit(1);
	}
}

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
	p();

	fgets(linebuf, LINESIZE, fp);
	fseek(fp, 0, SEEK_SET);
	fprintf(fp, "%ld\n", atoi(linebuf)+1);
	fflush(fp);
	/* UNLOCK */
	v();

	fclose(fp);
}

int
main()
{
	int i;
	pid_t pid;

	semid = semget(IPC_PRIVATE, 1, 0600);
	if (semid<0) {
		perror("semget()");
		exit(1);
	}

	if (semctl(semid, 0, SETVAL, 1)<0) {
		perror("semctl()");
		exit(1);
	}

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

	semctl(semid, 0, IPC_RMID);
	
	return 0;
}

