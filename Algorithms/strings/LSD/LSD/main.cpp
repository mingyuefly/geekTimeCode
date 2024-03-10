//
//  main.cpp
//  LSD
//
//  Created by mingyue on 2022/3/27.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class LSD {
public:
    static void sorts(vector<string> * a, int W) {
        int N = (int)a->size();
        int R = 256;
        vector<string> aux = vector<string>(N);
        for (int d = W - 1; d >= 0; d--) {
            vector<int> count = vector<int>(R+1); // C++ 默认初始化元素是0
            for (int i = 0; i < N; i++) {
                count.at(a->at(i).at(d) + 1)++; // C++ 字符串获取到指定索引的字符可以直接转换为字母表int值进行算术操作，脱胎于C语言
            }
            for (int r = 0; r < R; r++) {
                count.at(r+1)+=count.at(r);
            }
            for (int i = 0; i < N; i++) {
                aux.at(count.at(a->at(i).at(d))++) = a->at(i);
            }
            for (int i = 0; i < N; i++) {
                a->at(i) = aux.at(i);
            }
        }
    }
private:
//    LSD() {}
};


int main(int argc, const char * argv[]) {
    
    vector<string> * a = new vector<string>();
    string s1 = "4PGC938";
    string s2 = "2IYE230";
    string s3 = "3CIO720";
    string s4 = "1ICK750";
    string s5 = "1OHV845";
    string s6 = "4JZY524";
    string s7 = "1ICK750";
    string s8 = "3CIO720";
    string s9 = "1OHV845";
    string s10 = "1OHV845";
    string s11 = "2RLA629";
    string s12 = "2RLA629";
    string s13 = "3ATW723";
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
//    static LSD lsd = LSD();
//    lsd.sorts(a, 7);
    LSD::sorts(a, 7);
    for (int i = 0; i < a->size(); i++) {
        cout << a->at(i) << endl;
    }
    cout << endl;
    delete a;
    
    return 0;
}
