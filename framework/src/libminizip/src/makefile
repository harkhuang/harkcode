CSRCS =  adler32.c
CSRCS += compress.c
CSRCS += crc32.c
CSRCS +=deflate.c
CSRCS +=gzclose.c
CSRCS +=gzlib.c
CSRCS +=gzread.c
CSRCS +=gzwrite.c
CSRCS +=infback.c
CSRCS +=inffast.c
CSRCS +=inflate.c
CSRCS +=inftrees.c
CSRCS +=trees.c
CSRCS +=uncompr.c
CSRCS +=zutil.c
CSRCS +=zip.c
CSRCS +=unzip.c
CSRCS +=ioapi.c



TEST  = ../main.c
TEST += ../minizip.c
all:
	gcc ${CSRCS} -fPIC -shared -o libtest.so
	gcc ${TEST}   -L. -ltest -o test

.PHONY: clean
clean:
	rm *.o test  libtest.so
