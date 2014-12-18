#ifndef MYFILE_H
#define MYFILE_H

#define	NOFILE	200

void *myfile_creat(void);

#define	FLG_RD	0x00000001L
#define	FLG_WR	0x00000002L

int myfile_open(void *, int flags);
int myfile_close(int);

ssize_t myfile_read(int, void *, size_t);

ssize_t myfile_write(int, const void *, size_t);

#endif

