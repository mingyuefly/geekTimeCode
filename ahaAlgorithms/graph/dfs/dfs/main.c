//
//  main.c
//  dfs
//
//  Created by gmy on 2022/6/3.
//

#include <stdio.h>

int book[101], sum, n, e[101][101];
void dfs(int cur) {
    int i;
    printf("%d ", cur);
    sum++;
    if (sum == n) {
        return;;
    }
    for (i = 1; i <= n; i++) {
        if (e[cur][i] == 1 && book[i] == 0) {
            book[i] = 1;
            dfs(i);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int i, j, m, a, b;
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
    
    // 从1号顶点出发
    book[1] = 1;
    dfs(1);
    
    getchar();getchar();
    
    return 0;
}
