//
//  main.cpp
//  Quick3string
//
//  Created by mingyue on 2022/3/28.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Quick3string {
public:
    void sort(vector<string> * a) {
        int N = (int)a->size();
        sort(a, 0, N - 1, 0);
    }
private:
    int charAt(string s, int d) {
        if (d < s.size()) {
            return s.at(d);
        } else {
            return -1;
        }
    }
    void sort(vector<string> * a, int lo, int hi, int d) {
        if (hi <= lo) {
            return;
        }
        int lt = lo, gt = hi;
        int v = charAt(a->at(lo), d);
        int i = lo + 1;
        while (i <= gt) {
            int t = charAt(a->at(i), d);
            if (t < v) {
                exch(a, lt++, i++);
            } else if (t > v) {
                exch(a, i, gt--);
            } else {
                i++;
            }
        }
        sort(a, lo, lt - 1, d);
        if (v >= 0) {
            sort(a, lt, gt, d + 1);
        }
        sort(a, gt + 1, hi, d);
    }
    void exch(vector<string> * a, int i, int j) {
        string tmp = a->at(i);
        a->at(i) = a->at(j);
        a->at(j) = tmp;
    }
};



int main(int argc, const char * argv[]) {
    vector<string> * a = new vector<string>();
    string s1 = "edu.princeton.cs";
    string s2 = "com.apple";
    string s3 = "edu.princeton.cs";
    string s4 = "com.cnn";
    string s5 = "com.google";
    string s6 = "edu.uva.cs";
    string s7 = "edu.princeton.cs";
    string s8 = "edu.princeton.cs.www";
    string s9 = "edu.uva.cs";
    string s10 = "edu.uva.cs";
    string s11 = "edu.uva.cs";
    string s12 = "com.adobe";
    string s13 = "edu.princeton.ee";
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
    Quick3string q3s = Quick3string();
    q3s.sort(a);
    for (int i = 0; i < a->size(); i++) {
        cout << a->at(i) << endl;
    }
    cout << endl;
    
    delete a;
    
    return 0;
}
