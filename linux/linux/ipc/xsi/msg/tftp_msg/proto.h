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

/*
enum {
	C2S_xxx=1,
	C2S_yyy
};
*/

struct msg_path_st {
	long mtype;				/* Must be MT_C2S */
	/* int c2s_code; */
	char path[PATHSIZE];	/* ASCIIZ */
};

enum {
	S2C_DATA=1,
	S2C_EOT,
	S2C_ERR
};

struct msg_s2c_st {
	long mtype;
	int s2c_code;
	unoin {
		struct {
			char data[DATASIZE];
			int len;
		} data;
		int errno;
	} un;
};

#define	S2C_VALLEN_MIN	(sizeof(long)+ sizeof(int))
#define	S2C_VALLEN_MAX	(sizeof(struct msg_s2c_st))

#endif

