#ifndef NODEQUEUE_H_
#define NODEQUEUE_H_
typedef struct listNode listNode;
typedef struct NodeQueue NodeQueue;
treeNode* peek(NodeQueue* nodequeue);
void enqueue(NodeQueue* nodequeue, treeNode* treenode);
void dequeue(NodeQueue* nodequeue);
NodeQueue* newNodeQueue();
int isEmpty(NodeQueue* que);



#endif
