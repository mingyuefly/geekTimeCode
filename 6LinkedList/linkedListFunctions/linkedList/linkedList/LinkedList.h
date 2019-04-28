//
//  LinkedList.h
//  linkedList
//
//  Created by Gguomingyue on 2019/3/12.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stListNode{
    int val;
    struct stListNode *next;
}ListNode;

/*
 反转链表 // 返回头指针
 */
ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *next = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        if (next == NULL) {
            return head;
        }
        head = next;
    }
    return NULL;
}

void addNode(int nodeVal);

/*
 判断链表是否有环
 */
bool hasCycle(ListNode *head)
{
    ListNode *low = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) {
        low = low->next;
        fast = fast->next->next;
        if (low == fast) {
            return true;
        }
    }
    return false;
}

/*
 找倒环的出口
 */
ListNode * findLoopStart(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (slow == NULL || fast == NULL || fast->next == NULL) {
        return NULL;
    }
    ListNode *ptr1 = head;
    ListNode *ptr2 = slow;
    while (ptr2 != ptr1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        //printf("circle loop");
    }
    return ptr1;
}

/*
 合并有序链表
 */
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode head = {-1, NULL};
    ListNode *pRes = &head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            pRes->next = l1;
            l1 = l1->next;
        } else {
            pRes->next = l2;
            l2 = l2->next;
        }
        pRes = pRes->next;
    }
    if (l1) {
        pRes->next = l1;
    }
    if (l2) {
        pRes->next = l2;
    }
    return head.next;
}

/*
 删除链表倒数第n个节点，并返回头节点
 */
ListNode * removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fast = head;
    ListNode *prev = NULL;
    ListNode *next = head;
    
    int k = n;
    while ((k > 1) && (fast != NULL)) {
        fast = fast->next;
        k--;
    }
    
    if (fast == NULL) {
        // 链表少于n个节点
        return head;
    }
    
    while (fast->next != NULL) {
        fast = fast->next;
        prev = next;
        next = next->next;
    }
    
    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = prev->next->next;
    }
    
    return head;
}

/*
 求链表的中间节点
 */
ListNode * middleNode(ListNode *head)
{
    ListNode * slow = head;
    ListNode * fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

#endif /* LinkedList_h */
