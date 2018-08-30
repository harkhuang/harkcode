#ifndef MEDIALIB_H
#define MEDIALIB_H

struct chn_list_ent {
	uint16_t chnid;
	char *desc;
};

int media_getchnlist(struct chn_list_ent **, int *);
int media_freechnlist(struct chn_list_ent *);

ssize_t media_channelread(uint32_t chnid, void *bufp, size_t bufsize);

#endif

