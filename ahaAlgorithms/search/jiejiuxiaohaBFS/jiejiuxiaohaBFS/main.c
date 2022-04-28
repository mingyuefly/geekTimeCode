//
//  main.c
//  jiejiuxiaohaBFS
//
//  Created by mingyue on 2022/4/16.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <stdio.h>

struct note {
    int x;
    int y;
    int f;
    int s;
};

int main(int argc, const char * argv[]) {
    
    struct note que[2501];
    int a[51][51] = {0}, book[51][51] = {0};
    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int head, tail;
    int i, j, k, n, m, startX, startY, p = 0, q = 0, tx, ty, flag;
    
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d %d %d %d", &startX, &startY, &p, &q);
    
    head = tail = 1;
    que[tail].x = startX;
    que[tail].y = startY;
    que[tail].f = 0;
    que[tail].s = 0;
    tail++;
    book[startX][startY] = 1;
    
    flag = 0;
    
    while (head < tail) {
        for (k = 0; k <= 3; k++) {
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];
            if (tx < 0 || tx > n || ty < 0 || ty > m) {
                continue;
            }
            if (a[tx][ty] == 0 && book[tx][ty] == 0) {
                book[tx][ty] = 1;
                que[tail].x = tx;
                que[tail].y = ty;
                que[tail].f = head;
                que[tail].s = que[head].s + 1;
                tail++;
            }
            if (tx == p && ty == q) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
        head++;
    }
    printf("%d", que[tail - 1].s);
    printf("\n");
    for (int i = tail - 1; i > 0; i = que[i].f) {
        printf("(%d, %d)", que[i].x, que[i].y);
    }
    printf("\n");
    getchar();getchar();
    
    return 0;
}
