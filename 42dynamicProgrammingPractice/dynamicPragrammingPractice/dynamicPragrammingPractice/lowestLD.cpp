//
//  lowestLD.cpp
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
static int minDist[6][6] = {0};

void printResultFunction() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << minDist[i][j] << " ";
        }
        cout << endl;
    }
}

int minFunction(int x, int y, int z) {
    int minv = 100;
    if (x < minv) {
        minv = x;
    }
    if (y < minv) {
        minv = y;
    }
    if (z < minv) {
        minv = z;
    }
    return minv;
}

int lowestLD(char a[], int n, char b[], int m) {
    for (int j = 0; j < m; j++) {
        if (a[0] == b[j]) {
            minDist[0][j] = j;
        } else if (j != 0) {
            minDist[0][j] = minDist[0][j-1] + 1;
        } else {
            minDist[0][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == b[0]) {
            minDist[i][0] = i;
        } else if (i != 0) {
            minDist[i][0] = minDist[i-1][0] + 1;
        } else {
            minDist[i][0] = 1;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (a[i] == b[j]) {
                minDist[i][j] = minFunction(minDist[i-1][j] + 1, minDist[i][j-1] + 1, minDist[i-1][j-1]);
            } else {
                minDist[i][j] = minFunction(minDist[i-1][j] + 1, minDist[i][j-1] + 1, minDist[i-1][j-1] + 1);
            }
        }
    }
    return minDist[n-1][m-1];
}

int main(int argc, const char * argv[]) {
    
    lowestLD(a, n, b, m);
    cout << minDist[n-1][m-1] << endl;
    printResultFunction();
    
    return 0;
}
