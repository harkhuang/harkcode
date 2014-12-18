#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <glob.h>

#define	PAT	"/etc/a*.conf"

int
main()
{
	glob_t glres;
	int err;
	int i;

	err = glob(PAT, 0, NULL, &glres);
	if (err) {
		fprintf(stderr, "glob() error.\n");
		exit(1);
	}

	for (i=0;i<glres.gl_pathc;++i) {
		puts(glres.gl_pathv[i]);
	}

	globfree(&glres);

	return 0;
}

