//
//  main.cpp
//  LIFOArray
//
//  Created by mingyue on 2022/2/9.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

template <typename Item>
class ResizingArrayStack {
public:
    ResizingArrayStack() {
        N = 0;
        items = new vector<Item>(2);
    }
    ~ResizingArrayStack() {
        cout << "~ResizingArrayStack()" << endl;
        delete items;
    }
    bool isEmpty() {
        return N == 0;
    }
    int size() {
        return N;
    }
    void push(Item item) {
        if (N == items->size()) {
            resize(2 * int(items->size()));
        }
        items->at(N++) = item;
    }
    int pop() {
        int item = items->at(--N);
        items->at(N) = -1;
        if (N > 0 && N == items->size() / 4) {
            resize(int(items->size()) / 2);
        }
        return item;
    }
private:
    vector<int> *items;
    int N;
    void resize(int max) {
        cout << "resize" << endl;
        items->resize(max);
    }
};

int main(int argc, const char * argv[]) {
    ResizingArrayStack<int> stack;
    stack.push(1);
    stack.push(3);
    stack.push(7);
    stack.push(9);
    stack.push(18);
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    return 0;
}






////template <typename Item>
//class ResizingArrayStack {
//public:
//    ResizingArrayStack() {
//        N = 0;
//        items = new vector<int>(2);
//    }
//    ~ResizingArrayStack() {
//        cout << "~ResizingArrayStack()" << endl;
//        delete items;
//    }
//    bool isEmpty() {
//        return N == 0;
//    }
//    int size() {
//        return N;
//    }
//    void push(int item) {
//        if (N == items->size()) {
//            resize(2 * int(items->size()));
//        }
//        items->at(N++) = item;
//    }
//    int pop() {
//        int item = items->at(--N);
//        items->at(N) = -1;
//        if (N > 0 && N == items->size() / 4) {
//            resize(int(items->size()) / 2);
//        }
//        return item;
//    }
//private:
//    vector<int> *items;
//    int N;
//    void resize(int max) {
//        cout << "resize" << endl;
//        items->resize(max);
//    }
//};
//
//int main(int argc, const char * argv[]) {
//    ResizingArrayStack stack = ResizingArrayStack();
//    stack.push(1);
//    stack.push(3);
//    stack.push(7);
//    stack.push(9);
//    stack.push(18);
//    cout << stack.pop() << endl;
//    cout << stack.pop() << endl;
//    cout << stack.pop() << endl;
//    cout << stack.pop() << endl;
//    cout << stack.pop() << endl;
//    return 0;
//}
