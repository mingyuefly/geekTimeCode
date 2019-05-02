//
//  Bellman_FordOpimize.c
//  Bellman-FordOptimize
//
//  Created by mingyue on 2019/5/2.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "Bellman_FordOpimize.h"

void bellman_fordFunction(void)
{
    int i, k, n, m;
    int max = 999999;
    // 保存边 数组大小比边m大1
    int u[8], v[8], w[8];
    // first的大小比n的最大值小1，next比m的最大值大1;
    int first[6], next[8];
    int dist[6], book[6];
    // 遍历队列
    int queue[101] = {0}, head = 1, tail = 1;
    
    printf("请输入顶点数和边数:\n");
    scanf("%d %d", &n, &m);
    
    for (i = 1; i <= n; i++) {
        dist[i] = max;
    }
    dist[1] = 0;
    
    for (i = 1; i <= n; i++) {
        book[i] = 0;
    }
    
    for (i = 1; i <= n; i++) {
        first[i] = -1;
    }
    
    for (i = 1; i <= m; i++) {
        printf("请输入边：\n");
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
        next[i] = first[u[i]];
        first[u[i]] = i;
    }
    
    // 1顶点入队列
    queue[tail] = 1;
    tail++;
    book[1] = 1;
    
    while (head < tail) {
        k = first[queue[head]];
        while (k != -1) {
            if (dist[v[k]] > dist[u[k]] + w[k]) {
                dist[v[k]] = dist[u[k]] + w[k];
                if (book[v[k]] == 0) {
                    queue[tail] = v[k];
                    tail++;
                    book[v[k]] = 1;
                }
            }
            k = next[k];
        }
        book[queue[head]] = 0;
        head++;
    }
    
    for (i = 1; i <= n; i++) {
        printf(" %d ", dist[i]);
    }
}
