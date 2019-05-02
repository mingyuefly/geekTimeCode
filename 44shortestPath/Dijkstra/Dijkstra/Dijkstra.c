//
//  Dijkstra.c
//  Dijkstra
//
//  Created by mingyue on 2019/5/2.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "Dijkstra.h"

void Dijkstra(int start)
{
    int i, j, k, n, m, u, v, w, book[10] = {0}, e[10][10], dist[10], max = 999999, s = -1, min;
    printf("请输入顶点数和边数：\n");
    scanf("%d %d", &n, &m);
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
                e[i][j] = 0;
            } else {
                e[i][j] = max;
            }
        }
    }
    
    for (i = 1; i <= m; i++) {
        printf("请输入边：\n");
        scanf("%d %d %d", &u, &v, &w);
        e[u][v] = w;
    }
    
    for (i = 1; i <= n; i++) {
        dist[i] = e[1][i];
    }
    book[1] = 1;
    
    for (i = 1; i <= n - 1; i++) {
        // 找出dist中距离1顶点最短的顶点
        min = max;
        for (j = 1; j <= n; j++) {
            if (book[j] == 0 && dist[j] < min) {
                min = dist[j];
                s = j;
            }
        }
        book[s] = 1;
        
        // 松弛
        for (k = 1; k <= n; k++) {
            if (e[s][k] != max) {
                if (dist[k] > (dist[s] + e[s][k])) {
                    dist[k] = dist[s] + e[s][k];
                }
            }
        }
    }
    
    for (i = 1; i <= n; i++) {
        printf(" %d ", dist[i]);
    }
}
