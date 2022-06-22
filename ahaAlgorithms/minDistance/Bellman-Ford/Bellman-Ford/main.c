//
//  main.c
//  Bellman-Ford
//
//  Created by apple on 2022/6/20.
//
/**
 5 5
 2 3 2
 1 2 -3
 1 5 5
 4 5 2
 3 4 3
 0 -3 -1 2 4 
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int dis[10], i, k, n, m, u[10], v[10], w[10], check, flag;
    int inf = 99999999;
    // 读入n和m，n表示顶点个数，m表示边个数
    scanf("%d %d", &n, &m);
    // 读入边
    for (i = 1; i <= m; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }
    // 初始化dis数组，这里是1号顶点到其余各个顶点的初始路程
    for (i = 1; i <= n; i++) {
        dis[i] = inf;
    }
    dis[1] = 0;
    
    // Bellman-Ford算法核心语句
    for (k = 1; k <= n - 1; k++) {
        check = 0;
        for (i = 1; i <= m; i++) {
            if (dis[v[i]] > dis[u[i]] + w[i]) {
                dis[v[i]] = dis[u[i]] + w[i];
                check = 1;
            }
        }
        // 松弛完毕后检测数组dis是否有更新
        if (check == 0) {
            break;
        }
    }
    
    // 检测负权回路
    flag = 0;
    for (i = 1; i <= m; i++) {
        if (dis[v[i]] > dis[u[i]] + w[i]) {
            flag = 1;
        }
    }
    
    if (flag == 1) {
        printf("此图含有负权回路");
    } else {
        // 输出最终结果
        for (i = 1; i <= n; i++) {
            printf("%d ", dis[i]);
        }
    }
    
    getchar(); getchar();
    
    return 0;
}
