//
//  main.cpp
//  TrieST
//
//  Created by mingyue on 2022/4/2.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

static int R = 246;

class Node {
public:
    ~Node() {
        cout << "~Node()" << endl;
    }
    int val = -1;
    vector<Node *> * next = new vector<Node *>(R, nullptr);
private:
};

class TrieST {
public:
    TrieST () {
        
    }
    ~TrieST () {
        cout << "~TrieST ()" << endl;
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
        if (d == key.size()) {
            return x;
        }
        char c = key.at(d);
        return get(x->next->at(c), key, d + 1);
    }
    Node * put(Node * x, string key, int val, int d) {
        if (x == nullptr) {
            x = new Node();
            nodes->push_back(x);
        }
        if (d == key.size()) {
            x->val = val;
            return x;
        }
        char c = key.at(d);
        x->next->at(c) = put(x->next->at(c), key, val, d + 1);
        return x;
    }
};

int main(int argc, const char * argv[]) {
    
    TrieST trieST = TrieST();
    trieST.put("she", 0);
    cout << trieST.get("she");
    cout << endl;
    cout << trieST.get("sh");
    cout << endl;
    trieST.put("sells", 1);
    cout << trieST.get("sells");
    cout << endl;
    cout << trieST.get("sell");
    cout << endl;
    trieST.put("sea", 2);
    cout << trieST.get("sea");
    cout << endl;
    trieST.put("shells", 3);
    cout << trieST.get("shells");
    cout << endl;
    trieST.put("by", 4);
    cout << trieST.get("by");
    cout << endl;
    trieST.put("the", 5);
    cout << trieST.get("the");
    cout << endl;
    trieST.put("sea", 6);
    cout << trieST.get("sea");
    cout << endl;
    trieST.put("shore", 7);
    cout << trieST.get("shore");
    cout << endl;
    
    return 0;
}
