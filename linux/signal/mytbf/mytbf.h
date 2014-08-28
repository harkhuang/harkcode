#ifndef MYTBF_H
#define MYTBF_H

#define	JOBMAX	1024

typedef void mytbf_t;

int mytbf_new(mytbf_t**, int cps, int burst);
int mytbf_delete(mytbf_t*);

int mytbf_fetchtoken(mytbf_t*, int n);

#endif

