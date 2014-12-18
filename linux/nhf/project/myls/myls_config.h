#ifndef MYLS_CONFIG_H
#define MYLS_CONFIG_H

extern struct {
	int inode;
	int perm;
	int hlink;
	int user, group;
	int size;
	int mtime;
	int fname;
} global_config;

#endif

