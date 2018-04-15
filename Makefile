
APP = ./bin/threadville
CC = gcc
CFLAGS = -Wall -c
LFLAGS = -Wall -o

OBJS = main.o

all: $(OBJS)
	$(CC) $(LFLAGS) $(APP) $(OBJS)
	rm *.o


main.o: main.c 
	$(CC) $(CFLAGS) main.c



PHONY: clean
clean:
	rm -f ./bin/threadville