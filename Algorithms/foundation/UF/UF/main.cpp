//
//  main.cpp
//  UF
//
//  Created by mingyue on 2022/3/18.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class UF {
public:
    UF() {
        
    }
    UF(int N) {
        count = N;
        id = new vector<int>(N);
        for (int i = 0; i < N; i++) {
            id->at(i) = i;
        }
    }
    ~UF() {
        cout << "~UF()" << endl;
        delete id;
    }
    int getCount() {
        return count;
    }
    bool connected(int p, int q) {
        return id->at(p) == id->at(q);
    }
    int find(int p) {
        return id->at(p);
    }
    void unionP(int p, int q) {
        int pID = id->at(p);
        int qID = id->at(q);
        if (pID == qID) {
            return;
        }
        for (int i = 0; i < id->size(); i++) {
            if (id->at(i) == pID) {
                id->at(i) = qID;
            }
        }
        count--;
    }
    void show() {
        cout << "count:" << count << endl;
        for (int i = 0; i < id->size(); i++) {
            cout << i << ":" << id->at(i) << endl;
        }
    }
private:
    vector<int> * id;
    int count;
};

class QuickUF {
public:
    QuickUF() {
        
    }
    QuickUF(int N) {
        count = N;
        id = new vector<int>(N);
        for (int i = 0; i < N; i++) {
            id->at(i) = i;
        }
    }
    ~QuickUF() {
        cout << "~QuickUF()" << endl;
        delete id;
    }
    int getCount() {
        return count;
    }
    bool connected(int p, int q) {
        return id->at(p) == id->at(q);
    }
    int find(int p) {
        while (p != id->at(p)) {
            p = id->at(p);
        }
        return p;
    }
    void unionP(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot) {
            return;
        }
        id->at(pRoot) = qRoot;
        count--;
    }
    void show() {
        cout << "count:" << count << endl;
        for (int i = 0; i < id->size(); i++) {
            cout << i << ":" << id->at(i) << endl;
        }
    }
private:
    vector<int> * id;
    int count;
};


int main(int argc, const char * argv[]) {
    /*
    int N = 11;
    UF uf = UF(N);
    uf.show();
    int p = 8;
    int q = 5;
    uf.unionP(p, q);
    if (uf.connected(p, q)) {
        cout << uf.find(p) << endl;
    }
    uf.show();
    int r = 3;
    uf.unionP(p, r);
    if (uf.connected(r, q)) {
        cout << uf.find(r) << endl;
    }
    uf.show();
     */
    
    int N = 11;
    QuickUF uf = QuickUF(N);
    uf.show();
    int p = 8;
    int q = 5;
    uf.unionP(p, q);
    if (uf.connected(p, q)) {
        cout << uf.find(p) << endl;
    }
    uf.show();
    int r = 3;
    uf.unionP(p, r);
    if (uf.connected(r, q)) {
        cout << uf.find(r) << endl;
    }
    uf.show();
    
    return 0;
}
