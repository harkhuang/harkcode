#include <stdio.h>
#include "llist.h"
#define NAMESIZE 32

struct score
{
	int id;
	char name[NAMESIZE];
	int math;
};

static void print_s(void *data)
{
	struct score *d = data;
	printf("%d %s %d\n",d->id,d->name,d->math);
}

static int id_cmp(const void *key,const void *record)
{
	const int *k = key;
	const struct score *r = record;
	return (*k - r->id);
}

static int name_cmp(const void *key,const void *record)
{
	const char *k = key;
	const struct score *r = record;
	return strcmp(k,r->name);
}

int main()
{
	struct score tmp,*datap;
	int i,id,ret;
	char name[] = "sstu1";
	LLIST *handle;

	handle = llist_create(sizeof(struct score));
	if(handle == NULL)
		return -1;

	for(i = 0; i < 6 ;i++)
	{
		tmp.id = i;
		tmp.math = 100-i;
		snprintf(tmp.name,NAMESIZE,"stu%d",i);

		llist_insert(handle,&tmp,LLIST_BACKWARD);
		
	}
	
	llist_travel(handle,print_s);
	printf("\n\n");
	id = 3;

	ret = llist_fetch(handle,&id,id_cmp,&tmp);
	if(ret != -1)
		print_s(&tmp);
	printf("\n\n");
	llist_travel(handle,print_s);

	llist_destroy(handle);

//	llist_delete(handle,&id,id_cmp);
//	llist_travel(handle,print_s);


#if 0	
//	datap = llist_find(handle,&id,id_cmp);
	datap = llist_find(handle,name,name_cmp);
	if(datap == NULL)
		printf("can not find!\n");
	else
		print_s(datap);
#endif


	return 0;
}
