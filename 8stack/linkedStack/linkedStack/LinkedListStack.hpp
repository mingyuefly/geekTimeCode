//
//  LinkedListStack.hpp
//  linkedStack
//
//  Created by Gguomingyue on 2019/4/9.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef LinkedListStack_hpp
#define LinkedListStack_hpp

#include <stdio.h>
#include <iostream>
using namespace std;



template <class T>
class LinkedListStack {
public:
    LinkedListStack();
    ~LinkedListStack();
    void push(const T & data);
    T peek();
    T pop();
    int size() const;
private:
    int count;
    struct LinkedNode
    {
        T data;
        LinkedNode * next;
    };
    LinkedNode * head;
};

template <class T>
LinkedListStack<T>::LinkedListStack()
{
    this->count = 0;
    this->head = new LinkedNode();
    this->head->next = NULL;
}

template <class T>
LinkedListStack<T>::~LinkedListStack()
{
    LinkedNode * ptr, * temp;
    ptr = head;
    while (ptr->next != NULL) {
        temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
    }
    delete head;
    this->head = NULL;
    this->count = 0;
}

// 入栈
template <class T>
void LinkedListStack<T>::push(const T &data)
{
    LinkedNode * insertPtr = new LinkedNode;
    insertPtr->data = data;
    insertPtr->next = this->head->next;
    head->next = insertPtr;
    this->count++;
    cout << "push data : " << this->head->next->data << endl;
}

// 返回栈顶元素
template <class T>
T LinkedListStack<T>::peek()
{
    if (this->count == 0 || this->head->next == NULL) {
        cout << "stack is empty, peek fail" << endl;
        return NULL;
    } else {
        return this->head->next->data;
    }
}

// 出栈
template <class T>
T LinkedListStack<T>::pop()
{
    if (this->count == 0 || this->head->next == NULL) {
        cout << "stack is empty, pop fail" << endl;
        return NULL;
    } else {
        LinkedNode * temp = this->head->next;
        this->head->next = temp->next;
        T data = temp->data;
        delete temp;
        this->count--;
        return data;
    }
}

// 返回栈的大小
template <class T>
int LinkedListStack<T>::size() const
{
    return this->count;
}





#endif /* LinkedListStack_hpp */
