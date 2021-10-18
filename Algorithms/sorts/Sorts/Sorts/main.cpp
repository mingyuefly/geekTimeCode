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

typedef struct Comparable {
public:
    int value;
    int compareTo(Comparable a) {
        return value - a.value;
    }
}Comparable;

class Selection {
public:
    static void sort(vector<Comparable> &a) {
        size_t count = a.size();
        for (int i = 0; i < count; i++) {
            int minIndex = i;
            for (int j = i + 1; j < count; j++) {
                if (less(a[j], a[minIndex])) {
                    minIndex = j;
                }
            }
            exch(a, i, minIndex);
        }
    }
    static void show(vector<Comparable> a) {
        size_t count = a.size();
        for (int i = 0; i < count; i++) {
            cout << a.at(i).value << ' ';
        }
        cout << endl;
    }
    static bool isSorted(vector<Comparable> a) {
        size_t count = a.size();
        for (int i = 1; i < count; i++) {
            if (less(a[i], a[i - 1])) {
                return false;
            }
        }
        return true;
    }
private:
    static bool less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }
    static void exch(vector<Comparable> &a, int i, int j) {
        Comparable tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
};

class Insertion {
public:
    static void sort(vector<Comparable> &a) {
        size_t count = a.size();
        for (int i = 1; i < count; i++) {
            for (int j = i; j > 0 && less(a[j], a[j - 1]); j--) {
                exch(a, j, j - 1);
            }
        }
    }
    static void show(vector<Comparable> a) {
        size_t count = a.size();
        for (int i = 0; i < count; i++) {
            cout << a.at(i).value << ' ';
        }
        cout << endl;
    }
    static bool isSorted(vector<Comparable> a) {
        size_t count = a.size();
        for (int i = 1; i < count; i++) {
            if (less(a[i], a[i - 1])) {
                return false;
            }
        }
        return true;
    }
private:
    static bool less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }
    static void exch(vector<Comparable> &a, int i, int j) {
        Comparable tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
};

class Shell {
    public:
    static void sort(vector<Comparable> &a) {
        size_t count = a.size();
        int h = 1;
        while (h < count / 3) {
            h = 3 * h + 1;
        }
        while (h >= 1) {
            for (int i = h; i < count; i++) {
                for (int j = i; j > 0 && less(a[j], a[j - h]); j -= h) {
                    exch(a, j, j - h);
                }
            }
            h = h / 3;
        }
    }
    static void show(vector<Comparable> a) {
        size_t count = a.size();
        for (int i = 0; i < count; i++) {
            cout << a.at(i).value << ' ';
        }
        cout << endl;
    }
    static bool isSorted(vector<Comparable> a) {
        size_t count = a.size();
        for (int i = 1; i < count; i++) {
            if (less(a[i], a[i - 1])) {
                return false;
            }
        }
        return true;
    }
private:
    static bool less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }
    static void exch(vector<Comparable> &a, int i, int j) {
        Comparable tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
};

class Merge {
    public:
    //static vector<Comparable> aux;
    static void sort(vector<Comparable> &a) {
        vector<Comparable> aux;
        size_t count = a.size();
        for (int i = 0; i < count; i++) {
            Comparable c;
            c.value = 0;
            aux.push_back(c);
        }
        sort(a, 0, count - 1, aux);
    }
    static void show(vector<Comparable> a) {
        size_t count = a.size();
        for (int i = 0; i < count; i++) {
            cout << a.at(i).value << ' ';
        }
        cout << endl;
    }
    static bool isSorted(vector<Comparable> a) {
        size_t count = a.size();
        for (int i = 1; i < count; i++) {
            if (less(a[i], a[i - 1])) {
                return false;
            }
        }
        return true;
    }
private:
    //static vector<Comparable> aux;
    static void sort(vector<Comparable> &a, size_t lo, size_t hi, vector<Comparable> &aux) {
        if (hi <= lo) {
            return;
        }
        size_t mid = lo + (hi - lo) / 2;
        sort(a, lo, mid, aux);
        sort(a, mid + 1, hi, aux);
        merge(a, lo, mid, hi, aux);
    }
    static void merge(vector<Comparable> &a, size_t lo, size_t mid, size_t hi, vector<Comparable> &aux) {
        size_t i = lo;
        size_t j = mid + 1;
        for (size_t k = lo; k <= hi; k++) {
            aux[k] = a[k];
        }
        for (size_t k = lo; k <= hi; k++) {
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
    static bool less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }
    static void exch(vector<Comparable> &a, int i, int j) {
        Comparable tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
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
    
    /*
    Selection::show(params);
    Selection::sort(params);
    bool isSorted = Selection::isSorted(params);
    if (isSorted) {
        Selection::show(params);
    }
    */
    
    /*
    Insertion::show(params);
    Insertion::sort(params);
    bool isSorted = Insertion::isSorted(params);
    if (isSorted) {
        Insertion::show(params);
    }
     */
    
    /*
    Shell::show(params);
    Shell::sort(params);
    bool isSorted = Shell::isSorted(params);
    if (isSorted) {
        Shell::show(params);
    }
     */
    
    Merge::show(params);
    Merge::sort(params);
    bool isSorted = Merge::isSorted(params);
    if (isSorted) {
        Merge::show(params);
    }
    
    return 0;
}
