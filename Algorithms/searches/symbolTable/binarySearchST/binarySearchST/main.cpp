//
//  main.cpp
//  binarySearchST
//
//  Created by mingyue on 2022/2/9.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

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

class BinarySearchST {
public:
    BinarySearchST(int capicity) {
        keys = new vector<Comparable>(capicity);
        vals = new vector<int>(capicity);
        N = 0;
    }
    ~BinarySearchST() {
        cout << "~BinarySearchST()" << endl;
        delete keys;
        delete vals;
    }
    bool isEmpty() {
        return N == 0;
    }
    int size() {
        return N;
    }
    int rank(Comparable key) {
        int lo = 0, hi = N - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (keys->at(mid).compareTo(key) < 0) {
                lo = mid + 1;
            } else if (keys->at(mid).compareTo(key) > 0) {
                hi = mid - 1;
            } else {
                return mid;
            }
        }
        return lo;
    }
    int get(Comparable key) {
        if (isEmpty() == true) {
            return -1;
        }
        int i = rank(key);
        if (i < N && keys->at(i).compareTo(key) == 0) {
            return vals->at(i);
        } else {
            return -1;
        }
    }
    void put(Comparable key, int val) {
        if (N == keys->size()) {
            resize(2 * int(keys->size()));
        }
        int i = rank(key);
        if (i < N && keys->at(i).compareTo(key) == 0) {
            vals->at(i) = val;
            return;
        }
        for (int j = N; j > i; j--) {
            keys->at(j) = keys->at(j - 1);
            vals->at(j) = vals->at(j - 1);
        }
        keys->at(i) = key;
        vals->at(i) = val;
        N++;
    }
    void deleteKey(Comparable key) {
        if (isEmpty() == true) {
            return ;
        }
        int i = rank(key);
        if (i < N && keys->at(i).compareTo(key) == 0) {
            N--;
            for (int j = i; j < N; j++) {
                keys->at(j) = keys->at(j + 1);
                vals->at(j) = vals->at(j + 1);
            }
            if (N > 0 && N == keys->size() / 4) {
                resize(int(keys->size()) / 2);
            }
        }
    }
    Comparable min() {
        return keys->at(0);
    }
    Comparable max() {
        return keys->at(N - 1);
    }
    Comparable select(int k) {
        return keys->at(k);
    }
    Comparable ceiling(Comparable key) {
        int i = rank(key);
        return keys->at(i);
    }
    Comparable floor(Comparable key) {
        int i = rank(key);
        if (i < N && keys->at(i).compareTo(key) == 0) {
            return keys->at(i);
        } else {
            if (i > 0) {
                return keys->at(i - 1);
            } else {
                return Comparable(-1);
            }
        }
    }
    void show() {
        for (int i = 0; i < N; i++) {
            cout << "(" << keys->at(i).value << ":" << vals->at(i) << ")" << endl;
        }
        cout << endl;
    }
private:
    vector<Comparable> *keys;
    vector<int> *vals;
    int N;
    void resize(int max) {
        cout << "resize" << endl;
        keys->resize(max);
        vals->resize(max);
    }
};

int main(int argc, const char * argv[]) {
    BinarySearchST st = BinarySearchST(2);
    Comparable key0 = Comparable();
    key0.value = 3;
    Comparable key1 = Comparable();
    key1.value = 4;
    Comparable key2 = Comparable();
    key2.value = 5;
    Comparable key3 = Comparable();
    key3.value = 7;
    Comparable key4 = Comparable();
    key4.value = 9;
    Comparable key5 = Comparable();
    key5.value = 14;
    
    int v0 = 11;
    int v1 = 12;
    int v2 = 13;
    int v3 = 14;
    int v4 = 15;
    int v5 = 16;
    
    st.put(key0, v0);
    st.show();
    st.put(key2, v2);
    st.show();
    st.put(key1, v1);
    st.show();
    st.put(key4, v4);
    st.show();
    st.put(key5, v5);
    st.show();
    st.put(key3, v3);
    st.show();
    
    st.put(key4, 24);
    st.show();
    
    cout << st.ceiling(8).value << endl;
    cout << st.ceiling(3).value << endl;
    cout << st.floor(8).value << endl;
    cout << st.floor(3).value << endl;
    cout << st.floor(1).value << endl;
    
    st.deleteKey(key2);
    st.show();
    st.deleteKey(key3);
    st.show();
    st.deleteKey(key4);
    st.show();
    st.deleteKey(key5);
    st.show();
    st.deleteKey(key1);
    st.show();
    return 0;
}
