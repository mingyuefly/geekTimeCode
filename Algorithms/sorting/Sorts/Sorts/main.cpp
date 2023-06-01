//
//  main.cpp
//  Sorts
//
//  Created by mingyue on 2021/10/17.
//  Copyright © 2021 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace std;

template <typename T>
struct Comparable {
public:
    T value;
    int compareTo(Comparable a) {
        return value - a.value;
    }
};

template <class T>
class Selection {
public:
    static void sort(vector<Comparable<T>> &a) {
        size_t count = a.size();
        for (uint32_t i = 0; i < count; i++) {
            uint32_t minIndex = i;
            for (uint32_t j = i + 1; j < count; j++) {
                if (less(a[j], a[minIndex])) {
                    minIndex = j;
                }
            }
            exch(a, i, minIndex);
        }
    }
    static void show(vector<Comparable<T>> a) {
        size_t count = a.size();
        for (uint32_t i = 0; i < count; i++) {
            cout << a.at(i).value << ' ';
        }
        cout << endl;
    }
    static bool isSorted(vector<Comparable<T>> a) {
        size_t count = a.size();
        for (uint32_t i = 1; i < count; i++) {
            if (less(a[i], a[i - 1])) {
                return false;
            }
        }
        return true;
    }
private:
    static bool less(Comparable<T> v, Comparable<T> w) {
        return v.compareTo(w) < 0;
    }
    static void exch(vector<Comparable<T>> &a, uint32_t i, uint32_t j) {
        Comparable<T> tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
};

template <class T>
class Insertion {
public:
    static void sort(vector<Comparable<T>> &a) {
        size_t count = a.size();
        for (uint32_t i = 1; i < count; i++) {
            for (int j = i; j > 0 && less(a[j], a[j - 1]); j--) {
                exch(a, j, j - 1);
            }
        }
    }
    static void show(vector<Comparable<T>> a) {
        size_t count = a.size();
        for (uint32_t i = 0; i < count; i++) {
            cout << a.at(i).value << ' ';
        }
        cout << endl;
    }
    static bool isSorted(vector<Comparable<T>> a) {
        size_t count = a.size();
        for (uint32_t i = 1; i < count; i++) {
            if (less(a[i], a[i - 1])) {
                return false;
            }
        }
        return true;
    }
private:
    static bool less(Comparable<T> v, Comparable<T> w) {
        return v.compareTo(w) < 0;
    }
    static void exch(vector<Comparable<T>> &a, uint32_t i, uint32_t j) {
        Comparable<T> tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    
};

template <class T>
class Shell {
    public:
    static void sort(vector<Comparable<T>> &a) {
        size_t count = a.size();
        uint32_t h = 1;
        while (h < count / 3) {
            h = 3 * h + 1;
        }
        while (h >= 1) {
            for (uint32_t i = h; i < count; i++) {
                for (int j = i; j > 0 && less(a[j], a[j - h]); j -= h) {
                    exch(a, j, j - h);
                }
            }
            h = h / 3;
        }
    }
    static void show(vector<Comparable<T>> a) {
        size_t count = a.size();
        for (uint32_t i = 0; i < count; i++) {
            cout << a.at(i).value << ' ';
        }
        cout << endl;
    }
    static bool isSorted(vector<Comparable<T>> a) {
        size_t count = a.size();
        for (uint32_t i = 1; i < count; i++) {
            if (less(a[i], a[i - 1])) {
                return false;
            }
        }
        return true;
    }
private:
    static bool less(Comparable<T> v, Comparable<T> w) {
        return v.compareTo(w) < 0;
    }
    static void exch(vector<Comparable<T>> &a, uint32_t i, uint32_t j) {
        Comparable<T> tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
};

// 归并排序
template <class T>
class Merge {
    public:
    static void sort(vector<Comparable<T>> &a) {
        size_t count = a.size();
        vector<Comparable<T>> aux(count);
        sort(a, 0, count - 1, aux);
    }
    static void show(vector<Comparable<T>> a) {
        size_t count = a.size();
        for (uint32_t i = 0; i < count; i++) {
            cout << a.at(i).value << ' ';
        }
        cout << endl;
    }
    static bool isSorted(vector<Comparable<T>> a) {
        size_t count = a.size();
        for (uint32_t i = 1; i < count; i++) {
            if (less(a[i], a[i - 1])) {
                return false;
            }
        }
        return true;
    }
private:
    //static vector<Comparable<int>> aux;
    static void sort(vector<Comparable<T>> &a, uint32_t lo, uint32_t hi, vector<Comparable<T>> &aux) {
        if (hi <= lo) {
            return;
        }
        uint32_t mid = lo + (hi - lo) / 2;
        sort(a, lo, mid, aux);
        sort(a, mid + 1, hi, aux);
        merge(a, lo, mid, hi, aux);
    }
    static void merge(vector<Comparable<T>> &a, uint32_t lo, uint32_t mid, uint32_t hi, vector<Comparable<T>> &aux) {
        uint32_t i = lo;
        uint32_t j = mid + 1;
        for (uint32_t k = lo; k <= hi; k++) {
            aux[k] = a[k];
        }
        for (uint32_t k = lo; k <= hi; k++) {
            if (i > mid) {
                a[k] = aux[j++];
            } else if (j > hi) {
                a[k] = aux[i++];
            } else if (less(aux[i], aux[j])) {
                a[k] = aux[i++];
            } else {
                a[k] = aux[j++];
            }
        }
    }
    static bool less(Comparable<T> v, Comparable<T> w) {
        return v.compareTo(w) < 0;
    }
    static void exch(vector<Comparable<T>> &a, uint8_t i, uint8_t j) {
        Comparable<T> tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
};

template <class T>
class Quick {
public:
    static void sort(vector<Comparable<T>> &a) {
        size_t count = a.size();
        sort(a, 0, count - 1);
    }
    static void show(vector<Comparable<T>> a) {
        size_t count = a.size();
        for (uint32_t i = 0; i < count; i++) {
            cout << a.at(i).value << ' ';
        }
        cout << endl;
    }
    static bool isSorted(vector<Comparable<T>> a) {
        size_t count = a.size();
        for (uint32_t i = 1; i < count; i++) {
            if (less(a[i], a[i - 1])) {
                return false;
            }
        }
        return true;
    }
private:
    static void sort(vector<Comparable<T>> &a, uint32_t lo, uint32_t hi) {
        if (hi <= lo) {
            return;
        }
        uint32_t mid = partition(a, lo, hi);
        sort(a, lo, mid - 1);
        sort(a, mid + 1, hi);
    }
    static size_t partition(vector<Comparable<T>> &a, uint32_t lo, uint32_t hi) {
        uint32_t i = lo;
        uint32_t j = hi + 1;
        Comparable<T> midValue = a[lo];
        while (true) {
            while (less(a[++i], midValue)) {
                if (i == hi) {
                    break;
                }
            }
            while (less(midValue, a[--j])) {
                if (j == lo) {
                    break;
                }
            }
            if (i >= j) {
                break;
            }
            exch(a, i, j);
        }
        exch(a, lo, j);
        return j;
    }
    static bool less(Comparable<T> v, Comparable<T> w) {
        return v.compareTo(w) < 0;
    }
    static void exch(vector<Comparable<T>> &a, uint32_t i, uint32_t j) {
        Comparable<T> tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> a = {5, 3, 1, 10, 2, 18, 38, 17, 16, 25, 10};
    vector<Comparable<int>> params;
    for (int i = 0; i < a.size(); i++) {
        Comparable<int> c;
        c.value = a[i];
        params.push_back(c);
    }
    
    /*
    Selection<int>::show(params);
    Selection<int>::sort(params);
    bool isSorted = Selection<int>::isSorted(params);
    if (isSorted) {
        Selection<int>::show(params);
    }
     */
    
    /*
    Insertion<int>::show(params);
    Insertion<int>::sort(params);
    bool isSorted = Insertion<int>::isSorted(params);
    if (isSorted) {
        Insertion<int>::show(params);
    }
    */
    
    /*
    Shell<int>::show(params);
    Shell<int>::sort(params);
    bool isSorted = Shell<int>::isSorted(params);
    if (isSorted) {
        Shell<int>::show(params);
    }
     */
    
    
    Merge<int>::show(params);
    Merge<int>::sort(params);
    bool isSorted = Merge<int>::isSorted(params);
    if (isSorted) {
        Merge<int>::show(params);
    }

    
    /*
    Quick<int>::show(params);
    Quick<int>::sort(params);
    bool isSorted = Quick<int>::isSorted(params);
    if (isSorted) {
        Quick<int>::show(params);
    }
     */
    
    Comparable<uint32_t> t1 = {10}, t2 = {10};
    int res = t1.compareTo(t2);
    if (res) {
        cout << res << endl;
    }
    
    
    return 0;
}
