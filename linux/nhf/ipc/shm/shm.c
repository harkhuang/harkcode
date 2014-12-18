#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define	NAMESIZE	32
struct score_st {
	char name[NAMESIZE];
	int math, chinese;
};

int
main()
{
	struct score_st *ptr;
	pid_t pid;

	ptr = mmap(NULL, sizeof(*ptr), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
	if (ptr==MAP_FAILED) {
		perror("mmap()");
		exit(1);
	}

	pid = fork();
	if (pid<0) {
		perror("fork()");
		exit(1);
	}

	if (pid==0) {
		strcpy(ptr->name, "Alan");
		ptr->math = rand()%150;
		ptr->chinese = rand()%150;

		munmap(ptr, sizeof(*ptr));

		exit(0);
	} else {
		wait(NULL);

		printf("Name: %s\n", ptr->name);
		printf("Math: %d\n", ptr->math);
		printf("Chinese: %d\n", ptr->chinese);

		munmap(ptr, sizeof(*ptr));

        exit(0);
	}
}
