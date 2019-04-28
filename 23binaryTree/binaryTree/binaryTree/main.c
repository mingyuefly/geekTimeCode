//
//  main.c
//  binaryTree
//
//  Created by Gguomingyue on 2019/4/22.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include "ListBinaryTree.h"
#include "BinaryTree.h"

int main(int argc, const char * argv[]) {
    
    /***** 数组二叉树测试****/
    //struct Binary_tree binaryTree;
    //fake_node(&binaryTree);
    //in_order(&binaryTree);
    /************/
    
    /****** 链表二叉树测试 *****/
    Tree *root = NULL;
    printf("\r\n创建二叉树:");
    binaryTreeCreate(&root);
    printf("\r\n先序遍历二叉树:");
    binaryTreePreOrder(root);
    printf("\r\n中序遍历二叉树:");
    binaryTreeInOrder(root);
    printf("\r\n后序遍历二叉树:");
    binaryTreePostOrder(root);
    printf("\r\n层次遍历二叉树:");
    binaryTreeLevelOrder(root);
    printf("\r\n打印二叉树叶子节点:");
    binaryTreePrintfLeaf(root);
    printf("\r\n打印二叉树叶子节点个数:%d", binaryTreeGetLeafNum(root));
    printf("\r\n打印二叉树高度:%d", binaryTreeGetHight(root));
    
    binaryTreeDestroy(root);
    
    /************************/
    
    return 0;
}
