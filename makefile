CC = gcc
CFLAGS = -Wall -g

heapsort: heapsort.o heap.o nodestack.o nodequeue.o treenode.o
	$(CC) $(CFLAGS) -o heapsort heapsort.o heap.o nodestack.o nodequeue.o treenode.o
heapsort.o: heapsort.c heap.h
	$(CC) $(CFLAGS) -c heapsort.c
heap.o: heap.c heap.h treenode.h nodequeue.h nodestack.h
	$(CC) $(CFLAGS) -c heap.c
nodestack.o: nodestack.c nodestack.h treenode.h
	$(CC) $(CFLAGS) -c nodestack.c
nodequeue.o: nodequeue.c nodequeue.h treenode.h
	$(CC) $(CFLAGS) -c nodequeue.c
treenode.o: treenode.c treenode.h
	$(CC) $(CFLAGS) -c treenode.c

clean:
	@- $(RM) heapsort *.o
