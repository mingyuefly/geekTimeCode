//
//  LinkedList.cpp
//  graph
//
//  Created by Gguomingyue on 2019/2/22.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "LinkedList.hpp"

//template<class Any>
LinkedList::LinkedList(){
    head = new Node;
    tail = new Node;
    head->data = NULL;
    head->next = tail;
    head->prior = NULL;
    tail->data = NULL;
    tail->prior = head;
    tail->next = NULL;
    length = 0;
}

//template<class Any>
LinkedList::~LinkedList(){
    for(int i = 0;i < length + 2;i++){
        Node * temp = head;
        head = head->next;
        Student * data = temp->data;
        if(data != NULL){
            delete data;
        }
        delete temp;
    }
}

//template<class Any>
void LinkedList::add(Student * data){
    addLast(data);
}

//template<class Any>
Student * LinkedList::get(int index){
    Node * temp = getNode(index);
    if(temp == NULL){
        return NULL;
    }else{
        return temp->data;
    }
}

//template<class Any>
bool LinkedList::add(int index,Student * data){
    if(index < 0||index > length){
        return false;
    }else if(index == 0){
        addFirst(data);
    }else if(index == length){
        addLast(data);
    }else{
        Node *temp = getNode(index-1);
        Node *node = new Node;
        node->data = data;
        node->prior = temp;
        node->next = temp->next;
        temp->next->prior = node;
        temp->next = node;
        length++;
    }
    return true;
}

//template<class Any>
void LinkedList::addFirst(Student * data){
    Node * node = new Node;
    node->data = data;
    node->prior = head;;
    node->next = head->next;
    node->next->prior = node;
    head->next = node;
    length++;
}

//template<class Any>
void LinkedList::addLast(Student * data){
    Node * node = new Node;
    node->data = data;
    node->next = tail;
    node->prior = tail->prior;
    node->prior->next = node;
    tail->prior = node;
    length++;
}

//template<class Any>
Student * LinkedList::remove(int index){
    if(index < 0||index > length){
        return NULL;
    }else if(index==0){
        return removeFirst();
    }else if(index == length){
        return removeLast();
    }else{
        Node *temp = getNode(index);
        if(temp == NULL){
            return NULL;
        }else{
            Student * data = temp->data;
            delete temp;
            length--;
            return data;
        }
    }
}

//template<class Any>
Student * LinkedList::removeFirst(){
    if(length == 0){
        return NULL;
    }else{
        Node * temp = head->next;
        Student * data = temp->data;
        head->next = temp->next;
        head->next->prior = head;
        delete temp;
        length--;
        return data;
    }
}

//template<class Any>
Student * LinkedList::removeLast(){
    if(length == 0){
        return NULL;
    }else{
        Node * temp = tail->prior;
        Student * data = temp->data;
        tail->prior = temp->prior;
        tail->prior->next = tail;
        delete temp;
        length--;
        return data;
    }
}

//template<class Any>
int LinkedList::size(){
    return length;
}

//template<class Any>
Student * LinkedList::pop(){
    return removeLast();
}

//template<class Any>
void LinkedList::push(Student * data){
    addLast(data);
}

//template<class Any>
void LinkedList::in(Student * data){
    addLast(data);
}
//template<class Any>
Student * LinkedList::out(){
    return removeFirst();
}

