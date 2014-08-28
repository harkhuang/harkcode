#ifndef THR_CHANNEL_H
#define THR_CHANNEL_H

#include "medialib.h"

int thr_channel_create(struct chn_list_ent *);

int thr_channel_destroy(struct chn_list_ent *);
int thr_channel_destroyall(void);

#endif

