//
//  main.cpp
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
static int minDist = 100;

void lowestLD(int i, int j, int edist) {
    if (i == n || j == m) {
        if (i < n) {
            edist += (n - i);
        }
        if (j < m) {
            edist += (m - j);
        }
        if (edist < minDist) {
            minDist = edist;
        }
        return;
    }
    
    if (a[i] == b[j]) {
        lowestLD(i+1, j+1, edist);
    } else {
        lowestLD(i+1, j, edist+1);
        lowestLD(i, j+1, edist+1);
        lowestLD(i+1, j+1, edist+1);
    }
}

int main(int argc, const char * argv[]) {
    
    lowestLD(0, 0, 0);
    cout << minDist << endl;
    
    return 0;
}
