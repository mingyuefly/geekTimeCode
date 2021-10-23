//
//  main.cpp
//  priorityQueue
//
//  Created by mingyue on 2021/10/19.
//  Copyright © 2021 Gmingyue. All rights reserved.
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

class MaxPQ {
private:
    vector<Comparable > *pq;
    size_t N;
public:
    MaxPQ(size_t maxN) {
        pq = new vector<Comparable>(maxN + 1);
        for (int i = 0; i < maxN + 1; i++) {
            Comparable c;
            c.value = 0;
            pq->at(i) = c;
        }
        N = 0;
        cout << "pq size = " << pq->size() << endl;
    }
    ~MaxPQ() {
        cout << "~MaxPQ()" << endl;
        delete pq;
    }
    bool isEmpty() {
        return N == 0;
    }
    size_t size() {
        return N;
    }
    void insert(Comparable v) {
        pq->at(++N) = v;
        swim(N);
    }
    Comparable delMax() {
        Comparable max = pq->at(1);
        exch(1, N--);
        Comparable c;
        c.value = 0;
        pq->at(N + 1) = c;
        sink(1);
        return max;
    }
    void show() {
        size_t count = pq->size();
        for (int i = 1; i < count; i++) {
            cout << pq->at(i).value << ' ';
        }
        cout << endl;
    }
private:
    bool less(size_t i, size_t j) {
        return pq->at(i).compareTo(pq->at(j)) < 0;
    }
    void exch(size_t i, size_t j) {
        Comparable tmp = pq->at(i);
        pq->at(i) = pq->at(j);
        pq->at(j) = tmp;
    }
    void swim(size_t k) {
        while (k > 1 && less(k / 2, k)) {
            exch(k / 2, k);
            k = k / 2;
        }
    }
    void sink(size_t k) {
        while (2 * k <= N) {
            size_t j = 2 * k;
            if (j < N && less(j, j + 1)) {
                j++;
            }
            if (!less(k, j)) {
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

    MaxPQ maxPQ = MaxPQ(a.size());
    maxPQ.show();
    for (int i = 0; i < a.size(); i++) {
        maxPQ.insert(params[i]);
    }
    maxPQ.show();
    maxPQ.delMax();
    maxPQ.show();
    maxPQ.delMax();
    maxPQ.show();
    
    return 0;
}
