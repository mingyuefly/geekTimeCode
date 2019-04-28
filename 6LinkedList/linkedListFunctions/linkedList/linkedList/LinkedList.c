//
//  LinkedList.c
//  linkedList
//
//  Created by Gguomingyue on 2019/3/12.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "LinkedList.h"

void addNode(int nodeVal)
{
    
}

/*
 反转链表
 */
//ListNode *reverseList(ListNode *head)
//{
//    ListNode *prev = NULL;
//    ListNode *next = NULL;
//    while (head != NULL) {
//        next = head->next;
//        head->next = prev;
//        prev = head;
//        head = next;
//    }
//    return head;
//}

/*
 判断链表是否有环
 */
//int hasCycle(ListNode *head)
//{
//    ListNode *low = head;
//    ListNode *fast = head;
//    while (fast != NULL && fast->next != NULL) {
//        low = low->next;
//        fast = fast->next->next;
//        if (low == fast) {
//            return 1;
//        }
//    }
//    return 0;
//}



/*
 合并有序链表
 */
//ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
//{
//    return NULL;
//}
