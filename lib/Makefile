CC = gcc
CFLAGS = -c
OBJS = mypthread.o queue.o

libmypthread.a : $(OBJS)
	ar rv libmypthread.a $(OBJS)
	ranlib libmypthread.a
	rm $(OBJS)

queue.o: queue.c
	$(CC) $(CFLAGS) queue.c

mypthread.o: mypthread.c
	$(CC) $(CFLAGS) mypthread.c