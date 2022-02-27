//
//  main.cpp
//  redBlackTree
//
//  Created by mingyue on 2022/2/21.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>

using namespace std;

static bool RED = true;
static bool BLACK = false;

typedef struct Comparable {
public:
    Comparable() {
        
    }
    Comparable(int value) {
        this->value = value;
    }
    int value;
    int compareTo(Comparable a) {
        return value - a.value;
    }
    ~Comparable() {
        cout << "~Comparable()" << endl;
    }
}Comparable;

typedef struct Node {
public:
    Node() {
        
    }
    Node(Comparable key, int value, int N, bool color) {
        this->key = key;
        this->value = value;
        this->N = N;
        this->left = nullptr;
        this->right = nullptr;
        this->color = color;
    }
    ~Node() {
        cout << "~Node()" << endl;
        delete left;
        delete right;
    }
    Comparable key;
    int value;
    Node * left;
    Node * right;
    int N;
    bool color;
private:
}Node;

class RedBlackBST {
public:
    RedBlackBST() {
        
    }
    ~RedBlackBST() {
        cout << "~RedBlackBST()" << endl;
        delete root;
    }
    int size() {
        return size(root);
    }
    void put(Comparable key, int value) {
        
    }
private:
    Node * root;
    int size(Node * x) {
        if (x == nullptr) {
            return 0;
        } else {
            return x->N;
        }
    }
    bool isRed(Node * x) {
        if (x == nullptr) {
            return false;
        }
        return x->color == RED;
    }
    Node * rotateLeft(Node * h) {
        Node * x = h->right;
        h->right = x->left;
        x->left = h;
        x->color = h->color;
        h->color = RED;
        x->N = h->N;
        h->N = 1 + size(h->left) + size(h->right);
        return x;
    }
    Node * rotateRight(Node * h) {
        Node * x = h->left;
        h->left = x->right;
        x->right = h;
        x->color = h->color;
        h->color = RED;
        x->N = h->N;
        h->N = 1 + size(h->left) + size(h->right);
        return x;
    }
    void flipColors(Node * h) {
        h->color = RED;
        h->left->color = BLACK;
        h->right->color = BLACK;
    }
    Node * put(Node * h, Comparable key, int value) {
        if (h == nullptr) {
            return new Node(key, value, 1, RED);
        }
        int cmp = key.compareTo(h->key);
        if (cmp < 0) {
            h->left = put(h->left, key, value);
        } else if (cmp > 0) {
            h->right = put(h->right, key, value);
        } else {
            h->value = value;
        }
        if (isRed(h->right) && !isRed(h->left)) {
            h = rotateLeft(h);
        }
        if (isRed(h->left) && isRed(h->left->left)) {
            h = rotateRight(h);
        }
        if (isRed(h->left) && isRed(h->right)) {
            flipColors(h);
        }
        h->N = size(h->left) + size(h->right) + 1;
        return h;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
