// Jeremy McCormick
// CS201 University Of Alabama
#include <assert.h>
#include "treenode.h"
#include "nodestack.h"

static listNode* newListNode(treeNode* node);

struct NodeStack
{
    struct listNode* tail;

};

struct listNode
{
    struct treeNode* treeNode;
    struct listNode* prev;
};

NodeStack* newNodeStack()
{
    NodeStack* nodestack = malloc(sizeof(NodeStack));
    assert(nodestack != NULL);
    nodestack->tail = NULL;
    return nodestack;
}

static listNode* newListNode(treeNode* node)
{
    listNode* listnode = malloc(sizeof(listNode));
    assert(listnode != NULL);
    listnode->treeNode = node;
    listnode->prev = NULL;
    return listnode;
}

void push(NodeStack* nodestack, treeNode* treenode)
{
    listNode* listnode = newListNode(treenode);

    if(nodestack->tail == NULL)
        nodestack->tail = listnode;
    else
    {
        listnode->prev = nodestack->tail;
        nodestack->tail = listnode;
    }
}

treeNode* pop(NodeStack* nodestack)
{
    treeNode* returnNode;
    returnNode = nodestack->tail->treeNode;
    nodestack->tail = nodestack->tail->prev;
    return returnNode;
}
