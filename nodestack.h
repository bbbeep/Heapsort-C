#ifndef NODESTACK_H_
#define NODESTACK_H_
typedef struct NodeStack NodeStack;
typedef struct listNode listNode;

void push(NodeStack* nodestack, treeNode* treenode);
treeNode* pop(NodeStack* nodestack);
NodeStack* newNodeStack();
#endif
