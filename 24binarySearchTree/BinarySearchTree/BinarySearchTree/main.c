//
//  main.c
//  BinarySearchTree
//
//  Created by Gguomingyue on 2019/4/23.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include "BinarySearchTree.h"

int main(int argc, const char * argv[]) {
    
    Tree *tree = NULL;
    TreeNode *node = NULL;
    dataType data = 0;
    int res = 0;
    
    tree = treeCreate(treeCompare,NULL);
    assert(tree != NULL);
    
    while(1)
    {
        printf("\r\n插入一个数字，输入100时退出：");
        scanf("%d",&data);
        if(data == 100)break;
        res = treeInsert(tree,data);
        printf("\r\n %d 插入%s成功",data,(res != 0)?("不"):(" "));
    }
    treeDump(tree);
    while(1)
    {
        printf("\r\n查询一个数字，输入100时退出：");
        scanf("%d",&data);
        if(data == 100)break;
        node = treeSearch(tree,data);
        printf("\r\n %d %s存在树中",data,(node == NULL)?("不"):(" "));
    }
    treeDump(tree);
    while(1)
    {
        printf("\r\n删除一个数字，输入100时退出：");
        scanf("%d",&data);
        if(data == 100)break;
        res = treeDelete(tree,data);
        printf("\r\n %d 删除%s成功",data,(res != 0)?("不"):(" "));
        treeDump(tree);
    }
    
    treeDestroyTree(tree);
    
    /********
             7
      4             9
  2       6      8    10
1   3   5
     *******/
    
    return 0;
}
