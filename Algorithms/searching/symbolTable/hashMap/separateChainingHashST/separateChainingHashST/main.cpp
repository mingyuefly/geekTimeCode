//
//  main.cpp
//  separateChainingHashST
//
//  Created by mingyue on 2022/2/23.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>

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
        first = NULL;
    }
    int get(Comparable key) {
        for (Node *head = first; head != NULL; head = head->next) {
            if (key.compareTo(head->key) == 0) {
                return head->val;
            }
        }
        return -1;
    }
    void put(Comparable key, int val) {
        for (Node *head = first; head != NULL; head = head->next) {
            if (key.compareTo(head->key) == 0) {
                head->val = val;
                return;
            }
        }
        this->first = new Node(key, val, this->first);
    }
    void deleteKey(Comparable key) {
        Node *pre = first;
        for (Node *head = first; head != NULL; head = head->next) {
            if (key.compareTo(head->key) == 0) {
                pre->next = head->next;
                delete head;
                break;
            }
            pre = head;
        }
    }
    void show() {
        for (Node *head = first; head != NULL; head = head->next) {
            cout << "(" << head->key.value << ":" << head->val << ")" << " ";
        }
        cout << endl;
    }
    ~SequentialSearchST() {
        cout << "~SequentialSearchST()" << endl;
        for (Node *head = first; head != NULL; head = head->next) {
            delete head;
        }
    }
private:
    Node *first;
};

class SeparateChainingHashST {
public:
    SeparateChainingHashST() {
        
    }
    SeparateChainingHashST(int M) {
        this->M = M;
        st = new vector<SequentialSearchST *>(M);
        for (int i = 0; i < M; i++) {
            st->at(i) = new SequentialSearchST();
        }
    }
    ~SeparateChainingHashST() {
        cout << "~SeparateChainingHashST()" << endl;
        for (int i = 0; i < M; i++) {
            delete st->at(i);
        }
    }
    int get(Comparable key) {
        return st->at(hash(key))->get(key);
    }
    void put(Comparable key, int value) {
        st->at(hash(key))->put(key, value);
    }
    void deleteKey(Comparable key) {
        st->at(hash(key))->deleteKey(key);
    }
    void show() {
        for (int i = 0; i < M; i++) {
            st->at(i)->show();
        }
    }
private:
    int N;
    int M;
    vector<SequentialSearchST *> * st;
    int hash(Comparable key) {
        return key.value % 1000;
    }
};

int main(int argc, const char * argv[]) {
    
    SeparateChainingHashST scst = SeparateChainingHashST(100);
    
    Comparable key0 = Comparable();
    key0.value = 1001;
    Comparable key1 = Comparable();
    key1.value = 1002;
    Comparable key2 = Comparable();
    key2.value = 1003;
    Comparable key3 = Comparable();
    key3.value = 1004;
    Comparable key4 = Comparable();
    key4.value = 10003;
    Comparable key5 = Comparable();
    key5.value = 1006;
    Comparable key6 = Comparable();
    key6.value = 1016;
    Comparable key7 = Comparable();
    key7.value = 10006;
    Comparable key8 = Comparable();
    key8.value = 1007;
    Comparable key9 = Comparable();
    key9.value = 1008;
    Comparable key10 = Comparable();
    key10.value = 1009;
    Comparable key11 = Comparable();
    key11.value = 1011;
    Comparable key12 = Comparable();
    key12.value = 1012;
    Comparable key13 = Comparable();
    key13.value = 10012;
    Comparable key14 = Comparable();
    key14.value = 10003;
    Comparable key15 = Comparable();
    key15.value = 1000006;
    Comparable key16 = Comparable();
    key16.value = 1000016;
    Comparable key17 = Comparable();
    key17.value = 10017;
    Comparable key18 = Comparable();
    key18.value = 1018;
    Comparable key19 = Comparable();
    key19.value = 1019;
    
    int v0 = 11;
    int v1 = 12;
    int v2 = 13;
    int v3 = 14;
    int v4 = 15;
    int v5 = 16;
    int v6 = 17;
    int v7 = 18;
    int v8 = 19;
    int v9 = 20;
    int v10 = 21;
    int v11 = 22;
    int v12 = 23;
    int v13 = 24;
    int v14 = 25;
    int v15 = 26;
    int v16 = 27;
    int v17 = 28;
    int v18 = 29;
    int v19 = 30;
    
    scst.put(key0, v0);
    scst.put(key1, v1);
    scst.put(key2, v2);
    scst.put(key3, v3);
    scst.put(key4, v4);
    scst.put(key5, v5);
    scst.put(key6, v6);
    scst.put(key7, v7);
    scst.put(key8, v8);
    scst.put(key9, v9);
    scst.put(key10, v10);
    scst.put(key11, v11);
    scst.put(key12, v12);
    scst.put(key13, v13);
    scst.put(key14, v14);
    scst.put(key15, v15);
    scst.put(key16, v16);
    scst.put(key17, v17);
    scst.put(key18, v18);
    scst.put(key19, v19);
    
    scst.show();
    
    scst.deleteKey(key7);
    
    scst.show();
    
    scst.put(key2, 113);
    
    scst.show();
    
    return 0;
}
