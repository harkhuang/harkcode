CFLAGS+=-I../include -pthread
LDFLAGS+=-pthread

all: server

server: main.o thr_channel.o thr_hoster.o medialib.o mytbf.o

clean:
	rm -rf *.o server

install:
	cp server /usr/local/bin/

