#ifndef PROTO_H
#define	PROTO_H

#define	KEYPATH	"/tmp/count"
#define	KEYPROJ	't'

#define	PATHSIZE	1024
#define	DATASIZE	1024

enum {
	MT_C2S=1,
	MT_S2C
};

struct msg_c2s_st {
	long mtype;				/* Must be MT_C2S */
	char path[PATHSIZE];	/* ASCIIZ */
};

struct msg_s2c_st {
	long mtype;
	char data[DATASIZE];
	int len;
/*
 * 			len>0	: DATA
 * 			len==0	: EOT
 * 			len<0	: ERR, len==-errno
 */
};

#endif

