//
//  Dlist.c
//  linkedList
//
//  Created by Gguomingyue on 2019/3/7.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "Dlist.h"
#include <string.h>


// 创建链表
void dlist_init(stDlistHead * dlist)
{
    dlist->size = 0;
    dlist->head = NULL;
    dlist->tail = NULL;
}

// 销毁链表
void dlist_destroy(stDlistHead * dlist)
{
    stDlistNode * pNode = NULL;
    while (dlist->size > 0) {
        pNode = dlist->head;
        dlist->head = dlist->head->next;
        free(pNode);
        dlist->size--;
    }
    memset(dlist, 0, sizeof(stDlistHead));
    return;
}

// 插入头部
int dlist_insert_head(stDlistHead * dlist, stDlistNode *pNode, int data)
{
    if (pNode == NULL) {
        pNode = (stDlistNode *)malloc(sizeof(pNode));
        if (pNode == NULL) {
            return -1;
        }
    }
    pNode->data = data;
    pNode->prev = NULL;//链表首节点前向指针为空
    pNode->next = NULL;
    
    if (dlist->size == 0) {
        dlist->head = pNode;
        dlist->tail = pNode;
    } else {
        pNode->next = dlist->head;
        dlist->head->prev = pNode;
        dlist->head = pNode;
    }
    dlist->size++;
    return 0;
}

// 删除尾部
stDlistNode * dlist_remove_tail(stDlistHead * dlist)
{
    stDlistNode * pNode = NULL;
    if (dlist->size == 0) {
        return NULL;
    }
    pNode = dlist->tail;
    if (dlist->size > 1) {
        dlist->tail = dlist->tail->prev;
        dlist->tail->next = NULL;//尾部节点的后向指针为空
    } else {
        dlist->head = NULL;
        dlist->tail = NULL;
    }
    dlist->size--;
    return pNode;
}

// 删除节点
void dlist_remove_node(stDlistHead *dlist, stDlistNode *pNode)
{
    if (dlist == NULL || pNode == NULL) {
        return;
    }
    if (dlist->head == pNode) {
        dlist->head = dlist->head->next;
    } else if (dlist->tail == pNode) {
        dlist->tail = dlist->tail->prev;
    } else {
        pNode->prev->next = pNode->next;
        pNode->next->prev = pNode->prev;
    }
    dlist->size--;
    pNode->prev = NULL;
    pNode->next = NULL;
    if (dlist->size == 0) {
        memset(dlist,0,sizeof(stDlistHead));
    }
}

// 寻找节点
stDlistNode * dlist_search(stDlistHead * dlist, int data)
{
    stDlistNode *pNode = dlist->head;
    while (pNode != NULL) {
        if (pNode->data == data) {
            return pNode;
        }
        pNode = pNode->next;
    }
    return NULL;
}

// 遍历节点
void dlist_dump(stDlistHead *dlist)
{
    int no = 0;
    stDlistNode *pNode = dlist->head;
    while (pNode != NULL) {
        printf("\r\n [%d] = %d", no++, pNode->data);
        pNode = pNode->next;
    }
    return;
}

// 缓存
void Lru_dlist(stDlistHead * dlist, int data)
{
    stDlistNode * pNode = NULL;
    pNode = dlist_search(dlist, data);
    if (pNode != NULL) {
        dlist_remove_node(dlist, pNode);
    } else if (dlist->size >= 4) {
        pNode = dlist_remove_tail(dlist);
    }
    dlist_insert_head(dlist, pNode, data);
}
