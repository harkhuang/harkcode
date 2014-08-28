#ifndef MYSEM_H
#define MYSEM_H

typedef	void	mysem_t;

int mysem_init(mysem_t**, int);
int mysem_destroy(mysem_t*);

int mysem_add(mysem_t*, int n);
int mysem_sub(mysem_t*, int n);

int mysem_getvalue(mysem_t*);

#endif

