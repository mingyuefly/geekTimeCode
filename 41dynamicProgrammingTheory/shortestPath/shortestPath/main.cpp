//
//  main.cpp
//  shortestPath
//
//  Created by Gguomingyue on 2019/2/15.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>

using namespace std;

static int n = 4;
static int w[4][4] = {{1, 3, 5, 9}, {2, 1, 3, 4}, {5, 2, 6, 7}, {6, 8, 4, 3}};
static int minDist = 1000;

static int times = 0;

void minDistBT(int i, int j, int dist, int w[][4], int n) {
    cout << i << " " << j << " " << dist << endl;
    if (i == n &&  j == n) {
        cout << times << ":" << dist << endl;
        times++;
        if (dist < minDist) {
            minDist = dist;
        }
        return;
    }
    if (i < n) { // 往下走，更新i = i + 1，j = j
        minDistBT(i + 1, j, dist + w[i+1][j], w, n);
    }
    if (j < n) { // 往右走，更新i = i，j = j + 1
        minDistBT(i, j + 1, dist + w[i][j+1], w, n);
    }
}

int main(int argc, const char * argv[]) {
    
    minDistBT(0, 0, 1, w, n);
    cout << minDist << endl;
    cout << times << endl;
    return 0;
}
