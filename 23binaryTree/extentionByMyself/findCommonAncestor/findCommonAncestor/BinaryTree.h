//
//  BinaryTree.h
//  binaryTree
//
//  Created by Gguomingyue on 2019/4/22.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define MAX_TREE_NODES (1 << 8)

struct Node {
    int data;
};

struct Binary_tree {
    union {
        unsigned long nodes;
        struct Node * n[MAX_TREE_NODES];
    };
};

void init_binaryTree(struct Binary_tree * binaryTree);
void fake_node(struct Binary_tree * binaryTree);
struct Node * createNode(int data);
void in_order(struct Binary_tree * binaryTree);
void in_order_node(struct Binary_tree * binaryTree, int index);





#endif /* BinaryTree_h */
