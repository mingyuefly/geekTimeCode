//
//  main.c
//  bfs
//
//  Created by gmy on 2022/6/3.
//
/**
 5 5
 1 2
 1 3
 1 5
 2 4
 3 5
 1 2 3 5 4 
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int i, j, n, m, a, b, cur, book[101] = {0}, e[101][101];
    int que[10001], head, tail;
    scanf("%d %d", &n, &m);
    
    // 初始化二维矩阵
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
                e[i][j] = 0;
            } else {
                e[i][j] = 99999999;
            }
        }
    }
    
    // 读入定点之间的边
    for (i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }
    
    // 队列初始化
    head = 1;
    tail = 1;
    
    // 从1号顶点出发，将1号顶点加入队列
    que[tail] = 1;
    tail++;
    book[1] = 1;
    
    while (head < tail && tail <= n) {
        cur = que[head];
        for (i = 1; i <= n; i++) {
            if (e[cur][i] == 1 && book[i] == 0) {
                que[tail] = i;
                tail++;
                book[i] = 1;
            }
            if (tail > n) {
                break;
            }
        }
        head++;
    }
    
    for (i = 1; i < tail; i++) {
        printf("%d ", que[i]);
    }
    
    getchar(); getchar();
    
    return 0;
}
