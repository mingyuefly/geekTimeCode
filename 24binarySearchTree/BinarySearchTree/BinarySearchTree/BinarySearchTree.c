//
//  BinarySearchTree.c
//  BinarySearchTree
//
//  Created by Gguomingyue on 2019/4/23.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "BinarySearchTree.h"
#include "list_queue.h"

Tree * treeCreate(compareFuc compareFuction, destroyFuc destroyFunction)
{
    Tree * tree = (Tree *)malloc(sizeof(Tree));
    if (tree == NULL) {
        return NULL;
    }
    tree->size = 0;
    tree->compare = compareFuction;
    tree->destroy = destroyFunction;
    tree->root = NULL;
    return tree;
}

TreeNode * treeSearch(Tree * tree, dataType data)
{
    if (tree == NULL || bstree_is_empty(tree)) {
        return NULL;
    }
    TreeNode * node = tree->root;
    int res = 0;
    while (node != NULL) {
        res = tree->compare(data, node->data);
        if (res == 0) {
            return node;
        } else if (res > 0) {
            node = node->rightNode;
        } else {
            node = node->leftNode;
        }
    }
    return NULL;
}

int treeInsert(Tree * tree, dataType data)
{
    if (tree == NULL) {
        return -1;
    }
    TreeNode * node = (TreeNode *)malloc(sizeof(TreeNode));
    if (node == NULL) {
        return -2;
    }
    node->data = data;
    node->leftNode = NULL;
    node->rightNode = NULL;
    if (bstree_is_empty(tree)) {
        tree->root = node;
        tree->size++;
        return 0;
    }
    int res = 0;
    TreeNode * p = tree->root;
    while (p != NULL) {
        res = tree->compare(data, p->data);
        if (res > 0) {
            if (p->rightNode == NULL) {
                p->rightNode = node;
                tree->size++;
                return 0;
            }
            p = p->rightNode;
        } else {
            if (p->leftNode == NULL) {
                p->leftNode = node;
                tree->size++;
                return 0;
            }
            p = p->leftNode;
        }
    }
    return -3;
}

int treeDelete(Tree * tree, dataType data)
{
    if (tree == NULL || bstree_is_empty(tree)) {
        return -1;
    }
    TreeNode * node = tree->root; //所要删除的node
    TreeNode * pNode = NULL;      //node父节点
    int res = 0;
    while (node != NULL && tree->compare(data, node->data) != 0) {
        pNode = node;//当要删除的是根节点时pNode为空
        res = tree->compare(data, node->data);
        if (res > 0) {
            node = node->rightNode;
        } else if (res < 0) {
            node = node->leftNode;
        }
    }
    if (node == NULL) {
        return -2;
    }
    TreeNode * minP = NULL;
    TreeNode * minPP = NULL;
    if (node->leftNode != NULL && node->rightNode != NULL) {
        // 要删除的节点即有左子节点，又有右子节点，要找到这个节点右子树中的最小节点，形象的说也是这个节点右子树中最左下角节点，在这里是minP，其父节点为minPP。
        minP = node->rightNode;
        while (minP->leftNode != NULL) {
            minPP = minP;
            minP = minP->leftNode;
        }
        //将node的data值和minP的data值互换，
        int tempData = node->data;
        node->data = minP->data;
        minP->data = tempData;
        //问题就转化为删除minP
        node = minP;
        pNode = minPP;
    }
    
    // 仅有一个子节点或没有子节点
    TreeNode * child = NULL;
    if (node->leftNode != NULL) {
        // 仅有左子节点
        child = node->leftNode;
    } else if (node->rightNode != NULL) {
        // 仅有右子节点
        child = node->rightNode;
    } else {
        // 没有子节点
        child = NULL;
    }
    
    if (pNode == NULL) {
        // 删除的是根节点
        tree->root = child;
    } else if (pNode->leftNode == node) {
        // node是pNode的左子节点
        pNode->leftNode = child;
    } else {
        // node是pNode的右子节点
        pNode->rightNode = child;
    }
    
    tree->size--;
    free(node);
    
    return 0;
}

void treeDump(Tree * tree)
{
    //TreeNode *node = NULL;
    if ((tree == NULL) || (bstree_is_empty(tree)))
    {
        printf("\r\n 当前树是空树");
    }
    printf("\r\nSTART-----------------%d------------\r\n",tree->size);
    treeInOrder(tree->root);
    printf("\r\nEND-----------------%d----------------",tree->size);
    printf("\r\nSTART-----------------%d------------\r\n",tree->size);
    treeLevelOrder(tree->root);
    printf("\r\nEND-----------------%d----------------",tree->size);
    
}

void treeDestroyTreeNodes(Tree * tree, TreeNode * root)
{
    if (root == NULL) {
        return;
    }
    treeDestroyTreeNodes(tree, root->leftNode);
    treeDestroyTreeNodes(tree, root->rightNode);
    free(root);
}

void treeDestroyTree(Tree * tree)
{
    if (tree == NULL) {
        return;
    }
    treeDestroyTreeNodes(tree, tree->root);
    free(tree);
}

void treeInOrder(TreeNode * root)
{
    if (root == NULL) {
        return;
    }
    treeInOrder(root->leftNode);
    printf(" %d ", root->data);
    treeInOrder(root->rightNode);
}

void treeLevelOrder(TreeNode * root)
{
    list_queue *queue = NULL;
    TreeNode * node = NULL;
    if (root == NULL) {
        return;
    }
    queue = list_queue_create();
    list_queue_enqueue(queue, (void *)root);
    while (!list_queue_is_empty(queue)) {
        // 每次节点出队列时，将左右节点加入队列，并打印本节点
        list_queue_dequeue(queue, (void *)&node);
        printf(" %d ",node->data);
        if (node->leftNode != NULL) {
            list_queue_enqueue(queue, (void *)node->leftNode);
        }
        if (node->rightNode != NULL) {
            list_queue_enqueue(queue, node->rightNode);
        }
    }
    
    /********
             7
     4              9
  2       6       8   10
1   3   5
     *******/
}

int treeCompare(dataType key1, dataType key2)
{
    if (key1 == key2) {
        return 0;
    } else if (key1 > key2) {
        return 1;
    } else {
        return -1;
    }
}
