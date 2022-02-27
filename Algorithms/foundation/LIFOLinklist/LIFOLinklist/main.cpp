//
//  main.cpp
//  LIFOLinklist
//
//  Created by mingyue on 2022/2/10.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct Node {
    int value;
    Node * next;
    ~Node() {
        cout << "~Node()" << endl;
    }
}Node;

class Stack {
public:
    Stack() {
        N = 0;
    }
    ~Stack() {
        cout << "~Stack()" << endl;
    }
    bool isEmpty() {
        return N == 0;
    }
    int size() {
        return N;
    }
    void push(int item) {
        Node * oldFirst = first;
        first = new Node();
        first->value = item;
        first->next = oldFirst;
        N++;
    }
    int pop() {
        int item = first->value;
        Node *oldFirst = first;
        first = first->next;
        delete oldFirst;
        N--;
        return item;
    }
private:
    int N;
    Node * first;
};

int main(int argc, const char * argv[]) {
    Stack stack = Stack();
    stack.push(1);
    stack.push(3);
    stack.push(13);
    stack.push(32);
    stack.push(28);
    stack.push(81);
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    return 0;
}
