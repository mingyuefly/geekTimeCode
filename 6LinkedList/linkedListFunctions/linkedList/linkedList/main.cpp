//
//  main.cpp
//  linkedList
//
//  Created by Gguomingyue on 2019/3/12.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->val = 0;
    
    ListNode *node1 = (ListNode *)malloc(sizeof(ListNode));
    node1->val = 2;
    head->next = node1;
    
    ListNode *node2 = (ListNode *)malloc(sizeof(ListNode));
    node2->val = 5;
    node1->next = node2;
    
    ListNode *node3 = (ListNode *)malloc(sizeof(ListNode));
    node3->val = 7;
    node2->next = node3;
    
    ListNode *node4 = (ListNode *)malloc(sizeof(ListNode));
    node4->val = 8;
    node3->next = node4;
    
    ListNode *node5 = (ListNode *)malloc(sizeof(ListNode));
    node5->val = 13;
    //node5->next = node3;
    node5->next = NULL;
    node4->next = node5;
    
    //ListNode *newHead = reverseList(head);
    int hasCircle = hasCycle(head);
    cout << hasCircle << endl;
    
    if (!hasCircle) {
        ListNode *lHead = head;
        //ListNode *lHead = newHead;
        while (lHead) {
            cout << lHead->val << " ";
            lHead = lHead->next;
        }
        cout << endl;
    } else {
        ListNode * prtNode = findLoopStart(head);
        cout << prtNode->val << endl;
    }
    
    ListNode *headt = (ListNode *)malloc(sizeof(ListNode));
    headt->val = 1;
    
    ListNode *nodet1 = (ListNode *)malloc(sizeof(ListNode));
    nodet1->val = 4;
    headt->next = nodet1;
    
    ListNode *nodet2 = (ListNode *)malloc(sizeof(ListNode));
    nodet2->val = 5;
    nodet1->next = nodet2;
    
    ListNode *nodet3 = (ListNode *)malloc(sizeof(ListNode));
    nodet3->val = 9;
    nodet2->next = nodet3;
    
    ListNode *nodet4 = (ListNode *)malloc(sizeof(ListNode));
    nodet4->val = 17;
    nodet3->next = nodet4;
    
    ListNode *nodet5 = (ListNode *)malloc(sizeof(ListNode));
    nodet5->val = 21;
    //node5->next = node3;
    nodet5->next = NULL;
    nodet4->next = nodet5;
    
    int hasCirclet = hasCycle(headt);
    cout << hasCirclet << endl;
    
    if (!hasCirclet) {
        ListNode *lHead = headt;
        //ListNode *lHead = newHead;
        while (lHead) {
            cout << lHead->val << " ";
            lHead = lHead->next;
        }
        cout << endl;
    } else {
        ListNode * prtNode = findLoopStart(headt);
        cout << prtNode->val << endl;
    }
    
    ListNode *headMerge = mergeTwoLists(head, headt);
    int hasCircleMerge = hasCycle(headMerge);
    cout << hasCircleMerge << endl;
    
    if (!hasCircleMerge) {
        ListNode *lHead = headMerge;
        //ListNode *lHead = newHead;
        while (lHead) {
            cout << lHead->val << " ";
            lHead = lHead->next;
        }
        cout << endl;
    } else {
        ListNode * prtNode = findLoopStart(headMerge);
        cout << prtNode->val << endl;
    }
    
    ListNode * middleheadMerge = middleNode(headMerge);
    cout << middleheadMerge->val << endl;
    
    ListNode *headAfterRemove = removeNthFromEnd(headMerge, 5);
    int hasCircleAfterRemove = hasCycle(headAfterRemove);
    cout << hasCircleAfterRemove << endl;
    if (!hasCircleAfterRemove) {
        ListNode *lHead = headAfterRemove;
        //ListNode *lHead = newHead;
        while (lHead) {
            cout << lHead->val << " ";
            lHead = lHead->next;
        }
        cout << endl;
    } else {
        ListNode * prtNode = findLoopStart(headAfterRemove);
        cout << prtNode->val << endl;
    }
    
    ListNode * middleheadAfterRemove = middleNode(headAfterRemove);
    cout << middleheadAfterRemove->val << endl;
    
    return 0;
}
