//
//  LinkedList.cpp
//  cPlusPlusTemplate
//
//  Created by gomeguomingyue on 2019/2/25.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "LinkedList.hpp"



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
}

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

template<class Any>
int LinkedList<Any>::size(){
    return length;
}

template<class Any>
Any * LinkedList<Any>::pop(){
    return removeLast();
}

template<class Any>
void LinkedList<Any>::push(Any * data){
    addLast(data);
}

template<class Any>
void LinkedList<Any>::in(Any * data){
    addLast(data);
}
template<class Any>
Any * LinkedList<Any>::out(){
    return removeFirst();
}


