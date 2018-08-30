#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define	DELIMS	" \t\n"

struct mysh_cmd_st {
	glob_t gl;
};

static void prompt(void)
{
	printf("mysh-0.1$ ");
}

static void parse(struct mysh_cmd_st *res, char *line)
{
	int i;
	char *tok;

	for (i=0;;) {
		tok = strsep(&line, DELIMS);
		if (tok=NULL) {
			break;
		}
		if (tok[0]=='\0') {
			continue;
		}
		if (glob(tok, GLOB_NOCHECK|(GLOB_APPEND*i), NULL, &res->gl)!=0) {
			fprintf(stderr, "error\n");
		} else {
			i=1;
		}
	}
}

static void parse_free(struct mysh_cmd_st *res)
{
	globfree(&res->gl);
	res->gl.gl_pathc = 0;
}

static int is_buildin(struct mysh_cmd_st *res)
{
	return 0;
}

int
main()
{
	pid_t pid;
	char *line;
	size_t linesize;
	struct mysh_cmd_st cmd;

	line = NULL;
	linesize = 0;
	while (1) {
		prompt();
		if (getline(&line, &linesize, stdin)<0) {
			if (ferror(stdin)) {
				perror("getline()");
				exit(1);
			} else {
				break;
			}
		}
		if (line[0]=='\n') {
			continue;
		}
		parse(&cmd, line);
#if 0
int i;
for (i=0;i<cmd.gl.gl_pathc;++i) {
	printf("%d: %s\n", i, cmd.gl.gl_pathv[i]);
}
#endif
		if (is_buildin(&cmd)) {
			/* Do it */
		} else {
			pid = fork();
			if (pid<0) {
			}
			if (pid==0) {
				execvp(cmd.gl.gl_pathv[0], cmd.gl.gl_pathv);
				perror("execvp()");
				exit(1);
			}
			wait(NULL);
		}
		parse_free(&cmd);
	}

	free(line);

	return 0;
}

