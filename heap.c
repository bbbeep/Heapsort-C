// Jeremy McCormick
// CS201 University Of Alabama
#include <assert.h>
#include "heap.h"
#include "treenode.h"
#include "nodequeue.h"
#include "nodestack.h"


static int greaterThan (int a, int b);
static int lessThan(int a, int b);
static void buildHeap(Heap* heap,treeNode* root);
static void heapify(Heap* heap,treeNode* root);
static NodeStack* getLevelOrder(Heap* heap);

struct Heap
{
    int (*cmp)(int,int);
    treeNode* root;
    NodeQueue* addQueue;
    NodeStack* extractStack;
};

Heap* newHeap(int minOrMax) // O makes max heap, anything else makes min-heap;
{
    Heap* heap = malloc(sizeof(Heap));
    assert(heap != NULL);
    heap->root = NULL;
    heap->addQueue = newNodeQueue();
    heap->extractStack = newNodeStack();

    if(minOrMax == 0)
        heap->cmp = lessThan;
    else
        heap->cmp = greaterThan;

    return heap;
}

void add(Heap* heap, int value)//Use queue to keep track of available spots for leaf nodes
{
    treeNode* treenode;
    treenode = newTreeNode(value);

    if(heap->root == NULL)
    {
        heap->root = treenode;
        enqueue(heap->addQueue,treenode);
    }
    else
    {
        treeNode* peekedNode = peek(heap->addQueue);

        if(peekedNode->left == NULL)
        {
            peekedNode->left = treenode;
            treenode->parent = peekedNode;
            enqueue(heap->addQueue, treenode);
        }
        else if(peekedNode->right == NULL)
        {
            peekedNode->right = treenode;
            treenode->parent = peekedNode;
            enqueue(heap->addQueue, treenode);
            dequeue(heap->addQueue);
        }
    }
}

int extractTop(Heap* heap)//Uses stack of level order traversal to keep track of rightmost leaf node
{
    treeNode* leaf = pop(heap->extractStack);
    int extracted = heap->root->value;

    if(heap->root == leaf)
        return extracted;

    heap->root->value = leaf->value;

    if(leaf->parent->right != NULL && leaf->parent->right == leaf)
        leaf->parent->right = NULL;
    else
        leaf->parent->left = NULL;

    heapify(heap, heap->root);

    return extracted;
}

void makeHeap (Heap* heap)//Had to make extra function to handle the level order traversal
{

    buildHeap(heap,heap->root);

    heap->extractStack = getLevelOrder(heap); //Make the level order stack here becuase we only have to do it once. It runs O(n). If it was in extract() or buildHeap() it would
                                        // make the heapsort no longer be O(nlogn)
}

static void buildHeap(Heap* heap, treeNode* root)
{
    if(root->left == NULL && root->right == NULL)
        return;

    buildHeap(heap,root->left);

    if(root->right != NULL)
        buildHeap(heap, root->right);

    heapify(heap, root);
}

static void heapify(Heap* heap, treeNode* root)
{
    if(root->left == NULL && root->right == NULL)
        return;

    treeNode* swap = root;

    if(heap->cmp(swap->value,root->left->value))
        swap = root->left;
    if(root->right != NULL && heap->cmp(swap->value,root->right->value))
        swap = root->right;

    if(swap != root)
    {
        int temp = root->value;
        root->value = swap->value;
        swap->value = temp;
        heapify(heap, swap);
    }

}

static NodeStack* getLevelOrder(Heap* heap)//Use queue to get traversal and push it onto stack
{
    NodeQueue* queue = newNodeQueue();
    NodeStack* stack = newNodeStack();
    treeNode* temp;

    enqueue(queue,heap->root);
    while(isEmpty(queue) != 1)
    {
        temp = peek(queue);
        dequeue(queue);
        push(stack, temp);
        if(temp->left != NULL)
            enqueue(queue, temp->left);
        if(temp->right != NULL)
            enqueue(queue,temp->right);
    }
    return stack;
}


static int greaterThan (int a, int b)
{
    return a>b;
}

static int lessThan(int a,int b)
{
    return a<b;
}
