//
//  main.c
//  Dijkstra
//
//  Created by gmy on 2022/6/8.
//
/**
 6 9
 1 2 1
 1 3 12
 2 3 9
 2 4 3
 3 5 5
 4 3 4
 4 5 13
 4 6 15
 5 6 4
 0 1 8 4 13 17 66
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int e[10][10], dis[10], book[10], i, j, n, m, t1, t2, t3, u = 0, v, min;
    int inf = 99999999;
    // 读入n和m，n表示顶点数，m表示边的条数
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
    
    // 初始化dis数组，这里是1号顶点到其余各个顶点的初始路程
    for (i = 1; i <= n; i++) {
        dis[i] = e[1][i];
    }
    
    // book数组初始化
    for (i = 1; i <= n; i++) {
        book[i] = 0;
    }
    book[1] = 1;
    
    // Dijkstra算法核心语句
    for (i = 1; i <= n - 1; i++) {
        // 找到离1号顶点最近的顶点
        min = inf;
        for (j = 1; j <= n; j++) {
            if (book[j] == 0 && e[i][j] < min) {
                min = e[i][j];
                u = j;
            }
        }
        book[u] = 1;
        for (v = 1; v <= n; v++) {
            if (e[u][v] < inf) {
                if (dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                }
            }
        }
    }
    
    // 输出最终结果
    for (i = 1; i <= n; i++) {
        printf("%d ", dis[i]);
    }
    
    getchar(); getchar();
    
    return 0;
}
