#ifndef TREENODE_H_
#define TREENODE_H_
#include<stdlib.h>

//typedef struct treeNode treeNode;
typedef struct treeNode
{
    int value;
    struct treeNode* parent;
    struct treeNode* left;
    struct treeNode* right;

}treeNode;


treeNode* newTreeNode(int value);
#endif // TREENODE_H_
