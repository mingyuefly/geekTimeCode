//
//  main.cpp
//  cPlusPlusTemplate
//
//  Created by Gguomingyue on 2019/2/25.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

#include "Student.hpp"

using namespace std;

template <class T>
class Stack {
private:
    vector<T> elems;     // 元素
    
public:
    void push(T const&);  // 入栈
    void pop();               // 出栈
    T top() const;            // 返回栈顶元素
    bool empty() const{       // 如果为空则返回真。
        return elems.empty();
    }
};

template <class T>
void Stack<T>::push (T const& elem)
{
    // 追加传入元素的副本
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop ()
{
    if (elems.empty()) {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    // 删除最后一个元素
    elems.pop_back();
}

template <class T>
T Stack<T>::top () const
{
    if (elems.empty()) {
        throw out_of_range("Stack<>::top(): empty stack");
    }
    // 返回最后一个元素的副本
    return elems.back();
}

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





int main()
{
    Stack<int>         intStack;  // int 类型的栈
    Stack<string> stringStack;    // string 类型的栈
    Stack<Student> studentStack;  // student 类型的栈
    
    // 操作 int 类型的栈
    intStack.push(7);
    cout << intStack.top() <<endl;
    
    // 操作 string 类型的栈
    stringStack.push("hello");
    cout << stringStack.top() << std::endl;
    //stringStack.pop();
    //stringStack.pop();
    
    Student stu1 = Student("Jack", 98, 99, 100);
    Student stu2 = Student("Sam", 99, 90, 99);
    Student stu3 = Student("Sue", 97, 99, 87);
    
    studentStack.push(stu1);
    cout << studentStack.top().name << std::endl;
    //cout << studentStack.top().name << std::endl;
    //cout << studentStack.top().name << std::endl;
    
    //        stu1.show();
    //        stu2.show();
    //        stu3.show();
    
    Student *stu4 = new Student("Jim", 88, 89, 100);
    Student *stu5 = new Student("Tom", 89, 80, 99);
    Student *stu6 = new Student("Kelly", 87, 89, 87);
    
    LinkedList<Student> * list = new LinkedList<Student>();
    list->add(stu4);
    list->add(stu5);
    list->add(stu6);
    
    for(int i=0; i<list->size(); i++){
        list->get(i)->show();
    }
    
    delete list;
    
    return 0;
}
