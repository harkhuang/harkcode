#ifndef MYQUEUE_H
#define MYQUEUE_H

#define	QSZ_MAX	4096

typedef	struct {
	int datasize;
} queue_t;

int queue_init(queue_t **, int n);
int queue_destroy(queue_t *);

int queue_opreg(queue_t *, int);
int queue_opunreg(queue_t *, int);

ssize_t queue_enq(queue_t *, const char *buf, size_t size);
ssize_t queue_deq(queue_t *, char *buf, size_t size);

//int queue_count(queue_t *);

#endif

