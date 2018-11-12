#LIB = 
all:laber.o
	gcc -g -Wall -o laber laber.o $(LIB) `pkg-config --cflags --libs gtk+-2.0`
laber.o:
	gcc -c laber.cpp $(LIB) `pkg-config --cflags --libs gtk+-2.0`
clean:
	rm -r *.o