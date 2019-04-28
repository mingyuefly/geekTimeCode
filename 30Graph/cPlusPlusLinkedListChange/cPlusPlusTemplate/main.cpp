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
#include "LinkedList.hpp"

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
