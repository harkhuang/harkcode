#ifndef ERR_H
#define ERR_H

#ifdef DEBUG
#define	D_(...)	do {fprintf(stderr, ##);} while(0)
#else
#define	D_(...)	do {} while (0)
#endif

#endif

