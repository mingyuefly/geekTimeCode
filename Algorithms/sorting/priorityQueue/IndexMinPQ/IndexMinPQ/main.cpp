//
//  main.cpp
//  IndexMinPQ
//
//  Created by mingyue on 2022/3/15.
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

class IndexMinPQ {
public:
    IndexMinPQ() {
        
    }
    IndexMinPQ(size_t maxN) {
        this->maxN = maxN;
        keys = new vector<Comparable>(maxN + 1);
        for (int i = 0; i < maxN + 1; i++) {
            Comparable c;
            c.value = -1;
            keys->at(i) = c;
        }
        N = 0;
        pq = new vector<int>(maxN + 1, -1);
        qp = new vector<int>(maxN + 1, -1);
        cout << "pq size = " << pq->size() << endl;
    }
    ~IndexMinPQ() {
        cout << "~IndexMinPQ()" << endl;
        delete pq;
        delete qp;
        delete keys;
    }
    bool contains(int i) {
        if (validateIndex(i) == false) {
            return false;
        }
        return qp->at(i) != -1;
    }
    int size() {
        return N;
    }
    bool isEmpty() {
        return N == 0;
    }
    void insert(int i, Comparable key) {
        if (validateIndex(i) == false) {
            return;
        }
        if (contains(i)) {
            cout << "contains" << " " << i << endl;
            return;
        }
        N++;
        qp->at(i) = N;
        pq->at(N) = i;
        keys->at(i) = key;
        swim(N);
    }
    int minIndex() {
        if (N == 0) {
            return -1;
        }
        return pq->at(1);
    }
    Comparable minKey() {
        if (N == 0) {
            Comparable c;
            c.value = -1;
            return c;
        }
        return keys->at(pq->at(1));
    }
    int delMin() {
        if (N == 0) {
            return -1;
        }
        int min = pq->at(1);
        exch(1, N);
        N--;
        sink(1);
        if (min != pq->at(N + 1)) {
            return -1;
        }
        qp->at(min) = -1;
        Comparable c;
        c.value = -1;
        keys->at(min) = c;
        pq->at(N + 1) = -1;
        return min;
    }
    Comparable keyOf(int i) {
        if (validateIndex(i) == false) {
            Comparable c;
            c.value = -1;
            return c;
        }
        if (!contains(i)) {
            Comparable c;
            c.value = -1;
            return c;
        }
        return keys->at(i);
    }
    void changeKey(int i, Comparable key) {
        if (validateIndex(i) == false) {
            return;
        }
        if (!contains(i)) {
            return;
        }
        keys->at(i) = key;
        swim(qp->at(i));
        sink(qp->at(i));
    }
    void deleteIndex(int i) {
        if (!validateIndex(i)) {
            return;
        }
        if (!contains(i)) {
            return;
        }
        int index = qp->at(i);
        exch(index, N--);
        swim(index);
        sink(index);
        Comparable c;
        c.value = -1;
        keys->at(i) = c;
        qp->at(i) = -1;
    }
    void show() {
//        size_t count = N;
        for (int i = 0; i <= 20; i++) {
            cout << pq->at(i) << ' ' << keys->at(i).value << " " << qp->at(i) << endl;
        }
        cout << endl;
    }
private:
    vector<Comparable > *keys;
    int N = 0;
    vector<int> * pq;
    vector<int> * qp;
    size_t maxN = 100;
    bool validateIndex(int k) {
        if (k >= maxN || k < 0) {
            return false;
        }
        return true;
    }
    bool greater(int i, int j) {
        return keys->at(pq->at(i)).compareTo(keys->at(pq->at(j))) > 0;
    }
    void exch(int i, int j) {
        int swap = pq->at(i);
        pq->at(i) = pq->at(j);
        pq->at(j) = swap;
        qp->at(pq->at(i)) = i;
        qp->at(pq->at(j)) = j;
    }
    void swim(int k) {
        while (k > 1 && greater(k / 2, k)) {
            exch(k, k / 2);
            k = k / 2;
        }
    }
    void sink(int k) {
        while (2 * k <= N) {
            int j = 2 * k;
            if (j < N && greater(j, j+1)) {
                j++;
            }
            if (!greater(k, j)) {
                break;
            }
            exch(k, j);
            k = j;
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> a = {5, 3, 1, 10, 2, 18, 38, 17, 16, 25};
    vector<Comparable> params;
    for (int i = 0; i < a.size(); i++) {
        Comparable c;
        c.value = a[i];
        params.push_back(c);
    }

    IndexMinPQ indexPQ = IndexMinPQ(100);
    for (int i = 0; i < a.size(); i++) {
        indexPQ.insert(i, params.at(i));
    }
    indexPQ.show();
    cout << indexPQ.delMin() << endl;
    cout << endl;
    indexPQ.show();
    cout << indexPQ.delMin() << endl;
    cout << endl;
    indexPQ.show();
    Comparable c9;
    c9.value = 9;
    indexPQ.insert(11, c9);
    indexPQ.show();
    Comparable c33;
    c33.value = 33;
    indexPQ.insert(3, c33);
    indexPQ.show();
    Comparable c55;
    c55.value = 55;
    indexPQ.insert(5, c55);
    indexPQ.show();
    
    return 0;
}
