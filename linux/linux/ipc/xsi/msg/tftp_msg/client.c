#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

enum {
	ST_PATH=1,
	ST_RCV,
	ST_OUTPUT,
	ST_ERR,
	ST_Ex,
	ST_T
};

struct tftp_client_fsa_st {
	int state;
	char *path;
	struct msg_c2s_st sbuf;
	struct msg_s2c_st rbuf;
	int msgid;
	int outfd;
	char *errstr;
};

static void tftp_fsa_driver(struct tftp_client_fsa_st *fsa)
{
	switch (fsa->state) {
		case ST_PATH:
			fsa->sbuf.xxx
			fsa->sbuf.xxx
			fsa->sbuf.xxx
			if (msgsnd(fsa->msgid, &fsa->sbuf, sizeof(fsa->sbuf)-sizeof(long), 0)) {
			}
	}
}

