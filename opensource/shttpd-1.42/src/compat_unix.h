/*
 * Copyright (c) 2004-2007 Sergey Lyubka <valenok@gmail.com>
 * All rights reserved
 *
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Sergey Lyubka wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 */
#ifndef _COMPAT_UNIX_HEADER_INCLUDED_H
#define _COMPAT_UNIX_HEADER_INCLUDED_H


#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/mman.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#include <pwd.h>
#include <unistd.h>
#include <dirent.h>
#include <dlfcn.h>

#if !defined(NO_THREADS)
#include "pthread.h"
#define	_beginthread(a, b, c) do { pthread_t tid; \
	pthread_create(&tid, NULL, (void *(*)(void *))a, c); } while (0)
#endif /* !NO_THREADS */

//加入{}while(0) 使宏按照你预期的进行替代

#define	SSL_LIB				"libssl.so"
#define	DIRSEP				'/'
#define	IS_DIRSEP_CHAR(c)		((c) == '/')
#define	O_BINARY			0
#define	closesocket(a)			close(a)
#define	ERRNO				errno


#endif
