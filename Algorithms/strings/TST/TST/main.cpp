//
//  main.cpp
//  TST
//
//  Created by mingyue on 2022/4/7.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    char c;
    Node * left = nullptr;
    Node * mid = nullptr;
    Node * right = nullptr;
    int val = -1;
    Node() {
        
    }
    ~Node() {
        cout << "~Node()" << endl;
    }
private:
};

class TST {
public:
    TST() {
        
    }
    ~TST() {
        cout << "~TST()" << endl;
        for (int i = 0; i < nodes->size(); i++) {
            delete nodes->at(i);
        }
        delete nodes;
    }
    int get(string key) {
        Node * x = get(root, key, 0);
        if (x == nullptr) {
            return -1;
        }
        return x->val;
    }
    void put(string key, int val) {
        root = put(root, key, val, 0);
    }
private:
    Node * root = nullptr;
    vector<Node *> * nodes = new vector<Node *>();
    Node * get(Node * x, string key, int d) {
        if (x == nullptr) {
            return nullptr;
        }
        char c = key.at(d);
        if (c < x->c) {
            return get(x->left, key, d);
        } else if (c > x->c) {
            return get(x->right, key, d);
        } else if (d < key.size() - 1) {
            return get(x->mid, key, d + 1);
        } else {
            return x;
        }
    }
    Node * put(Node * x, string key, int val, int d) {
        char c = key.at(d);
        if (x == nullptr) {
            x = new Node();
            x->c = c;
            nodes->push_back(x);
        }
        if (c < x->c) {
            x->left = put(x->left, key, val, d);
        } else if (c > x->c) {
            x->right = put(x->right, key, val, d);
        } else if (d < key.size() - 1) {
            x->mid = put(x->mid, key, val, d + 1);
        } else {
            x->val = val;
        }
        return x;
    }
};

int main(int argc, const char * argv[]) {
    TST tst = TST();
    tst.put("she", 0);
    cout << tst.get("she");
    cout << endl;
    cout << tst.get("sh");
    cout << endl;
    tst.put("sells", 1);
    cout << tst.get("sells");
    cout << endl;
    cout << tst.get("sell");
    cout << endl;
    tst.put("sea", 2);
    cout << tst.get("sea");
    cout << endl;
    tst.put("shells", 3);
    cout << tst.get("shells");
    cout << endl;
    tst.put("by", 4);
    cout << tst.get("by");
    cout << endl;
    tst.put("the", 5);
    cout << tst.get("the");
    cout << endl;
    tst.put("sea", 6);
    cout << tst.get("sea");
    cout << endl;
    tst.put("shore", 7);
    cout << tst.get("shore");
    cout << endl;
    
    return 0;
}
