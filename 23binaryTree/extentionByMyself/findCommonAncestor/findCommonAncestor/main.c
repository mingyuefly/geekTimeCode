//
//  main.c
//  findCommonAncestor
//
//  Created by mingyue on 2020/3/19.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include "BinaryTree.h"
#include "ListBinaryTree.h"

int main(int argc, const char * argv[]) {
    
    Tree *root = NULL;
    printf("\r\n创建二叉树:");
    binaryTreeCreate(&root);
    printf("\r\n中序遍历二叉树:");
    binaryTreeInOrder(root);
    
    Tnode* node1 = lowestCommonAncestorData(root, 5, 1);
    Tnode* node2 = lowestCommonAncestorData(root, 5, 4);
    Tnode* node3 = lowestCommonAncestorData(root, 6, 4);
    printf("data1 = %d", node1->data);
    printf("data2 = %d", node2->data);
    printf("data3 = %d", node3->data);
    
    binaryTreeDestroy(root);
    
    return 0;
}
