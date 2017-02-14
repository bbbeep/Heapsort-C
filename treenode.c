// Jeremy McCormick
// CS201 University Of Alabama
#include <assert.h>
#include "treenode.h"

treeNode* newTreeNode(int value)
{
    treeNode* node = malloc(sizeof(treeNode));
    assert(node != NULL);
    node->value = value;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
     return node;
}
