//
//  statesChangeFunction.cpp
//  shortestPath
//
//  Created by Gguomingyue on 2019/2/15.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>

using namespace std;

static int n = 4;
static int w[4][4] = {{1, 3, 5, 9}, {2, 1, 3, 4}, {5, 2, 6, 7}, {6, 8, 4, 3}};
static int minDist = 0;
static int mem[4][4] = {0};

void statesChangeObserve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mem[i][j];
            if (mem[i][j] >= 10) {
                cout << "  ";
            } else {
                cout << "   ";
            }
        }
        cout << endl;
    }
}

int minFun(int x, int y){
    if (x > y) {
        return y;
    }
    return x;
}

int minDistDP(int i, int j) {
    
    if (i == 0 && j == 0) {
        return w[i][j];
    }
    if (mem[i][j] > 0) {
        return mem[i][j];
    }
    int minLeft = 1000;
    if ((j - 1) >= 0) {
        minLeft = minDistDP(i, j - 1);
    }
    int minUp = 1000;
    if ((i - 1) >= 0) {
        minUp = minDistDP(i - 1, j);
    }
    int currMinDist = w[i][j] + minFun(minLeft, minUp);
    mem[i][j] = currMinDist;
    
    return currMinDist;
}


int main(int argc, const char * argv[]) {
    
    //cout << "statesChangeFunction.cpp" << endl;
    minDist = minDistDP(3, 3);
    cout << minDist << endl;
    statesChangeObserve();
    
    return 0;
}
