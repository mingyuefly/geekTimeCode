//
//  main.cpp
//  linkedStack
//
//  Created by Gguomingyue on 2019/4/9.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>
#include "LinkedListStack.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << " === StackBasedOnLinkedList test begin ===" << endl;
    LinkedListStack<float> stack;
    cout << "size ==== " << stack.size() << endl;
    stack.push(10.1);
    stack.push(20.2);
    stack.push(30.3);
    stack.push(40.4);
    stack.push(50.5);
    stack.push(60.6);
    cout << "size ==== " << stack.size() << endl;
    cout << "stack peek  " << stack.peek() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "size==="<<stack.size()<<endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "size==="<<stack.size()<<endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack peek  " << stack.peek() << endl;
    stack.push(110.1);
    stack.push(120.2);
    stack.push(130.3);
    stack.push(140.4);
    stack.push(150.5);
    stack.push(160.6);
    cout << "size==="<<stack.size()<<endl;
    cout << "stack peek  " << stack.peek() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack peek  " << stack.peek() << endl;   //peek
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "size==="<<stack.size()<<endl;
    cout << "stack peek  " << stack.peek() << endl;   //peek
    cout << "stack pop  " << stack.pop() << endl;
    //system("pause");
    
    return 0;
}
