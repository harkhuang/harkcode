#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <sys/stat.h>
#include <string.h>

#define	PATHMAX	1024

static int notloop(const char *path)
{
	char *pos;

	pos = strrchr(path, '/');
	if (pos==NULL) {
		return 1;
	}
	if ((strcmp(pos+1, ".")==0) || (strcmp(pos+1, "..")==0)) {
		return 0;
	}
	return 1;
}

static long long do_mydu(const char *path)
{
	static struct stat statres;
	static char nextpath[PATHMAX];
	static int ret;
	static int depth=0;

	int i;
	long long sum;
	glob_t globres;

//	fprintf(stderr, "%s\n", path);

	if (lstat(path, &statres)<0) {
		perror("lstat()");
		count--;
		return 0;
	}
	if (!S_ISDIR(statres.st_mode)) {
		count--;
		return statres.st_blocks;
	}
	snprintf(nextpath, PATHMAX, "%s/*", path);
	if (ret = glob(nextpath, GLOB_NOSORT, NULL, &globres)) {
		fprintf(stderr, "glob(%s)==%d\n", nextpath, ret);
	}
	snprintf(nextpath, PATHMAX, "%s/.*", path);
	if (ret = glob(nextpath, GLOB_NOSORT|GLOB_APPEND, NULL, &globres)) {
		fprintf(stderr, "glob(%s)==%d\n", nextpath, ret);
	}
	sum = statres.st_blocks;
	for (i=0;i<globres.gl_pathc;++i) {
		if (notloop(globres.gl_pathv[i])) {
			count++;
			sum += do_mydu(globres.gl_pathv[i]);
		}
	}
	globfree(&globres);

	count--;
	return sum;
}

int
main(int argc, char **argv)
{
	if (argc<2) {
		fprintf(stderr, "Usage...\n");
		exit(1);
	}

	printf("%lld\n", do_mydu(argv[1]));

	return 0;
}

