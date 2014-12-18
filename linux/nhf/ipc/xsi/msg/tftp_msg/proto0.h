#ifndef PROTO_H
#define	PROTO_H

#define	KEYPATH	"/tmp/count"
#define	KEYPROJ	't'

#define	PATHSIZE	1024
#define	DATASIZE	1024

struct msg_path_st {
	char path[PATHSIZE];	/* ASCIIZ */
};

struct msg_data_st {
	char data[DATASIZE];
	int len;
};

struct msg_eot_st {
};

struct msg_err_st {
	int errno;
};

#endif

