//
//  BinaryTree.c
//  binaryTree
//
//  Created by Gguomingyue on 2019/4/22.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "BinaryTree.h"

void init_binaryTree(struct Binary_tree * binaryTree)
{
    for (int i = 0; i < MAX_TREE_NODES; i++) {
        binaryTree->n[i] = NULL;
    }
}

struct Node * createNode(int data)
{
    struct Node * node = (struct Node *)malloc(sizeof(struct Node));
    if (!node) {
        return NULL;
    }
    node->data = data;
    return node;
}

void fake_node(struct Binary_tree * binaryTree)
{
    int i, data[10] = {7, 4, 9, 2, 6, 8, 10, 1, 3, 5};
    init_binaryTree(binaryTree);
    
    /* root start at 1 */
    for (i = 0; i < 10; i++) {
        binaryTree->n[i+1] = createNode(data[i]);
    }
    binaryTree->nodes = 10;
    
    /********
               7
        4              9
    2       6       8     10
  1   3   5
     *******/
    
}

void in_order(struct Binary_tree * binaryTree)
{
    in_order_node(binaryTree, 1);
}

void in_order_node(struct Binary_tree * binaryTree, int index)
{
    if (binaryTree->n[index] == NULL) {
        return;
    }
    //printf("%d ",binaryTree->n[index]->data);
    //printf("[%2d]: %4d\n", index, binaryTree->n[index]->data);
    in_order_node(binaryTree, index<<1);
    //printf("[%2d]: %4d\n", index, binaryTree->n[index]->data);
    in_order_node(binaryTree, (index<<1) + 1);
    printf("[%2d]: %4d\n", index, binaryTree->n[index]->data);
}
