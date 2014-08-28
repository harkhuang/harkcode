#ifndef LIBRELAY_H
#define LIBRELAY_H

#define	RELAY_JOBMAX	4096

enum {
	STATE_RUNNING=1,
	STATE_CANCELED,
	STATE_TERMINATED
};

struct relay_jobstat_st {
	int fd1, fd2;
	int64_t count12, count21;
	time_t start, end;
	int state;
};

int relay_addjob(int fd1, int fd2);

int relay_canceljob(int);

int relay_statjob(int, struct relay_jobstat_st*);

int relay_waitjob(int, struct relay_jobstat_st*);

#endif

