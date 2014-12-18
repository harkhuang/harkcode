#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#include "list.h"


struct llist_node_st
{
    struct llist_node_st *prev;
    struct llist_node_st *next;
    char data[0];
};

struct llist_st
{
    int size;
	pthread_mutex_t mut;
    struct llist_node_st head;
};



//static pthread_mutex_t mut = ....;
static	pthread_mutexattr_t mattr_rec;
static 	pthread_once_t mattr_rec_initonce = PTHREAD_ONCE_INIT;

static void mattr_rec_init(void)
{
	pthread_mutexattr_init(&mattr_rec);
	pthread_mutexattr_settype(&mattr_rec, PTHREAD_MUTEX_RECURSIVE);
}

LLIST *llist_create(int size)
{
	struct llist_st *ptr;

	pthread_once(&mattr_rec_initonce, mattr_rec_init);

	ptr = malloc(sizeof(*ptr));
	if(ptr == NULL)
		return NULL;

	ptr->size = size;
	ptr->head.prev = ptr->head.next = &ptr->head;
	pthread_mutex_init(&ptr->mut, &mattr_rec)

	return ptr;
}

int llist_insert(LLIST *p,const void *data,int mode)
{
	struct llist_st *ptr=p;
	struct llist_node_st *newnode;

	newnode = malloc(sizeof(*newnode)+ptr->size);
	/*if error*/
	
	memcpy(newnode->data,data,ptr->size);

	pthread_mutex_lock();
	newnode->prev = &ptr->head;
	newnode->next = ptr->head.next;
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;
	pthread_mutex_unlock();	

	return 0;
}

static struct llist_node_st *find_unlocked(LLIST *p,const void *key,llist_cmp *cmp)
{
	struct llist_st *ptr=p;
	struct llist_node_st *cur;

	for(cur = ptr->head.next ; cur != &ptr->head ; cur = cur->next)
		if(cmp(key,cur->data) == 0)
			break;
	return cur;
}

int llist_delete(LLIST *p,const void *key,llist_cmp *cmp)
{
	struct llist_st *ptr=p;
	struct llist_node_st *node;

	/* LOCK */
	node = find_unlocked(ptr,key,cmp);
	if(node == &ptr->head)
		/* UNLOCK */
		return -1;
	
	node->prev->next = node->next;
	node->next->prev = node->prev;
	/* UNLOCK */
	
	free(node);
}

void llist_travel(LLIST *p,llist_op *op)
{
	struct llist_st *ptr=p;
	struct llist_node_st *cur;

	/* LOCK */
	for(cur = ptr->head.next ; cur != &ptr->head ; cur = cur->next)
		op(cur->data);
	/* UNLOCK */
}

void llist_destroy(LLIST *p)
{
	struct llist_st *ptr=p;
	struct llist_node_st *cur,*next;

	for(cur = ptr->head.next ; cur != &ptr->head ; cur = next)
	{
		next = cur->next;
		free(cur);
	}

}










