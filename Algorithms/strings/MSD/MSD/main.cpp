//
//  main.cpp
//  MSD
//
//  Created by mingyue on 2022/3/28.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class MSD {
public:
    void sort(vector<string> * a) {
        int N = (int)a->size();
        aux = new vector<string>(N);
        sort(a, 0, N - 1, 0);
    }
private:
    int R = 256;
    int M = 3;
    vector<string> * aux;
    int charAt(string s, int d) {
        if (d < s.size()) {
            return s.at(d);
        } else {
            return -1;
        }
    }
    void sort(vector<string> * a, int lo, int hi, int d) {
        if (hi <= lo + M) {
            insertion(a, lo, hi, d);
            return;
        }
        vector<int> count = vector<int>(R + 2);
        for (int i = lo; i <= hi; i++) {
            count.at(charAt(a->at(i), d) + 2)++;
        }
        for (int r = 0; r < R + 1; r++) {
            count.at(r + 1)+=count.at(r);
        }
        for (int i = lo; i <= hi; i++) {
            aux->at(count.at(charAt(a->at(i), d) + 1)++) = a->at(i);
        }
        for (int i = lo; i <= hi; i++) {
            a->at(i) = aux->at(i - lo);
        }
        for (int r = 0; r < R; r++) {
            sort(a, lo + count.at(r), lo + count.at(r + 1) - 1, d + 1);
        }
    }
    void insertion(vector<string> * a, int lo, int hi, int d) {
        for (int i = lo + 1; i <= hi; i++) {
            for (int j = i; j > lo && less(a->at(j), a->at(j - 1)); j--) {
                exch(a, j, j - 1);
            }
        }
    }
    void exch(vector<string> * a, int i, int j) {
        string tmp = a->at(i);
        a->at(i) = a->at(j);
        a->at(j) = tmp;
    }
    bool less(string v, string w) {
        for (int i = 0; i < min(v.size(), w.size()); i++) {
            if (v.at(i) < w.at(i)) {
                return true;
            }
            if (v.at(i) > w.at(i)) {
                return false;
            }
        }
        return v.size() < w.size();
    }
};


int main(int argc, const char * argv[]) {
    
    vector<string> * a = new vector<string>();
    string s1 = "she";
    string s2 = "sells";
    string s3 = "seashells";
    string s4 = "by";
    string s5 = "the";
    string s6 = "seashore";
    string s7 = "the";
    string s8 = "shells";
    string s9 = "she";
    string s10 = "sells";
    string s11 = "are";
    string s12 = "surely";
    string s13 = "seashells";
    a->push_back(s1);
    a->push_back(s2);
    a->push_back(s3);
    a->push_back(s4);
    a->push_back(s5);
    a->push_back(s6);
    a->push_back(s7);
    a->push_back(s8);
    a->push_back(s9);
    a->push_back(s10);
    a->push_back(s11);
    a->push_back(s12);
    a->push_back(s13);
    for (int i = 0; i < a->size(); i++) {
        cout << a->at(i) << endl;
    }
    cout << endl;
    MSD msd;
    msd.sort(a);
    for (int i = 0; i < a->size(); i++) {
        cout << a->at(i) << endl;
    }
    cout << endl;
    delete a;
    return 0;
}
