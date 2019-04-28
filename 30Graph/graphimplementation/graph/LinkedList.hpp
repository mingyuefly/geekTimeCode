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
//#include "Student.hpp"

using namespace std;

//template<class Any>
struct Node{
    Node * prior;
    int data;
    Node * next;
};

//template<class Any>
class LinkedList{
    Node * head;//头结点
    Node * tail;//尾结点
    int length;//链表长度
    Node * getNode(int index){
        //获得index位置的结点数据
        if(index < 0 || index > length){
            return NULL;
        }else{
            Node * temp = head->next;
            for(int i = 0; i < index; i++, temp = temp->next);
            return temp;
        }
    };
    
public:
    LinkedList();
    ~LinkedList();
    
    //list
    void add(int data);//添加数据
    int get(int index);//获取index位置上的数据
    bool add(int index,int data);//向index位置上添加一条数据
    void addFirst(int data);//向链表头部添加一条数据
    void addLast(int data);//向链表尾部添加一条数据
    int remove(int index);//移除index位置上的数据
    int removeFirst();//移除链表第一个元素
    int removeLast();//移除链表最后一个元素
    int size();//获得链表的长度
    
    //stack
    int pop();//出栈一条数据
    void push(int data);//入栈一条数据
    
    //queue
    void in(int data);//进入队列
    int out();//出队列
};




#endif /* LinkedList_hpp */
