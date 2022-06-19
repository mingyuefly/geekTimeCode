//
//  main.c
//  Dijkstra1
//
//  Created by apple on 2022/6/19.
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
 0 1 8 4 13 17
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    // u[6], v[6], w[6]用来存储具体的边信息，first[5], next[6]实现邻接表
    int u[6], v[6], w[6], dis[10], book[10], i, j, n, m, k, x = 0, y, min, first[5], next[6];
    int inf = 99999999;
    // 读入n和m，n表示顶点数，m表示边的条数
    scanf("%d %d", &n, &m);
    
    // 初始化
    for (i = 1; i <= n; i++) {
        first[i] = -1;
    }
    
    // 读入边
    for (i = 1; i <= m; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
        next[i] = first[u[i]]; // 将从i点出发的边连成一个链表
        first[u[i]] = i; // 记录每一个定点链表的第一个边
    }
    
//    // 遍历所有边
//    for (i = 1; i <= n; i++) {
//        k = first[i];
//        while (k != -1) {
//            printf("%d %d %d\n", u[k], v[k], w[k]);
//            k = next[k];
//        }
//    }
    
    // 初始化dis数组，这里是1号顶点到其余各个顶点的初始路程
    for (i = 2; i <= n; i++) {
        dis[i] = inf;
    }
    dis[1] = 0;
    k = first[1];
    while (k != -1) {
        dis[v[k]] = w[k];
        k = next[k];
    }
    
    // book数组初始化
    for (i = 1; i <= n; i++) {
        book[i] = 0;
    }
    book[1] = 1;
    
    for (i = 1; i <= n - 1; i++) {
        // 找到离1号定点最近的点
        min = inf;
        for (j = 1; j <= n; j++) {
            if (book[j] == 0 && dis[j] < min) {
                min = dis[j];
                x = j;
            }
        }
        book[x] = 1;
        for (y = 1; y <= n; y++) {
            k = first[y];
            while (k != -1) {
                if (v[k] == x) {
                    if (dis[y] > dis[x] + w[k]) {
                        dis[y] = dis[x] + w[k];
                    }
                    break;
                }
                k = next[k];
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
