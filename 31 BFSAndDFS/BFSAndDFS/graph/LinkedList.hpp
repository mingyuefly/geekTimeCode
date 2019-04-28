//
//  LinkedList.hpp
//  graph
//
//  Created by Gguomingyue on 2019/2/22.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>
//#include<cctype>
//#include <vector>
//#include <iterator>
//#include <list>
//#include <cstdlib>
//#include <stdexcept>


//#include "Student.hpp"
using namespace std;

template<class Any>
struct Node{
    Node<Any> * prior;
    Any * data;
    Node<Any> * next;
};

template<class Any>
class LinkedList{
    Node<Any> * head;//头结点
    Node<Any> * tail;//尾结点
    int length;//链表长度
    Node<Any> * getNode(int index){
        //获得index位置的结点数据
        if(index < 0 || index > length){
            return NULL;
        }else{
            Node<Any> *temp = head->next;
            for(int i = 0; i < index; i++, temp = temp->next);
            return temp;
        }
    };
    
public:
    LinkedList();
    ~LinkedList();
    
    //list
    void add(Any * data);//添加数据
    Any * get(int index);//获取index位置上的数据
    bool add(int index,Any * data);//向index位置上添加一条数据
    void addFirst(Any* data);//向链表头部添加一条数据
    void addLast(Any* data);//向链表尾部添加一条数据
    Any * remove(int index);//移除index位置上的数据
    Any * removeFirst();//移除链表第一个元素
    Any * removeLast();//移除链表最后一个元素
    void removeAll();//移除链表上所有元素
    int size();//获得链表的长度
    
    //stack
    Any * pop();//出栈一条数据
    void push(Any * data);//入栈一条数据
    
    //queue
    void in(Any * data);//进入队列
    Any * out();//出队列
};

template<class Any>
LinkedList<Any>::LinkedList(){
    head = new Node<Any>;
    tail = new Node<Any>;
    head->data = NULL;
    head->next = tail;
    head->prior = NULL;
    tail->data = NULL;
    tail->prior = head;
    tail->next = NULL;
    length = 0;
}

template<class Any>
LinkedList<Any>::~LinkedList(){
    for(int i = 0;i < length + 2;i++){
        Node<Any> * temp = head;
        head = head->next;
        Any * data = temp->data;
        if(data != NULL){
            delete data;
        }
        delete temp;
    }
    cout << "~LinkedList()" << endl;
}

// list
template<class Any>
void LinkedList<Any>::add(Any * data){
    addLast(data);
}

template<class Any>
Any * LinkedList<Any>::get(int index){
    Node<Any>* temp = getNode(index);
    if(temp == NULL){
        return NULL;
    }else{
        return temp->data;
    }
}

template<class Any>
bool LinkedList<Any>::add(int index,Any * data){
    if(index < 0||index > length){
        return false;
    }else if(index == 0){
        addFirst(data);
    }else if(index == length){
        addLast(data);
    }else{
        Node<Any> *temp = getNode(index-1);
        Node<Any> *node = new Node<Any>;
        node->data = data;
        node->prior = temp;
        node->next = temp->next;
        temp->next->prior = node;
        temp->next = node;
        length++;
    }
    return true;
}

template<class Any>
void LinkedList<Any>::addFirst(Any* data){
    Node<Any> * node = new Node<Any>;
    node->data = data;
    node->prior = head;;
    node->next = head->next;
    node->next->prior = node;
    head->next = node;
    length++;
}

template<class Any>
void LinkedList<Any>::addLast(Any* data){
    Node<Any> * node = new Node<Any>;
    node->data = data;
    node->next = tail;
    node->prior = tail->prior;
    node->prior->next = node;
    tail->prior = node;
    length++;
}

template<class Any>
Any * LinkedList<Any>::remove(int index){
    if(index < 0||index > length){
        return NULL;
    }else if(index==0){
        return removeFirst();
    }else if(index == length){
        return removeLast();
    }else{
        Node<Any> *temp = getNode(index);
        if(temp == NULL){
            return NULL;
        }else{
            Any * data = temp->data;
            delete temp;
            length--;
            return data;
        }
    }
}

template<class Any>
Any * LinkedList<Any>::removeFirst(){
    if(length == 0){
        return NULL;
    }else{
        Node<Any> * temp = head->next;
        Any * data = temp->data;
        head->next = temp->next;
        head->next->prior = head;
        delete temp;
        length--;
        return data;
    }
}

template<class Any>
Any * LinkedList<Any>::removeLast(){
    if(length == 0){
        return NULL;
    }else{
        Node<Any> * temp = tail->prior;
        Any* data = temp->data;
        tail->prior = temp->prior;
        tail->prior->next = tail;
        delete temp;
        length--;
        return data;
    }
}

template <class Any>
void LinkedList<Any>::removeAll() {
    if (length == 0) {
        return;
    } else {
        for (int i = 0; i < length; i++) {
            Node<Any> * node = get(i);
            delete node;
        }
        head->next = tail;
        tail->prior = head;
    }
}

template<class Any>
int LinkedList<Any>::size(){
    return length;
}

// stack
template<class Any>
Any * LinkedList<Any>::pop(){
    return removeLast();
}

template<class Any>
void LinkedList<Any>::push(Any * data){
    addLast(data);
}

// queue
template<class Any>
void LinkedList<Any>::in(Any * data){
    addLast(data);
}
template<class Any>
Any * LinkedList<Any>::out(){
    return removeFirst();
}






#endif /* LinkedList_hpp */
