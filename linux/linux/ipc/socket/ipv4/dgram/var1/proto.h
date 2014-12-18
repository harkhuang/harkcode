#ifndef PROTO_H
#define PROTO_H

#include <stdint.h>

#define	RCVADDR	"0.0.0.0"	/* ANY ADDR */
#define	RCVPORT	"1984"

#define	SCORE_MAX	(512-8)
struct score_st {
	int32_t math, chinese;
	uint8_t name[1];	/* UTF-8 */
}__attribute__((packed));

#endif

