//
//  BoyerMoore.cpp
//  BoyerMoore
//
//  Created by Gguomingyue on 2019/10/28.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "BoyerMoore.hpp"
#include <cmath>

/**
 hash map build
 */
static int size = 256;
void generateBC(int bc[], int m, string pattern)
{
    for (int i = 0; i < m; i++) {
        bc[i] = -1;
    }
    for (int i = 0; i < pattern.length(); i++) {
        int ascii = (int)pattern.at(i);
        bc[ascii] = i;
    }
}

/**
 build suffix and prefix
 */
void generateGS(string pattern, int suffix[], bool prefix[])
{
    int M = (int)pattern.length();
    for (int i = 0; i < M; i++) {
        suffix[i] = -1;
        prefix[i] = false;
    }
    for (int i = 0; i < M - 1; i++) {
        int j = i;
        int k = 0;
        while (j >= 0 && pattern.at(j) == pattern.at(M - 1 - k)) {
            k++;
            j--;
            suffix[k] = j + 1;//因为前边j--,所以这里+1
        }
        if (j == -1) {
            prefix[k] = true;
        }
    }
}

/**
 move by good suffix
 */
int moveByGS(int m, int j, int suffix[], bool prefix[])
{
    int k = m - 1 - j;
    if (suffix[k] != -1) {
        return j - suffix[k] + 1;
    }
    //因为不存在与好后缀匹配的子串，所以r从j+1+1位开始
    for (int r = j + 2; r < m; r++) {
        // m-r表示可能存在的好前缀和好后缀子串匹配的位数
        if (prefix[m-r] == true) {
            return r;
        }
    }
    return 0;
}

/**
 BM
 */
int boyerMoore(string txt, string pattern)
{
    int N = (int)txt.length();
    int M = (int)pattern.length();
    int bc[size];
    generateBC(bc, size, pattern);
    int suffix[M];
    bool prefix[M];
    generateGS(pattern, suffix, prefix);
    int i = 0;
    while (i <= N - M) {
        int j = 0;
        for (j = M - 1; j >= 0; j--) {
            if (txt.at(i + j) != pattern.at(j)) {
                break;
            }
        }
        
        if (j < 0) {
            return i;
        }
        
        char bad = txt.at(i + j);
        int badIndex = bc[(int)bad];
        int x = j - badIndex;
        
        int y = 0;
        if (j < M - 1) {
            y = moveByGS(M, j, suffix, prefix);
        }
        if (x > y) {
            i = i + x;
        } else {
            i = i + y;
        }
    }
    
    return N;
}

