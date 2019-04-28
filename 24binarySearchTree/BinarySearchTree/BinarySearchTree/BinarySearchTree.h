//
//  BinarySearchTree.h
//  BinarySearchTree
//
//  Created by Gguomingyue on 2019/4/23.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int dataType;

typedef struct _btreeNode{
    dataType data;
    struct _btreeNode * leftNode;
    struct _btreeNode * rightNode;
}TreeNode;

typedef struct _btree{
    int size;
    int (*compare)(dataType key1, dataType key2);
    int (*destroy)(dataType data);
    TreeNode * root;
}Tree;

typedef int (*compareFuc)(dataType key1, dataType key2);
typedef int (*destroyFuc)(dataType data);

#define bstree_is_empty(tree)  (tree->size == 0)

Tree * treeCreate(compareFuc compareFuction, destroyFuc destroyFunction);
TreeNode * treeSearch(Tree * tree, dataType data);
int treeInsert(Tree * tree, dataType data);
int treeDelete(Tree * tree, dataType data);
void treeDump(Tree * tree);
void treeDestroyTreeNodes(Tree * tree, TreeNode * root);
void treeDestroyTree(Tree * tree);
void treeInOrder(TreeNode * root);
void treeLevelOrder(TreeNode * root);
int treeCompare(dataType key1, dataType key2);



#endif /* BinarySearchTree_h */
