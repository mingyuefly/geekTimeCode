//
//  Dlist.h
//  linkedList
//
//  Created by Gguomingyue on 2019/3/7.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef Dlist_h
#define Dlist_h

#include <stdio.h>
#include <stdlib.h>

// 链表节点结构
typedef struct DlistNode {
    struct DlistNode *prev;
    struct DlistNode *next;
    int data;
}stDlistNode;

// 哨兵，包含头尾空节点
typedef struct DlistHead {
    int size;
    stDlistNode *head;
    stDlistNode *tail;
}stDlistHead;

// 创建链表
void dlist_init(stDlistHead * dlist);

// 销毁链表
void dlist_destroy(stDlistHead * dlist);

// 插入头部
int dlist_insert_head(stDlistHead * dlist, stDlistNode *pNode, int data);

// 删除尾部
stDlistNode * dlist_remove_tail(stDlistHead * dlist);

// 删除节点
void dlist_remove_node(stDlistHead *dlist, stDlistNode *pNode);

// 寻找节点
stDlistNode * dlist_search(stDlistHead *dlist, int data);

// 遍历节点
void dlist_dump(stDlistHead *dlist);

// 缓存
void Lru_dlist(stDlistHead * dlist, int data);


#endif /* Dlist_h */

