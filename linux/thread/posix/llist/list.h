#ifndef MY_LIST_H_
#define MY_LIST_H_

typedef void LLIST;

typedef void llist_op(void *);
typedef int llist_cmp(const void *,const void *);


LLIST *llist_create(int);

int llist_insert(LLIST *,const void *,int mode);

void llist_travel(LLIST *,llist_op *op);
				
int llist_delete(LLIST *,const void *,llist_cmp *);

void llist_destroy(LLIST *);


#endif










