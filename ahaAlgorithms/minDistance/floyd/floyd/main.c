//
//  main.c
//  floyd
//
//  Created by gmy on 2022/6/7.
//
/**
 4 8
 1 2 2
 1 3 6
 1 4 4
 2 3 3
 3 1 7
 3 4 1
 4 1 5
 4 3 12

 1 1 0
 1 2 2
 1 3 5
 1 4 4
 2 1 9
 2 2 0
 2 3 3
 2 4 4
 3 1 6
 3 2 8
 3 3 0
 3 4 1
 4 1 5
 4 2 7
 4 3 10
 4 4 0
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int e[10][10], k, i, j, n, m, t1, t2, t3;
    int inf = 99999999;
    // 读入n和m，n表示顶点个数，m表示边的条数
    scanf("%d %d", &n, &m);
    
    // 初始化
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
                e[i][j] = 0;
            } else {
                e[i][j] = inf;
            }
        }
    }
    
    // 读入边
    for (i = 1; i <= m; i++) {
        scanf("%d %d %d", &t1, &t2, &t3);
        e[t1][t2] = t3;
    }
    
    // floyd
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (e[i][j] > e[i][k] + e[k][j]) {
                    e[i][j] = e[i][k] + e[k][j];
                }
            }
        }
    }
    printf("\n");
    
    // 输出最终结果
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d %d %d", i, j, e[i][j]);
            printf("\n");
        }
    }
    printf("\n");
    
    return 0;
}
