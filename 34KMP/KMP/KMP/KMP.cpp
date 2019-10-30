//
//  KMP.cpp
//  KMP
//
//  Created by Gguomingyue on 2019/10/29.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "KMP.hpp"

/**
 nexts implemention
 */
void getNexts(string pattern, int nexts[])
{
    int M = (int)pattern.length();
    nexts[0] = -1;
    int k = -1;
    for (int i = 1; i < M; i++) {
        while (k != -1 && pattern.at(k + 1) != pattern.at(i)) {
            k = nexts[k];
        }
        if (pattern.at(k + 1) == pattern.at(i)) {
            k++;
        }
        nexts[i] = k;
    }
}

int kmp(string txt, string pattern)
{
    int N = (int)txt.length();
    int M = (int)pattern.length();
    int nexts[M];
    getNexts(pattern, nexts);
    int j = 0;
    for (int i = 0; i < N; i++) {
        while (j > 0 && txt.at(i) != pattern.at(j)) {
            j = nexts[j - 1] + 1;
            // 移动后接着对比j位，若不相等继续根据nexts数组调整，若相等跳出while循环继续
        }
        if (txt.at(i) == pattern.at(j)) {
            j++;
        }
        if (j == M) {
            return i - M + 1;
        }
    }
    
    return N;
}
