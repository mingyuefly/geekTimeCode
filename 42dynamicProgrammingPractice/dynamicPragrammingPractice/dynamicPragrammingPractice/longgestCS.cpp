//
//  longgestCS.cpp
//  dynamicPragrammingPractice
//
//  Created by Gguomingyue on 2019/2/20.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>
using namespace std;

static char a[6] = {'m', 'i', 't', 'c', 'm', 'u'};
static char b[6] = {'m', 't', 'a', 'c', 'n', 'u'};
static int n = 6;
static int m = 6;
static int maxDist[6][6] = {0};

void printResultFunction() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << maxDist[i][j] << " ";
        }
        cout << endl;
    }
}

int maxFunction(int x, int y, int z) {
    int maxv = -1;
    if (x > maxv) {
        maxv = x;
    }
    if (y > maxv) {
        maxv = y;
    }
    if (z > maxv) {
        maxv = z;
    }
    return maxv;
}

int longgetsCS(char a[], int n, char b[], int m) {
    for (int j = 0; j < m; j++) {
        if (a[0] == b[j]) {
            maxDist[0][j] = 1;
        } else if (j != 0) {
            maxDist[0][j] = maxDist[0][j-1];
        } else {
            maxDist[0][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == b[0]) {
            maxDist[i][0] = 1;
        } else if (i != 0) {
            maxDist[i][0] = maxDist[i-1][0];
        } else {
            maxDist[i][0] = 0;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (a[i] == b[j]) {
                maxDist[i][j] = maxFunction(maxDist[i-1][j], maxDist[i][j-1], maxDist[i-1][j-1] + 1);
            } else {
                maxDist[i][j] = maxFunction(maxDist[i-1][j], maxDist[i][j-1], maxDist[i-1][j-1]);
            }
        }
    }
    return maxDist[n-1][m-1];
}

int main(int argc, const char * argv[]) {
    
    longgetsCS(a, n, b, m);
    cout << maxDist[n-1][m-1] << endl;
    printResultFunction();
    
    return 0;
}
