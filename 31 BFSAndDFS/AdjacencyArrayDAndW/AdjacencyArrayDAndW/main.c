//
//  main.c
//  AdjacencyArrayDAndW
//
//  Created by Gguomingyue on 2019/4/26.
//  Copyright © 2019 Gmingyue. All rights reserved.
/*
             1
           / | \
          2  3——5
         /
        4
*/


#include <stdio.h>

int book[101], sum, n, e[101][101];

void dfs(int cur)
{
    if (sum == n) {
        return;
    }
    sum++;
    printf(" %d ", cur);
    for (int i = 1; i <= n; i++) {
        if (e[cur][i] == 1 && book[i] == 0) {
            book[i] = 1;
            dfs(i);
        }
    }
    return;
}

int main(int argc, const char * argv[]) {
    
    int i, j, m, a, b;
    printf("请输入：\n");
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (i == j) {
                e[i][j] = 0;
            } else {
                e[i][j] = 999999;
            }
        }
    }
    for (i = 1; i <= m; i++) {
        printf("请输入顶点:\n");
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }
    
    sum = 0;
    book[1] = 1;
    dfs(1);
    //getchar(); getchar();
    
    return 0;
}
