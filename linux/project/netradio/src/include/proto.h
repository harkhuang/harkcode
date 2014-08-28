#ifndef PROTO_H
#define PROTO_H

#include <stdint.h>

#define	DEFAULT_MGROUP	"224.2.2.2"
#define	DEFAULT_RCVPORT	"9089"

#define	NUM_CHN		200
#define	CHNID_MIN	0x8000
#define	CHNID_MAX	(CHNIDMIN+NUMCHN-1)

#define	CHNID_LIST	0x0001

#define	MSG_MAX		(512-8)

#define	DATA_MAX	(MSG_MAX-2)
struct msg_channel_st {
	uint16_t	chnid;		/* MUST BETWEEN [CHNID_MIN,CHNID_MAX] */
	uint8_t 	data[1];
};

struct msg_list_ent_st {
	uint16_t    chnid;
	uint16_t	reclen;
	uint8_t		desc[1];
};

#define	LISTSIZE_MAX	(MSG_MAX-4)
struct msg_list_st {
	uint16_t    chnid;		/* MUST BE CHNID_LIST */
	uint16_t	num_chn;
	struct msg_list_ent_st list_ent[1];
};

#endif

