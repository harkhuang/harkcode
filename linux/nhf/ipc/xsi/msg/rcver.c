#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#include "proto.h"

int
main()
{
	key_t key;
	int msgid;
	struct score_st score;

	key = ftok(KEYPATH, KEYPROJ);
	if (key<0) {
		perror("ftok()");
		exit(1);
	}

	msgid = msgget(key, IPC_CREAT|0600);
	if (msgid<0) {
		perror("msgget()");
		exit(1);
	}

	while (1) {
		if (msgrcv(msgid, &score, sizeof(score)-sizeof(long), 2, 0)<0) {
			perror("msgsnd()");
			exit(1);
		}
		printf("Name: %s\n", score.name);
		printf("Math: %d\n", score.math);
		printf("Chinese: %d\n", score.chinese);
		printf("==============\n");
	}

	msgctl(msgid, IPC_RMID, NULL);

	return 0;
}

