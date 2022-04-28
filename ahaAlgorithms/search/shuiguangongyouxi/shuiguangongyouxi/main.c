//
//  main.c
//  shuiguangongyouxi
//
//  Created by mingyue on 2022/4/28.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <stdio.h>

int a[51][51];
int book[51][51], n, m, flag = 0;
struct note {
    int x;
    int y;
}s[100];
int top = 0;

void dfs(int x, int y, int front) {
    int i;
    if (x == n && y == m + 1) {
        flag = 1;
        for (i = 1; i <= top; i++) {
            printf("(%d, %d)", s[i].x, s[i].y);
        }
        printf("\n");
        return;
    }
    if (x < 1 || x > n || y < 1 || y > m) {
        return;
    }
    if (book[x][y] == 1) {
        return;
    }
    book[x][y] = 1;
    top++;
    s[top].x = x;
    s[top].y = y;
    // 直管
    if (a[x][y] >= 5 && a[x][y] <= 6) {
        if (front == 1) {
            dfs(x, y + 1, 1);
        }
        if (front == 2) {
            dfs(x + 1, y, 2);
        }
        if (front == 3) {
            dfs(x, y - 1, 3);
        }
        if (front == 4) {
            dfs(x - 1, y, 4);
        }
    }
    
    // 弯管
    if (a[x][y] >= 1 && a[x][y] <= 4) {
        if (front == 1) {
            dfs(x + 1, y, 2);
            dfs(x - 1, y, 4);
        }
        if (front == 2) {
            dfs(x, y + 1, 1);
            dfs(x, y - 1, 3);
        }
        if (front == 3) {
            dfs(x - 1, y, 4);
            dfs(x + 1, y, 2);
        }
        if (front == 4) {
            dfs(x, y + 1, 1);
            dfs(x, y - 1, 3);
        }
    }
    
    book[x][y] = 0;
    top--;
    return;
}

int main(int argc, const char * argv[]) {
    
    int i, j, num = 0;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    dfs(1, 1, 1);
    if (flag == 0) {
        printf("impossible\n");
    } else {
        printf("找到铺设方案\n");
    }
    getchar();getchar();
    
    return 0;
}
