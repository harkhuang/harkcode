#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

#include "mysem.h"

struct mysem_st {
	int value;
	pthread_mutex_t mut;
	pthread_cond_t cond;
};

int mysem_init(mysem_t **ptr, int n)
{
	struct mysem_st *self;

	self = malloc(sizeof(*self));
	if (self==NULL) {
		return -errno;
	}
	self->value = n;
	pthread_mutex_init(&self->mut, NULL);
	pthread_cond_init(&self->cond, NULL);

	*ptr = self;

	return 0;
}

int mysem_destroy(mysem_t *ptr)
{
	struct mysem_st *self=ptr;

	pthread_mutex_destroy(&self->mut);
	pthread_cond_destroy(&self->cond);
	free(ptr);

	return 0;
}

int mysem_add(mysem_t *ptr, int n)
{
	struct mysem_st *self=ptr;

	pthread_mutex_lock(&self->mut);
	self->value += n;
	pthread_cond_broadcast(&self->cond);
	pthread_mutex_unlock(&self->mut);

	return 0;
}

int mysem_sub(mysem_t *ptr, int n)
{
    struct mysem_st *self=ptr;

    pthread_mutex_lock(&self->mut);
	while (self->value < n) {
		pthread_cond_wait(&self->cond, &self->mut);
	}
    self->value -= n;
    pthread_mutex_unlock(&self->mut);

    return 0;
}

int mysem_getvalue(mysem_t *ptr)
{
	int ret;
    struct mysem_st *self=ptr;

    pthread_mutex_lock(&self->mut);
    ret = self->value;
    pthread_mutex_unlock(&self->mut);

    return ret;
}
