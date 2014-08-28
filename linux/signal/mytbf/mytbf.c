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
};

static struct mytbf_st *job[JOBMAX];
static int inited = 0;
static struct sigaction alrm_save;

static int get_free_pos(void)
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

static void alrm_handler(int s, siginfo_t *infop, void *un)
{
	int i;

	if (infop->si_code != SI_KERNEL) {
		return;
	}

	alarm(1);
	for (i=0;i<JOBMAX;++i) {
		if (job[i]) {
			job[i]->token += job[i]->cps;
			if (job[i]->token > job[i]->burst) {
				job[i]->token = job[i]->burst;
			}
		}
	}
}

static void module_unload(void)
{
	int i;

	alarm(0);
//	signal(SIGALRM, alrm_save);
	sigaction(SIGALRM, &alrm_save, NULL);
	for (i=0;i<JOBMAX;++i) {
		if (job[i]) {
			free(job[i]);
			job[i]=NULL;
		}
	}
}

static void module_load(void)
{
	struct sigaction sa;

	sa.sa_sigaction = alrm_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
//	alrm_save = signal(SIGALRM, alrm_handler);
	sigaction(SIGALRM, &sa, &alrm_save);
	alarm(1);
	atexit(module_unload);
}

int mytbf_new(mytbf_t**ptr, int cps, int burst)
{
	struct mytbf_st *self;
	int pos;

	if (!inited) {
		module_load();
		inited = 1;
	}

	pos = get_free_pos();
	if (pos<0) {
		return EBUSY;
	}

	self = malloc(sizeof(*self));
	if (self==NULL) {
		return errno;
	}

	self->token = 0;
	self->cps = cps;
	self->burst = burst;
	self->pos = pos;

	job[pos] = self;
	*ptr = self;

	return 0;
}

int mytbf_delete(mytbf_t *ptr)
{
	struct mytbf_st *self=ptr;

	job[self->pos] = NULL;

	free(ptr);

	return 0;
}

int mytbf_fetchtoken(mytbf_t *ptr, int n)
{
	struct mytbf_st *self=ptr;
	int ret;

	while (self->token<=0) {
		pause();
	}
	ret = min(n, self->token);

	self->token -= ret;

	return ret;
}

