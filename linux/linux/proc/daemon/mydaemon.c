#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <syslog.h>
#include <errno.h>

#define FNAME	"/tmp/daemon.out"

static void daemon_exit(int s)
{
	syslog(LOG_INFO, "Signal %d was caught, exit now.", s);
	/* Resource Free */
	closelog();
	exit(0);
}

static void daemonize(int nochdir, int noclose)
{
	pid_t pid;
	int fd;

	pid = fork();
	if (pid<0) {
		syslog(LOG_ERR, "fork(): %s", strerror(errno));
		exit(1);
	}
	if (pid!=0) {
		exit(0);
	}

	if (!noclose) {
		fd = open("/dev/null", O_RDWR);
		if (fd<0) {
			syslog(LOG_WARNING, "open(/dev/null): %s", strerror(errno));
		} else {
			dup2(fd, 0);
			dup2(fd, 1);
			dup2(fd, 2);

			if (fd>2) {
				close(fd);
			}
		}
	}

	setsid();

	if (!nochdir) {
		chdir("/");
	}
	umask(0);
}

int
main()
{
	int i;
	FILE *fp;
	struct sigaction sa, osa;

	openlog("mydaemon", LOG_PID|LOG_PERROR, LOG_DAEMON);

	// daemonize(0, 0);

	sa.sa_handler = daemon_exit;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGTERM);
	sigaddset(&sa.sa_mask, SIGINT);
	sigaddset(&sa.sa_mask, SIGQUIT);
	sa.sa_flags = 0;

	sigaction(SIGTERM, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
/*
	signal(SIGTERM, daemon_exit);
	signal(SIGINT, daemon_exit);
	signal(SIGQUIT, daemon_exit);
*/
	fp = fopen(FNAME, "a");
	if (fp==NULL) {
		syslog(LOG_ERR, "fopen(): %s", strerror(errno));
		exit(1);
	}

	for (i=0;;++i) {
		fprintf(fp, "%d\n", i);
		fflush(fp);
		sleep(1);
	}
}

