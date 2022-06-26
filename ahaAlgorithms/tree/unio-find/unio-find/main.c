//
//  main.c
//  unio-find
//
//  Created by apple on 2022/6/26.
//
/**
 10 9
 1 2
 3 4
 5 2
 4 6
 2 6
 8 7
 9 7
 1 6
 2 4
 3
 */

/**
 10 9
 1 2
 1 1 3 4 5 6 7 8 9 10
 3 4
 1 1 3 3 5 6 7 8 9 10
 5 2
 5 1 3 3 5 6 7 8 9 10
 4 6
 5 1 3 3 5 3 7 8 9 10
 2 6
 5 5 5 3 5 3 7 8 9 10
 8 7
 5 5 5 3 5 3 8 8 9 10
 9 7
 5 5 5 3 5 3 8 9 9 10
 1 6
 5 5 5 3 5 5 8 9 9 10
 2 4
 5 5 5 5 5 5 8 9 9 10
 5 5 5 5 5 5 8 9 9 10
 3
 */

#include <stdio.h>
int f[1000] = {0}, n, m, k, sum = 0;

// 初始化
void init(void) {
    int i;
    for (i = 1; i <= n; i++) {
        f[i] = i;
    }
    return;
}

//
int getf(int v) {
    if (f[v] == v) {
        return v;
    } else {
        // 顺路修改为最终编号
        f[v] = getf(f[v]);
        return f[v];
    }
}

//
void merge(int v, int u) {
    int t1, t2;
    t1 = getf(v);
    t2 = getf(u);
    if (t1 != t2) {
        f[t2] = t1;
    }
//    for (int i = 1; i <= n; i++) {
//        printf("%d ", f[i]);
//    }
//    printf("\n");
    return;
}

int main(int argc, const char * argv[]) {
    
    int i, x, y;
    scanf("%d %d", &n, &m);
    
    init();
    for (i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        merge(x, y);
    }
    
//    for (i = 1; i <= n; i++) {
//        printf("%d ", f[i]);
//    }
//    printf("\n");
    
    for (i = 1; i <= n; i++) {
        if (i == f[i]) {
            sum++;
        }
    }
    
    printf("%d\n", sum);
    getchar(); getchar();
    
    return 0;
}
