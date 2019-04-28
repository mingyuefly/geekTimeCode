//
//  dynamicProgramming.cpp
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
static int states[4][4] = {0};

void statesChangeObserve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << states[i][j];
            if (states[i][j] >= 10) {
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

int minDistDP(int matrix[4][4], int n) {
    
    int sum = 0;
    for (int j = 0; j < n; j++) {
        sum += w[0][j];
        states[0][j] = sum;
    }
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += w[i][0];
        states[i][0] = sum;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            states[i][j] = w[i][j] + minFun(states[i-1][j], states[i][j-1]);
        }
    }
    
    return states[n-1][n-1];
}


int main(int argc, const char * argv[]) {
    
    minDist = minDistDP(w, n);
    cout << minDist << endl;
    statesChangeObserve();
    
    return 0;
}
