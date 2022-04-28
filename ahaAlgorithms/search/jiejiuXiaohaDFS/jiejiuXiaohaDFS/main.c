//
//  main.c
//  jiejiuXiaohaDFS
//
//  Created by mingyue on 2022/4/13.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <stdio.h>

int n, m, p, q, min = 99999999;
int a[51][51], book[51][51];

void dfs(int x, int y, int step){
    int next[4][2] = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
    if (x == p && y == q) {
        if (step < min) {
            min = step;
        }
        return;
    }
    for (int k = 0; k < 3; k++) {
        int tx = x + next[k][0];
        int ty = y + next[k][1];
        if (tx < 1 || tx > n || ty < 1 || ty > m) {
            continue;
        }
        if (a[tx][ty] == 0 && book[tx][ty] == 0) {
            book[tx][ty] = 1;
            dfs(tx, ty, step + 1);
            book[tx][ty] = 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    int i, j, startX, startY;
    // 读入n和m，n为行，m为列
    scanf("%d %d", &n, &m);
    // 读入迷宫
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    // 读入起点和终点坐标
    scanf("%d %d %d %d", &startX, &startY, &p, &q);
    
    // 从起点开始搜索
    book[startX][startY] = 1;
    dfs(startX, startY, 0);
    
    printf("%d", min);
    getchar();getchar();
    
    return 0;
}
