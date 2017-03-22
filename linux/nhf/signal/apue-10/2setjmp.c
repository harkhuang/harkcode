#include "apue.h"
#include <setjmp.h>

#define TOK_ADD    5

jmp_buf jmpbuffer;


 

void     do_line(char *);
void     cmd_add(void);
int      get_token(void);

int
main(void)
{
    char    line[MAXLINE];
    printf("setjmp in main1\n");
    if (setjmp(jmpbuffer) != 0)
    printf("error");
    cmd_add();
    printf("setjmp in main\n");
    exit(0);
}

 
void
cmd_add(void)
{
    int     token; 
    longjmp(jmpbuffer, 1);
    printf(" longjmp in cmd_add\n");
    return 0;
}

 
char     *tok_ptr;       /* global pointer for get_token() */

void
do_line(char *ptr)       /* process one line of input */
{
    int    cmd;

    tok_ptr = ptr;
    while ((cmd = get_token()) > 0) {
        switch (cmd) { /* one case for each command */
        case TOK_ADD:
                cmd_add();
                break;
        }
    }
}

 
int
get_token(void)
{
   /* fetch next token from line pointed to by tok_ptr */
}

