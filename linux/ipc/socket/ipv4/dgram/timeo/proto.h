#ifndef PROTO_H
#define PROTO_H

#include <stdint.h>

#define	RCVADDR	"0.0.0.0"	/* ANY ADDR */
#define	RCVPORT	"1984"

#define	NAMESIZE	16
struct score_st {
	uint8_t name[NAMESIZE];	/* UTF-8 */
	int32_t math, chinese;
}__attribute__((packed));

#endif

