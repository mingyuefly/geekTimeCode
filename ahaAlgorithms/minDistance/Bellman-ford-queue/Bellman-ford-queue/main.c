//
//  main.c
//  Bellman-ford-queue
//
//  Created by apple on 2022/6/22.
//
/**
 5 7
 1 2 2
 1 5 10
 2 3 3
 2 5 7
 3 4 4
 4 5 5
 5 3 6
 0 2 5 9 9
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int n, m, i, k;
    int u[8], v[8], w[8];
    // first要比n的最大值大1，next要比m最大值大1
    int first[6], next[8];
    int dis[6] = {0}, book[6] = {0};
    int que[101] = {0}, head = 1, tail = 1;
    int inf = 99999999;
    // 读入顶点个数和变得条数
    scanf("%d %d", &n, &m);
    
    // 初始化dis数组，这里是1号顶点到其余各个顶点的初始路程
    for (i = 1; i <= n; i++) {
        dis[i] = inf;
    }
    dis[1] = 0;
    
    // 初始化book数组，初始化为0，刚开始都不在队列中
    for (i = 1; i <= n; i++) {
        book[i] = 0;
    }
    
    // 初始化first数组下标1~n的值为-1，表示1~n顶点暂时都没有边
    for (i = 1; i <= n; i++) {
        first[i] = -1;
    }
    
    for (i = 1; i <= m; i++) {
        // 读入每一条边
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
        next[i] = first[u[i]];
        first[u[i]] = i;
    }
    
    // 1号顶点入队
    que[tail] = 1; tail++;
    book[1] = 1; //标记1号顶点已经入队列
    while (head < tail) {
        k = first[que[head]];
        while (k != -1) {
            if (dis[v[k]] > dis[u[k]] + w[k]) {
                dis[v[k]] = dis[u[k]] + w[k];
                if (book[v[k]] == 0) {
                    que[tail] = v[k];
                    tail++;
                    book[v[k]] = 1;
                }
            }
            k = next[k];
        }
        // 出队
        book[que[head]] = 0; // 同一个顶点可能还会进队列，目的是让所有边得到松弛
        head++;
    }
    
    // 输出最终结果
    for (i = 1; i <= n; i++) {
        printf("%d ", dis[i]);
    }
    
    getchar(); getchar();
    
    return 0;
}
