// Jeremy McCormick
// CS201 University Of Alabama
#include <assert.h>
#include "treenode.h"
#include "nodequeue.h"


static listNode* newListNode(treeNode* node);

struct NodeQueue
{
    listNode* head;
    listNode* tail;
};

struct listNode
{
    treeNode* treeNode;
    listNode* next;
};


void enqueue(NodeQueue* nodequeue, treeNode* treenode)
{
    listNode* listnode = newListNode(treenode);
    if(nodequeue->head == NULL)
    {
        nodequeue->head = listnode;
    }
    else
    {
        nodequeue->tail->next = listnode;
    }
    nodequeue->tail = listnode;
}

treeNode* peek(NodeQueue* nodequeue)
{
    return nodequeue->head->treeNode;
}

void dequeue(NodeQueue* nodequeue)
{
    nodequeue->head = nodequeue->head->next;

}

static listNode* newListNode(treeNode* node)
{
    listNode* listnode = malloc(sizeof(listNode));
    assert(listnode != NULL);
    listnode->treeNode = node;
    listnode->next = NULL;
    return listnode;
}

NodeQueue* newNodeQueue()
{
    NodeQueue *nodequeue = malloc(sizeof(NodeQueue));
    assert(nodequeue != NULL);
    nodequeue->head = NULL;
    nodequeue->tail = NULL;
    return nodequeue;
}

int isEmpty(NodeQueue* que)
{
    if(que->head == NULL)
        return 1;
    return 0;
}
