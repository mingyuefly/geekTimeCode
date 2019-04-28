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
#include<cctype>
#include <vector>
#include <iterator>
#include <list>

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
    int size();//获得链表的长度
    
    //stack
    Any * pop();//出栈一条数据
    void push(Any * data);//入栈一条数据
    
    //queue
    void in(Any * data);//进入队列
    Any * out();//出队列
};




#endif /* LinkedList_hpp */
