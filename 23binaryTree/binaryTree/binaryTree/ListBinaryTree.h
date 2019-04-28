//
//  ListBinaryTree.h
//  binaryTree
//
//  Created by Gguomingyue on 2019/4/22.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef ListBinaryTree_h
#define ListBinaryTree_h

#include <stdio.h>
#include <stdlib.h>
#include "list_queue.h"

typedef struct _treeNode{
    int data;
    struct _treeNode * leftChild;
    struct _treeNode * rightChild;
}Tnode, Tree;

/*
 树的创建和销毁
 */
void binaryTreeCreate(Tree * * root);
void binaryTreeDestroy(Tree * root);

/*
 前中后序遍历
 */
void binaryTreePreOrder(Tree * root);
void binaryTreeInOrder(Tree * root);
void binaryTreePostOrder(Tree * root);

/*
 层次遍历
 */
void binaryTreeLevelOrder(Tree * root);

/*
 遍历叶子节点
 */
void binaryTreePrintfLeaf(Tree * root);

int binaryTreeGetLeafNum(Tree * root);

int binaryTreeGetHight(Tree * root);

#endif /* ListBinaryTree_h */
