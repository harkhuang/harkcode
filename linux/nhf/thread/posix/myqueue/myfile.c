#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "myqueue.h"

#define	DEFAULT_QSZ	1024

struct myfile_st {
	queue_t *queue;
	int op_flag;
};

static struct myfile_st *filedes[NOFILE];

static int get_free_pos(void);

void *myfile_creat(void)
{
	queue_t *q;

	if (queue_init(&q, DEFAULT_QSZ)) {
		return NULL;
	}
	return q;
}

int myfile_open(void *f_id, int flags)
{
	struct myfile_st *self;
	int pos;

	self = malloc();

	self->queue = f_id;
	self->op_flag = flags;

	pos = get_free_pos();

	filedes[pos] = self;

	queue_opreg(f_id, flags);

	return pos;
}

int myfile_close(int fd)
{
	queue_opunreg(filedes[fd]->queue, filedes[fd]->flags);

	free(filedes[fd]);
	filedes[fd]=NULL;
}

ssize_t myfile_write(int fd, const void *buf, size_t size)
{
	if (filedes[fd]->flags & FLG_WR) {
		return queue_deq(filedes[fd]->queue, buf, size);
	}
	return -EPERM;
}

