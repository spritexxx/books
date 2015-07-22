# specify compiler
CC=gcc

# specify compiler flags
CFLAGS=-c -Wall 

all: simple_server

simple_server: simple_server.o hacking.o
	$(CC) $^ -o simple_server

simple_server.o: simple_server.c
	$(CC) $^ $(CFLAGS)

hacking.o: hacking.c
	$(CC) $^ $(CFLAGS)

clean:
	rm *.o simple_server

run: simple_server
	./simple_server
