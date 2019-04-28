//
//  geekZOmain.cpp
//  zeroOneBag
//
//  Created by Gguomingyue on 2019/2/2.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <stdio.h>

#include <iostream>
#include <cstdio>

using namespace std;

static int maxW = 0;
static int weight[5] = {2, 2, 4, 6, 3};
static int n = 5;
static int w = 9;
static int times = 0;
static int cx[5];

void force(int i, int cw) {
    for(int i=0;i<n;i++){
        cout << cx[i] <<" ";
    }
    cout << endl;
    cout << i << endl;
    cout << cw << endl;
    times++;
    cout << times << endl;
    if (cw == w || i == n) {
        if (cw > maxW && cw <= w) {
            maxW = cw;
        }
        return;
    }
    cx[i] = 0;
    force(i + 1, cw);
    if (cw + weight[i] <= w) {
    cx[i] = 1;
        force(i + 1, cw + weight[i]);
    }
}


int main(int argc, const char * argv[]) {
    
    force(0, 0);
    cout << endl;
    cout << maxW << endl;
    cout << times << endl;
    return 0;
}

