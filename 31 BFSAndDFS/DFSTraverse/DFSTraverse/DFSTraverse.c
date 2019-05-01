//
//  BFSTraverse.c
//  BFSTraverse
//
//  Created by mingyue on 2019/5/1.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "DFSTraverse.h"

int min, n, max;
int e[101][101];
int book[10001] = {0};

void dfsFunction(int cur, int dis)
{
    int j;
    if (dis > min) {
        return;
    }
    if (cur == n) {
        if (dis < min) {
            min = dis;
        }
        return;
    }
    for (j = 1; j <= n; j++) {
        if (e[cur][j] != max && book[j] == 0) {
            book[j] = 1;
            dfsFunction(j, dis + e[cur][j]);
            book[j] = 0;
        }
    }
    return;
}
