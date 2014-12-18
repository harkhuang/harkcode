#include <stdio.h>
#include <signal.h>

#include "anytimer.h"

struct at_job_st {
	int sec;
	at_jobfunc_t *funcp;
	void *arg;
};

static struct at_job_st *job[AT_JOBMAX];

static int get_free_pos()
{
}

static void alrm_handler(int s)
{
}

static void module_unload(void)
{
}

static void module_load(void)
{
}

at_addjob(int, at_jobfunc_t*, void*)
{
	
}

