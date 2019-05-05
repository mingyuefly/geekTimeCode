//
//  main.c
//  Floyd
//
//  Created by mingyue on 2019/5/1.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int i, j, n, m, a, b, c, k, e[101][101], max = 999999;
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
        printf("请输入边:\n");
        scanf("%d %d %d", &a, &b, &c);
        e[a][b] = c;
    }
    
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (e[i][j] > (e[i][k] + e[k][j])) {
                    e[i][j] = e[i][k] + e[k][j];
                }
            }
        }
    }
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf(" %d ", e[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
