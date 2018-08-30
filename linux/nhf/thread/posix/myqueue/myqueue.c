#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

#include	"myqueue.h"

struct myqueue_st {
	queue_t	public;
	pthread_mutex_t mut;
	pthread_cond_t cond;
	int rd_count, wr_count;
	int head, tail;
	int queuesize;
	char data[1];	/* C89 */
};

int queue_init(queue_t **ptr, int n)
{
	struct myqueue_st *self;

	self = malloc(sizeof(*self)+n-1);
	if (self==NULL) {
		return -errno;
	}

	if (n>QSZ_MAX) {
		n=QSZ_MAX;
	}

	self->public.datasize = 0;
	self->head = 0;
	self->tail = 0;
	self->queuesize = n;
	self->rd_count = 0;
	self->wr_count = 0;
	pthread_mutex_init(&self->mut, NULL);
	pthread_cond_init(&self->cond, NULL);

	*ptr = (void*)self;

	return 0;
}

int queue_destroy(queue_t *ptr)
{
	struct myqueue_st *self=(void*)ptr;

	pthread_mutex_destroy(&self->mut);
	pthread_cond_destroy(&self->cond);
	free(ptr);

	return 0;
}

int queue_opreg(queue_t *ptr, int flags)
{
	struct myqueue_st *self=(void*)ptr;

	ptread_mutex_lock(&self->mut);
	if (flags&FLG_RD) {
		self->rd_count++;
	}
	if (flags&FLG_WR) {
		self->wr_count++;
	}
	while (self->rd_count<=0 || self->wr_count<=0) {
		pthread_cond_wait(&self->cond, &self->mut);
	}
	pthread_cond_broadcast(&self->cond);
	ptread_mutex_unlock(&self->mut);
}

int queue_opunreg(queue_t *ptr, int flags)
{
	struct myqueue_st *self=(void*)ptr;

	ptread_mutex_lock(&self->mut);
	if (flags&FLG_RD) {
		self->rd_count--;
	}
	if (flags&FLG_WR) {
		self->wr_count--;
	}
	pthread_cond_broadcast(&self->cond);
	ptread_mutex_unlock(&self->mut);
}

static int next(struct myqueue_st *self, int n)
{
	if (n+1 >= self->queuesize) {
		return 0;
	}
	return n+1;
}

static int queue_enq_byte_unlocked(struct myqueue_st *self, int c)
{
	if (self->public.datasize >= self->queuesize) {
		return -1;
	}
	self->data[self->tail] = c;
	self->tail = next(self, self->tail);
	self->public.datasize++;
	return 0;
}

ssize_t queue_enq(queue_t *ptr, const char *buf, size_t size)
{
	int i;
	struct myqueue_st *self=(void*)ptr;

	pthread_mutex_lock(&self->mut);
	if (self->rd_count<=0) {
		pthread_mutex_unlock(&self->mut);
		return -EPIPE;
	}
	while (self->public.datasize>=self->queuesize && self->rd_count>0) {
		pthread_cond_wait(&self->cond, &self->mut);
	}
	if (self->rd_count<=0) {
		pthread_mutex_unlock(&self->mut);
		return -EPIPE;
	}
	for (i=0;i<size;++i) {
		if (queue_enq_byte_unlocked(self, buf[i])<0) {
			break;
		}
	}
	pthread_cond_broadcast(&self->cond);
	pthread_mutex_unlock(&self->mut);

	return i;
}

static int queue_deq_byte(struct myqueue_st *self, char *c)
{
	if (self->public.datasize <=0) {
		return -1;
	}
	*c = self->data[self->head];
	self->head = next(self, self->head);
	self->public.datasize--;
	return 0;
}

ssize_t queue_deq(queue_t *ptr, char *buf, size_t size)
{
	int i;
	struct myqueue_st *self=(void*)ptr;

	for (i=0;i<size;++i) {
		if (queue_deq_byte(self, buf+i)<0) {
			break;
		}
	}

	return i;
}

