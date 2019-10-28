//
//  BruteForce.cpp
//  bruteForce
//
//  Created by Gguomingyue on 2019/10/23.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "BruteForce.hpp"
#include <iostream>
using namespace std;

int bruteForce(string txt, string pattern)
{
    int i, j;
    int N = (int)txt.length();
    int M = (int)pattern.length();
    for (i = 0, j = 0; i < N && j < M; i++) {
        if (txt.at(i) == pattern.at(j)) {
            j++;
        } else {
            i -= j;
            j = 0;
        }
    }
    if (j == M) {
        cout << "字符串匹配成功" << endl;
        return i - M;
    }
    cout << "字符串匹配失败" << endl;
    return N;
}
