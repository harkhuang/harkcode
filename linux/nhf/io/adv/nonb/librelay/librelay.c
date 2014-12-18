#include <stdio.h>

#include "librelay.h"

enum {
	ST_R=1,
	ST_W,
	ST_Ex,
	ST_T
};

#define	BUFSIZE	1024
struct fsa_relay_st {
	int state;
	int sfd, dfd;
	char buf[BUFSIZE];
	int len, pos;
	char *errstr;
	int64_t count;
};

struct relay_job_st {
	int fd1, fd2;
	int fd1_saveflag, fd2_saveflag;
	struct fsa_relay_st fsa12, fsa21;
	int state;
	time_t start, end;
	pthread_mutex_t  mut;
	pthread_cond_t	cond;
};

static struct relay_job_st *job[RELAY_JOBMAX];
static pthread_mutex_t	mut_job = PTHREAD_MUTEX_INITIALIZER;

static pthread_t tid_driver;
static pthread_once_t	init_once = PTHREAD_ONCE_INIT;

static void fsa_driver(struct fsa_relay_st *fsa)
{
	int ret;

	switch (fsa->state) {
		case ST_R:
			fsa->len = read(fsa->sfd, fsa->buf, BUFSIZE);
			if (fsa->len==0) {
				fsa->state = ST_T;
			} else if (fsa->len<0) {
				if (errno==EAGAIN) {
					/* Do nothing */
				} else {
					fsa->errstr = "read(sfd)";
					fsa->state = ST_Ex;
				}
			} else {
				fsa->pos = 0;
				fsa->state = ST_W;
			}
			break;
		case ST_W:
			ret = write(fsa->dfd, fsa->buf+fsa->pos, fsa->len);
			if (ret<0) {
				if (errno==EAGAIN) {
					/* Do nothing */
				} else {
					fsa->errstr = "write(dfd)";
					fsa->state = ST_Ex;
				}
			} else {
				fsa->pos += ret;
				fsa->len -= ret;
				fsa->count += ret;
				if (fsa->len>0) {
					/* Do nothing */
				} else {
					fsa->state = ST_R;
				}
			}
			break;
		case ST_Ex:
			perror(fsa->errstr);
			fsa->state = ST_T;
			break;
		case ST_T:
			/* Do nothing */
			break;
		default:
			raise(SIGABRT);
			break;
	}
}

static void *thr_relayer(void *unused)
{
	int i;

	while (1) {
		for (i=0;i<REL_JOBMAX;++i) {
			pthread_mutex_lock(&mut_job);
			if (job[i]) {
				if (pthread_mutex_trylock(&job[i]->mut)==0) {
					if (job[i]->state==STATE_RUNNING) {
						fsa_driver(&job[i]->fsa12);
						fsa_driver(&job[i]->fsa21);
						if (job[i]->fsa12.state==ST_T && job[i]->fsa21.state==ST_T) {
							job[id]->end = time(NULL);
							job[i]->state = STATE_TERMINATED;
						}
					}
					pthread_cond_broadcast(&job[i]->cond);
					pthread_mutex_unlock(&job[i]->mut);
				}
			}
			pthread_mutex_unlock(&mut_job);
		}
	}
}

static int get_free_pos_unlocked(void)
{
	int i;

	for (i=0;i<REL_JOBMAX;++i) {
		if (job[i]==NULL) {
			return i;
		}
	}
	return -1;
}

static void module_load(void)
{
	err = pthread_create(&tid_driver, NULL, thr_relayer, NULL);
	if (err) {
		perror("");
		exit(1):
	}
}

int relay_addjob(int fd1, int fd2)
{
	int pos;
	struct relay_job_st *self;

	pthread_once(&init_once, mudule_load);

	self = malloc(sizeof(*self));

	self->fd1 = fd1;
	self->fd2 = fd2;
	self->state = STATE_RUNNING;
	self->fd1_saveflag = fcntl(fd1, F_GETFL);
	fcntl(fd1, F_SETFL, self->fd1_saveflag|O_NONBLOCK);
	self->fd2_saveflag = fcntl(fd2, F_GETFL);
	fcntl(fd2, F_SETFL, self->fd2_saveflag|O_NONBLOCK);
	self->start = time(NULL);
	self->end = -1;
	pthread_mutex_init(&self->mut, NULL);
	pthread_cond_init(&self->cond, NULL);

	self->fsa12.sfd = fd1;
	self->fsa12.dfd = fd2;
	self->fsa12.state = ST_R;
	self->fsa21.sfd = fd2;
	self->fsa21.dfd = fd1;
	self->fsa21.state = ST_R;

	pthread_mutex_lock(&mut_job);
	pos = get_free_pos_unlocked();
	job[pos]=self;
	pthread_mutex_unlock(&mut_job);

	return pos;
}

int relay_canceljob(int id)
{
	pthread_once(&init_once, mudule_load);

	if () {
	}

	pthread_mutex_lock(&job[id]->mut);
	if (job[id]->state != STATE_RUNNING) {
		pthread_mutex_unlock(&job[id]->mut);
		return -errno;
	}
	job[id]->state = STATE_CANCELED;
	job[id]->end = time(NULL);
	pthread_cond_broadcast(&job[id]->cond);
	pthread_mutex_unlock(&job[id]->mut);
}

int relay_statjob(int id, struct relay_jobstat_st *res)
{
	pthread_once(&init_once, mudule_load);

	if () {
	}

	pthread_mutex_lock(&job[id]->mut);
	res->fd1 = job[id]->fd1;
	res->fd2 = job[id]->fd2;
	res->count12 = job[id]->fsa12.count;
	res->count21 = job[id]->fsa21.count;
	res->start = job[id]->start;
	res->end = job[id]->end;
	res->state = job[id]->state;
	pthread_mutex_unlock(&job[id]->mut);

	return 0;
}


int relay_waitjob(int id, struct relay_jobstat_st *res)
{
	pthread_once(&init_once, mudule_load);

	if () {
	}

	pthread_mutex_lock(&job[id]->mut);
	while (job[id]->state == STATE_RUNNING) {
		pthread_cond_wait(&job[id]->cond, &job[id]->mut);
	}
	res->fd1 = job[id]->fd1;
	res->fd2 = job[id]->fd2;
	res->count12 = job[id]->fsa12.count;
	res->count21 = job[id]->fsa21.count;
	res->start = job[id]->start;
	res->end = job[id]->end;
	res->state = job[id]->state;
	pthread_mutex_unlock(&job[id]->mut);

	pthread_mutex_lock(&mut_job);
	pthread_mutex_destroy(&job[id]->mut);
	pthread_cond_destroy(&job[id]->cond);
	fcntl(job[id]->fd1, F_SETFL, job[id]->fd1_saveflag);
	fcntl(job[id]->fd2, F_SETFL, job[id]->fd2_saveflag);
	free(job[id]);
	job[id]=NULL;
	pthread_mutex_unlock(&mut_job);

	return 0;

}

