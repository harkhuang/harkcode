#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
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
	int shmid;
	struct score_st *ptr;
	pid_t pid;

	shmid = shmget(IPC_PRIVATE, sizeof(*ptr), 0600);
	if (shmid<0) {
		perror("shmget()");
		exit(1);
	}


	pid = fork();
	if (pid<0) {
		perror("fork()");
		exit(1);
	}

	if (pid==0) {
		ptr = shmat(shmid, NULL, 0);
		if (ptr==(void*)-1) {
			perror("shmat()");
			exit(1);
		}
		strcpy(ptr->name, "Alan");
		ptr->math = rand()%150;
		ptr->chinese = rand()%150;

		shmdt(ptr);

		exit(0);
	} else {
		wait(NULL);

		ptr = shmat(shmid, NULL, 0);
		if (ptr==(void*)-1) {
			perror("shmat()");
			exit(1);
		}
		printf("Name: %s\n", ptr->name);
		printf("Math: %d\n", ptr->math);
		printf("Chinese: %d\n", ptr->chinese);

		shmdt(ptr);

//		shmctl(shmid, IPC_RMID, NULL);

        exit(0);
	}
}

