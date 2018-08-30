#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

#include "mytbf.h"

struct mytbf_st {
	int token;
	int cps;
	int burst;
	int pos;
	pthread_mutex_t mut;
};

static struct mytbf_st *job[JOBMAX];
static pthread_mutex_t mut_job = PTHREAD_MUTEX_INITIALIZER;
static pthread_once_t init_once = PTHREAD_ONCE_INIT;
static pthread_t tid_timer;

static int get_free_pos_unlocked(void)
{
	int i;
	for (i=0;i<JOBMAX;++i) {
		if (job[i]==NULL) {
			return i;
		}
	}
	return -1;
}

static int min(int a, int b)
{
	if (a<b) {
		return a;
	}
	return b;
}

static void *thr_timer(void *un)
{
	int i;

	while (1) {
		sleep(1);
		for (i=0;i<JOBMAX;++i) {
			if (job[i]) {
				pthread_mutex_lock(&job[i]->mut);
				job[i]->token += job[i]->cps;
				if (job[i]->token > job[i]->burst) {
					job[i]->token = job[i]->burst;
				}
				pthread_mutex_unlock(&job[i]->mut);
			}
		}
		pthread_testcancel();
	}
}

static void module_unload(void)
{
	int i;

	pthread_cancel(tid_timer);
	pthread_join(tid_timer, NULL);
	for (i=0;i<JOBMAX;++i) {
		if (job[i]) {
			free(job[i]);
			job[i]=NULL;
		}
	}
}

static void module_load(void)
{
	pthread_create(&tid_timer, NULL, thr_timer, NULL);
	/* if err */
	atexit(module_unload);
}

int mytbf_new(mytbf_t**ptr, int cps, int burst)
{
	struct mytbf_st *self;
	int pos;

	pthread_once(&init_once, module_load);

	self = malloc(sizeof(*self));
	if (self==NULL) {
		return errno;
	}

	self->token = 0;
	self->cps = cps;
	self->burst = burst;

	pthread_mutex_lock(&mut_job);
	pos = get_free_pos_unlocked();
	if (pos<0) {
		pthread_mutex_unlock(&mut_job);
		free(self);
		return EBUSY;
	}

	self->pos = pos;

	job[pos] = self;
	pthread_mutex_init(&self->mut, NULL);

	pthread_mutex_unlock(&mut_job);

	*ptr = self;

	return 0;
}

int mytbf_delete(mytbf_t *ptr)
{
	struct mytbf_st *self=ptr;

	pthread_mutex_destroy(&self->mut);
	job[self->pos] = NULL;

	free(ptr);

	return 0;
}

int mytbf_fetchtoken(mytbf_t *ptr, int n)
{
	struct mytbf_st *self=ptr;
	int ret;

	pthread_mutex_lock(&self->mut);
	while (self->token<=0) {
		pthread_mutex_unlock(&self->mut);
		pthread_mutex_lock(&self->mut);
	}
	ret = min(n, self->token);

	self->token -= ret;
	pthread_mutex_unlock(&self->mut);

	return ret;
}

