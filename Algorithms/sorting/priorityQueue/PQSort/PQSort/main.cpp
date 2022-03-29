//
//  main.cpp
//  PQSort
//
//  Created by mingyue on 2021/11/28.
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
public:
    size_t N;
    MaxPQ() {
        
    }
    ~MaxPQ() {
        cout << "~MaxPQ()" << endl;
    }
    void sort(vector<Comparable> *a) {
        //size_t n = a->size();
        for (size_t k = N / 2; k >= 1; k--) {
            sink(a, k, N);
        }
        while (N > 1) {
            exch(a, 1, N--);
            sink(a, 1, N);
        }
    }
    void show(vector<Comparable> *a) {
        size_t count = a->size();
        for (int i = 1; i < count; i++) {
            cout << a->at(i).value << ' ';
        }
        cout << endl;
    }
private:
    bool less(vector<Comparable> *a, size_t i, size_t j) {
        return a->at(i).compareTo(a->at(j)) < 0;
    }
    void exch(vector<Comparable> *a, size_t i, size_t j) {
        Comparable tmp = a->at(i);
        a->at(i) = a->at(j);
        a->at(j) = tmp;
    }
    void swim(vector<Comparable> *a, size_t k) {
        while (k > 1 && less(a, k / 2, k)) {
            exch(a, k / 2, k);
            k = k / 2;
        }
    }
    void sink(vector<Comparable> *a, size_t k, size_t n) {
        while (2 * k <= n) {
            size_t j = 2 * k;
            if (j < n && less(a, j, j + 1)) {
                j++;
            }
            if (!less(a, k, j)) {
                break;
            }
            exch(a, k, j);
            k = j;
        }
    }
};

int main(int argc, const char * argv[]) {
    MaxPQ maxPQ = MaxPQ();
    vector<int> a1 = {5, 3, 1, 10, 2, 18, 38, 17, 16, 25};
    vector<Comparable> *params1 = new vector<Comparable>(a1.size() + 1);
    maxPQ.N = a1.size();
    for (int i = 0; i < a1.size() + 1; i++) {
        if (i == 0) {
            Comparable c;
            c.value = 0;
            params1->at(i) = c;
        } else {
            Comparable c;
            c.value = a1[i - 1];
            params1->at(i) = c;
        }
    }
    maxPQ.show(params1);
    maxPQ.sort(params1);
    maxPQ.show(params1);
    delete params1;
    
    return 0;
}
