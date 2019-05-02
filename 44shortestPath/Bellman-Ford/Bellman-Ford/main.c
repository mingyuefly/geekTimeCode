//
//  main.c
//  Bellman-Ford
//
//  Created by mingyue on 2019/5/2.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int n, m, i, j, a, b, c, u[10], v[10], w[10], max = 999999;
    int dist[10];
    printf("请输入顶点数和边数：\n");
    scanf("%d %d", &n, &m);
    
    for (i = 1; i <= m; i++) {
        printf("请输入边：\n");
        scanf("%d %d %d", &a, &b, &c);
        u[i] = a;
        v[i] = b;
        w[i] = c;
    }
    
    for (i = 1; i <= n; i++) {
        dist[i] = max;
    }
    dist[1] = 0;
    
    for (i = 1; i <= n - 1; i++) {
        for (j = 1; j <= m; j++) {
            if (dist[v[j]] > dist[u[j]] + w[j]) {
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }
    
    for (i = 1; i <= n; i++) {
        printf(" %d ", dist[i]);
    }
    
    getchar();getchar();
    
    return 0;
}
