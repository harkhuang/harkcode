#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/mman.h>

#include "proto.h"

#define MINSPARESERVERS 5
#define MAXSPARESERVERS 10
#define MAXCLIENTS 20

#define IPSTRSIZE	40
#define LINESIZE	80

#define SIG_NOTIFY	SIGUSR2

enum {
	STATE_IDLE=0,
	STATE_BUSY
};

struct server_st {
	pid_t pid;
	int state;
	int reuse;
};

typedef struct server_st msg_t;

static struct server_st *serverpool;
static int idle_count=0, busy_count=0;
static int sd;

static void server_job(int sd, int pos);

void
usr2_handler(int s)
{
	return;
}

int
add_1_server(void)
{
	int slot;
	pid_t pid;

	if (idle_count+busy_count >= MAXCLIENTS) {
		return -1;
	}
	for (slot=0;slot<MAXCLIENTS;++slot) {
		if (serverpool[slot].pid==-1) {
			break;
		}
	}
	serverpool[slot].state = STATE_IDLE;
	pid = fork();
	if (pid<0) {
		return -1;
	}
	if (pid==0) {
		server_job(sd, slot);
		exit(0);
	} else {
		serverpool[slot].pid = pid;
		idle_count++;
	}

	return 0;
}

int
del_1_server(void)
{
	int i;

	if (idle_count == 0) {
		return -1;
	}
	for (i=0;i<MAXCLIENTS;++i) {
		if (serverpool[i].pid !=-1 && serverpool[i].state == STATE_IDLE) {
			kill(serverpool[i].pid, SIGTERM); /* FIXME: 可能有竞争BUG */
			serverpool[i].pid = -1;
			idle_count--;
			break;
		}
	}
	return 0;
}

int
scan_pool(void)
{
	int i, idle=0, busy=0;

	for (i=0;i<MAXCLIENTS;++i) {
		if (serverpool[i].pid == -1) {
			continue;
		}
		if (kill(serverpool[i].pid, 0)) {
			serverpool[i].pid = -1;
			continue;
		}
		if (serverpool[i].state == STATE_IDLE) {
			idle++;
		} else if (serverpool[i].state == STATE_BUSY) {
			busy++;
		} else {
			fprintf(stderr, "Unknown state.\n");
			abort();
		}
	}
	idle_count=idle; busy_count=busy;
	return 0;
}

static void server_job(int sd, int pos)
{
	int client_sd;
	struct sockaddr_in peer_addr;
	socklen_t peer_addr_len;
	char ipstr[IPSTRSIZE];
	time_t stamp;
	char linebuf[LINESIZE];
	int len;
	pid_t ppid;

	ppid = getppid();

	peer_addr_len = sizeof(peer_addr);
	while (1) {
		serverpool[pos].state = STATE_IDLE;
		kill(ppid, SIG_NOTIFY);

		client_sd = accept(sd, (void*)&peer_addr, &peer_addr_len);
		if (client_sd<0) {
			if (errno==EINTR || errno==EAGAIN) {
				continue;
			}
			perror("accept()");
			exit(1);
		}

		serverpool[pos].state = STATE_BUSY;
		kill(ppid, SIG_NOTIFY);

		inet_ntop(AF_INET, &peer_addr.sin_addr, ipstr, IPSTRSIZE);
//		printf("[%d]: Client: %s:%d\n", getpid(), ipstr, ntohs(peer_addr.sin_port));
		stamp = time(NULL);

		len = snprintf(linebuf, LINESIZE, FMT_STAMP, stamp);
		/* FIXME: If LINESIZE is not big enough */

		send(client_sd, linebuf, len, 0);

		sleep(5);

		close(client_sd);
	}
	close(sd);
}

int
main()
{
	int ret, i;
	struct sockaddr_in myend;
	struct sigaction sa, osa;
	sigset_t set, oset;
	int val;

	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_NOCLDWAIT;
	sigaction(SIGCHLD, &sa, &osa);

	sa.sa_handler = usr2_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIG_NOTIFY, &sa, &osa);

	sigemptyset(&set);
	sigaddset(&set, SIG_NOTIFY);

	sigprocmask(SIG_BLOCK, &set, &oset);

	serverpool = mmap(NULL, sizeof(struct server_st)*MAXCLIENTS, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
	if (serverpool==MAP_FAILED) {
		perror("mmap()");
		exit(1);
	}

	for (i=0;i<MAXCLIENTS;++i) {
		serverpool[i].pid=-1;
	}

	sd=socket(AF_INET, SOCK_STREAM, 0);
	if (sd==-1) {
		perror("socket()");
		exit(1);
	}

	val = 1;
	if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val))<0) {
		perror("setsockopt(..., SO_REUSEADDR, ...)");
	}

	myend.sin_family = AF_INET;
	myend.sin_port = htons(atoi(SERVERPORT));
	inet_pton(AF_INET, "0.0.0.0", &myend.sin_addr);
	ret=bind(sd, (struct sockaddr*)&myend, sizeof(myend));
	if (ret==-1) {
		perror("bind()");
		exit(1);
	}

	ret=listen(sd, 100);
	if (ret==-1) {
		perror("listen()");
		exit(1);
	}

	for (i=0;i<MINSPARESERVERS;++i) {
		add_1_server();
	}

	while (1) {
		sigsuspend(&oset);
		scan_pool();
		if (idle_count > MAXSPARESERVERS) {
//fprintf(stderr, "[%d]: kill %d server(s).\n", getpid(), (idle_count-MAXSPARESERVERS));
			for (i=0;i<(idle_count-MAXSPARESERVERS);++i) {
				del_1_server();
			}
		} else if (idle_count < MINSPARESERVERS) {
			for (i=0;i<MINSPARESERVERS-idle_count; ++i) {
				add_1_server();
			}
		}
		for (i=0;i<MAXCLIENTS;++i) {
			if (serverpool[i].pid==-1) {
				putchar(' ');
			} else {
				if (serverpool[i].state == STATE_IDLE) {
					putchar('.');
				} else {
					putchar('x');
				}
			}
		}
		putchar('\n');
	}

	sigprocmask(SIG_SETMASK, &oset, NULL);

	exit(0);
}

