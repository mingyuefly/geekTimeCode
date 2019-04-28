//
//  ListBinaryTree.c
//  binaryTree
//
//  Created by Gguomingyue on 2019/4/22.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "ListBinaryTree.h"

void binaryTreeCreate(Tree **root)
{
    int a = 0;
    printf("\r\n输入节点数值((当输入为100时，当前节点创建完成))):");
    scanf("%d", &a);
    
    if (a == 100) {
        *root = NULL;
    } else {
        *root = (Tnode *)malloc(sizeof(Tnode));
        if (*root == NULL) {
            return;
        }
        (*root)->data = a;
        printf("\r\n create %d 的左孩子:", a);
        binaryTreeCreate(&((*root)->leftChild));
        printf("\r\n create %d 的右孩子:", a);
        binaryTreeCreate(&((*root)->rightChild));
    }
}

void binaryTreeDestroy(Tree *root)
{
    if (root == NULL) {
        return;
    }
    binaryTreeDestroy(root->leftChild);
    binaryTreeDestroy(root->rightChild);
    free(root);
}

void binaryTreePreOrder(Tree * root)
{
    if (root == NULL) {
        return;
    }
    printf(" %d", root->data);
    binaryTreePreOrder(root->leftChild);
    binaryTreePreOrder(root->rightChild);
}

void binaryTreeInOrder(Tree * root)
{
    if (root == NULL) {
        return;
    }
    binaryTreeInOrder(root->leftChild);
    printf(" %d", root->data);
    binaryTreeInOrder(root->rightChild);
}

void binaryTreePostOrder(Tree * root)
{
    if (root == NULL) {
        return;
    }
    binaryTreePostOrder(root->leftChild);
    binaryTreePostOrder(root->rightChild);
    printf(" %d", root->data);
}

void binaryTreeLevelOrder(Tree * root)
{
    list_queue *queue = NULL;
    Tnode * node = NULL;
    if (root == NULL) {
        return;
    }
    queue = list_queue_create();
    list_queue_enqueue(queue, (void *)root);
    while (!list_queue_is_empty(queue)) {
        // 每次节点出队列时，将左右节点加入队列，并打印本节点
        list_queue_dequeue(queue, (void *)&node);
        printf(" %d ",node->data);
        if (node->leftChild != NULL) {
            list_queue_enqueue(queue, (void *)node->leftChild);
        }
        if (node->rightChild != NULL) {
            list_queue_enqueue(queue, node->rightChild);
        }
    }
    
    /********
             7
     4              9
  2       6       8    10
1   3   5
     *******/
}

/*
 遍历叶子节点
 */
void binaryTreePrintfLeaf(Tree * root)
{
    if (root == NULL) {
        return;
    }
    if (root->leftChild == NULL && root->rightChild == NULL) {
        printf(" %d ", root->data);
    } else {
        binaryTreePrintfLeaf(root->leftChild);
        binaryTreePrintfLeaf(root->rightChild);
    }
}

int binaryTreeGetLeafNum(Tree * root)
{
    if (root == NULL) {
        return 0;
    }
    if (root->leftChild == NULL && root->rightChild == NULL) {
        return 1;
    }
    return binaryTreeGetLeafNum(root->leftChild) + binaryTreeGetLeafNum(root->rightChild);
}

int binaryTreeGetHight(Tree * root)
{
    int leftHight = 0;
    int rightHight = 0;
    if (root == NULL) {
        return 0;
    }
    leftHight = binaryTreeGetHight(root->leftChild);
    rightHight = binaryTreeGetHight(root->rightChild);
    return leftHight > rightHight?(leftHight + 1):(rightHight + 1);
}
