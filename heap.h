#ifndef HEAP_H_
#define HEAP_H_

typedef struct Heap Heap;
Heap* newHeap(int minOrMax);
int extractTop(Heap* heap);
void add(Heap* heap,int value);
void makeHeap(Heap* heap);
#endif // HEAP_H_
