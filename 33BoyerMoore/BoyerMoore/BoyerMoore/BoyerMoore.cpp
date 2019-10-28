//
//  BoyerMoore.cpp
//  BoyerMoore
//
//  Created by Gguomingyue on 2019/10/28.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "BoyerMoore.hpp"

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

int boyerMoore(string txt, string pattern)
{
    int N = (int)txt.length();
    int M = (int)pattern.length();
    int bc[size];
    generateBC(bc, size, pattern);
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
        i = i + (j - badIndex);
    }
    
    return N;
}


