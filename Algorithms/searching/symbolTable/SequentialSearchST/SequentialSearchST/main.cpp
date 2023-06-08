//
//  main.cpp
//  SequentialSearchST
//
//  Created by mingyue on 2022/2/8.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct Comparable {
public:
    int value;
    int compareTo(Comparable a) {
        return value - a.value;
    }
}Comparable;

typedef struct Node {
public:
    Comparable key;
    int val;
    Node *next;
    Node(Comparable key, int val, Node *next) {
        this->key = key;
        this->val = val;
        this->next = next;
    }
    ~Node() {
        cout << "~Node()" << endl;
    }
}Node;

class SequentialSearchST {
public:
    SequentialSearchST() {
        first = nullptr;
    }
    int get(Comparable key) {
        Node *head = first;
        while (head != nullptr) {
            if (key.compareTo(head->key) == 0) {
                return head->val;
            }
            head = head->next;
        }
        return -1;
    }
    void put(Comparable key, int val) {
        Node *head = first;
        while (head != nullptr) {
            if (key.compareTo(head->key) == 0) {
                head->val = val;
                return;
            }
            head = head->next;
        }
        this->first = new Node(key, val, this->first);
    }
    void deleteKey(Comparable key) {
        Node *pre = nullptr;
        Node *head = first;
        while (head != nullptr) {
            if (key.compareTo(head->key) == 0) {
                if (head == first) {
                    first = head->next;
                } else {
                    pre->next = head->next;
                }
                delete head;
                break;
            }
            pre = head;
            head = head->next;
        }
    }
    void show() {
        for (Node *head = first; head != NULL; head = head->next) {
            cout << "(" << head->key.value << ":" << head->val << ")" << endl;
        }
        cout << endl;
    }
    ~SequentialSearchST() {
        cout << "~SequentialSearchST()" << endl;
        Node *head = first;
        while (head != nullptr) {
            Node *tmpH = head;
            head = head->next;
            delete tmpH;
        }
    }
private:
    Node *first;
};

int main(int argc, const char * argv[]) {
    SequentialSearchST st = SequentialSearchST();
    
    Comparable key0 = Comparable();
    key0.value = 1;
    Comparable key1 = Comparable();
    key1.value = 2;
    Comparable key2 = Comparable();
    key2.value = 3;
    Comparable key3 = Comparable();
    key3.value = 4;
    Comparable key4 = Comparable();
    key4.value = 5;
    Comparable key5 = Comparable();
    key5.value = 6;
    
    int v0 = 11;
    int v1 = 12;
    int v2 = 13;
    int v3 = 14;
    int v4 = 15;
    int v5 = 16;
    
    st.put(key0, v0);
    st.show();
    st.put(key1, v1);
    st.show();
    st.put(key2, v2);
    st.show();
    st.put(key3, v3);
    st.show();
    st.put(key4, v4);
    st.show();
    st.put(key5, v5);
    st.show();
    
    st.deleteKey(key2);
    st.show();
    
    st.deleteKey(key5);
    st.show();
    
    return 0;
}
