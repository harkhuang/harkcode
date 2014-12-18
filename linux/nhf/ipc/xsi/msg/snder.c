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

	msgid = msgget(key, 0);
	if (msgid<0) {
		perror("msgget()");
		exit(1);
	}

	strcpy(score.name, "Alan");
	score.math = rand()%150;
	score.chinese = rand()%150;

	score.mtype = 2;

	if (msgsnd(msgid, &score, sizeof(score)-sizeof(long), 0)<0) {
		perror("msgsnd()");
		exit(1);
	}

	return 0;
}

