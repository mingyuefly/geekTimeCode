//
//  main.cpp
//  LinearProbingHashST
//
//  Created by mingyue on 2022/2/24.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Comparable {
public:
    int value;
    int compareTo(Comparable a) {
        return value - a.value;
    }
    ~Comparable() {
        cout << "~Comparable()" << endl;
    }
}Comparable;

class LinearProbingHashST {
public:
    LinearProbingHashST() {
        keys = new vector<Comparable>(M);
        for (int i = 0; i < M; i++) {
            Comparable key = Comparable();
            key.value = -1;
            keys->at(i) = key;
        }
        vals = new vector<int>(M);
        for (int i = 0; i < M; i++) {
            vals->at(i) = -1;
        }
    }
    LinearProbingHashST(int cap) {
        M = cap;
        keys = new vector<Comparable>(M);
        for (int i = 0; i < M; i++) {
            Comparable key = Comparable();
            key.value = -1;
            keys->at(i) = key;
        }
        vals = new vector<int>(M);
        for (int i = 0; i < M; i++) {
            vals->at(i) = -1;
        }
    }
    ~LinearProbingHashST() {
        cout << "~LinearProbingHashST()" << endl;
        delete keys;
        delete vals;
    }
    void put(Comparable key, int value) {
        if (N >= M/2) {
            resize(2 * M);
        }
        int i;
        for (i = hash(key); keys->at(i).value != -1; i = (i + 1) % M) {
            if (keys->at(i).value == key.value) {
                vals->at(i) = value;
                return;
            }
        }
        keys->at(i) = key;
        vals->at(i) = value;
        N++;
    }
    int get(Comparable key) {
        for (int i = hash(key); keys->at(i).value != -1; i = (i + 1) % M) {
            if (keys->at(i).value == key.value) {
                return vals->at(i);
            }
        }
        return -1;
    }
    void deleteKey(Comparable key) {
        bool contain = false;
        for (int i = 0; i < M; i++) {
            if (keys->at(i).value == key.value) {
                contain = true;
            }
        }
        if (!contain) {
            return;
        }
        int i = hash(key);
        while (key.value != keys->at(i).value) {
            i = (i + 1) % M;
        }
        keys->at(i).value = -1;
        vals->at(i) = -1;
        i = (i + 1) % M;
        while (keys->at(i).value != -1) {
            Comparable keyToRedo = keys->at(i);
            int valueRedo = vals->at(i);
            keys->at(i).value = -1;
            vals->at(i) = -1;
            N--;
            put(keyToRedo, valueRedo);
            i = (i + 1) % M;
        }
        N--;
        if (N > 0 && N == M/8) {
            resize(M/2);
        }
    }
    void show() {
        for (int i = 0; i < M; i++) {
            cout << i << "---" << "(" << keys->at(i).value << ":" << vals->at(i) << ")" << endl;
        }
    }
private:
    int N = 0;
    int M = 20;
    vector<Comparable> * keys;
    vector<int> * vals;
    int hash(Comparable key) {
        return key.value % M;
    }
    void resize(int cap) {
        LinearProbingHashST t = LinearProbingHashST(cap);
        for (int i = 0; i < M; i++) {
            if (keys->at(i).value != -1) {
                t.put(keys->at(i), vals->at(i));
            }
        }
        vector<Comparable> * tKeys = keys;
        vector<int> * tVals = vals;
        keys = t.keys;
        vals = t.vals;
        M = t.M;
        t.keys = tKeys;
        t.vals = tVals;
    }
};

int main(int argc, const char * argv[]) {
    
    LinearProbingHashST lpst = LinearProbingHashST();
    
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
    Comparable key20 = Comparable();
    key20.value = 1023;
    
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
    int v20 = 33;
    
    lpst.put(key0, v0);
    lpst.put(key1, v1);
    lpst.put(key2, v2);
    lpst.put(key3, v3);
    lpst.put(key4, v4);
    lpst.put(key5, v5);
    lpst.put(key6, v6);
    lpst.put(key7, v7);
    lpst.put(key8, v8);
    lpst.put(key9, v9);
    lpst.put(key10, v10);
    lpst.put(key11, v11);
    lpst.put(key12, v12);
    lpst.put(key13, v13);
    lpst.put(key14, v14);
    lpst.put(key15, v15);
    lpst.put(key16, v16);
    lpst.put(key17, v17);
    lpst.put(key18, v18);
    lpst.put(key19, v19);
    lpst.put(key20, v20);
    
    lpst.show();
    cout << endl;
    
    lpst.deleteKey(key7);
    lpst.show();
    cout << endl;
    
    lpst.put(key2, 113);
    lpst.show();
    
    return 0;
}
