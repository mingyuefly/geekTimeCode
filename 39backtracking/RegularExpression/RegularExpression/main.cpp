//
//  main.cpp
//  RegularExpression
//
//  Created by Gguomingyue on 2019/1/28.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>

using namespace std;

static bool matched = false;
static char patten[] = "abcde*";
static int plen = 6;

void rematched(int ti, int pj, char text[], int tlen);
bool match(char text[], int tlen);

bool match(char text[], int tlen) {
    matched = false;
    rematched(0, 0, text, tlen);
    return matched;
}

void rematched(int ti, int pj, char text[], int tlen) {
    if (matched) return;
    if (pj == plen) { // 正则表达式到结尾
        if (ti == tlen) { //文本串到结尾
            matched = true;
            return;
        }
    }
    if (patten[pj] == '*') {
        for (int k = 0; k <= tlen - ti; k++) {
            rematched(ti + k, pj + 1, text, tlen);
        }
    } else if (patten[pj] == '?') {
        rematched(ti, pj + 1, text, tlen);
        rematched(ti + 1, pj + 1, text, tlen);
    } else if (ti < tlen && patten[pj] == text[ti]) {
        rematched(ti + 1, pj + 1, text, tlen);
    } else {
        
    }
}

int length(char text[]) {
    int l = 0;
    while (text[++l]) ;
    return l;
}


int main(int argc, const char * argv[]) {
    
    char text[] = "abcdeefkdjfkdjfkdjkjgjgjk";
    int tlen = length(text);
    cout << tlen << endl;
    match(text, tlen);
    cout << matched << endl;
    return 0;
}
