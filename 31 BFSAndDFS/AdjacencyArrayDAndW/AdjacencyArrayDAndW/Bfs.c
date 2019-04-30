//
//  Bfs.c
//  AdjacencyArrayDAndW
//
//  Created by  on 2019/4/30.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "Bfs.h"

void bfsFunction()
{
    int i, j, n, m, a, b, cur, book[101] = {0}, e[101][101];
    int queue[10001], head, tail;
    printf("请输入:\n");
    scanf("%d %d", &n, &m);
    
    // 初始化二维向量
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (i == j) {
                e[i][j] = 0;
            } else {
                e[i][j] = 999999;
            }
        }
    }
    
    // 加边
    for (i = 1; i <= m; i++) {
        printf("请输入边:\n");
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }
    
    // 队列初始化
    head = 1;
    tail = 1;
    
    queue[tail] = 1;
    tail++;
    book[1] = 1;
    
    while (head < tail && tail <= n) {
        cur = queue[head];
        for (i = 1; i <= n; i++) {
            if (e[cur][i] == 1 && book[i] == 0) {
                queue[tail] = i;
                book[i] = 1;
                tail++;
            }
            if (tail > n) {
                break;
            }
        }
        head++;
    }
    
    for (i = 1; i < tail; i++) {
        printf(" %d ", queue[i]);
    }
    
    getchar();getchar();
}
