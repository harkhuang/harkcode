#ifndef PROTO_H
#define PROTO_H

#define	KEYPATH	"/tmp/count"
#define	KEYPROJ	'a'

#define	NAMESIZE	16
struct score_st {
	long mtype;
	char name[NAMESIZE];	/* UTF-8 */
	int math, chinese;
};

#endif

