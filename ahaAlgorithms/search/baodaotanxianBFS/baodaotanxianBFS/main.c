//
//  main.c
//  baodaotanxianBFS
//
//  Created by mingyue on 2022/4/23.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

/**
 10 10 6 8
 1 2 1 0 0 0 0 0 2 3
 3 0 2 0 1 2 1 0 1 2
 4 0 1 0 1 2 3 2 0 1
 3 2 0 0 0 1 2 4 0 0
 0 0 0 0 0 0 1 5 3 0
 0 1 2 1 0 1 5 4 3 0
 0 1 2 3 1 3 6 2 1 0
 0 0 3 4 8 9 7 5 0 0
 0 0 0 8 7 8 6 0 1 2
 0 0 0 0 0 0 0 0 1 0
 38
 */

#include <stdio.h>

struct note {
    int x;
    int y;
};

int main(int argc, const char * argv[]) {
    
    struct note que[2501];
    int head, tail;
    int a[51][51];
    int book[51][51] = {0};
    int i, j, k, sum, max = 0, mx, my, n, m, startX, startY, tx, ty;
    
    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    scanf("%d %d %d %d", &n, &m, &startX, &startY);
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    head = 1;
    tail = 1;
    
    que[tail].x = startX;
    que[tail].y = startY;
    tail++;
    book[startX][startY] = 1;
    sum = 1;
    
    while (head < tail) {
        for (k = 0; k <= 3; k++) {
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];
            if (tx < 1 || tx > n || ty < 1 || ty > m) {
                continue;
            }
            if (a[tx][ty] > 0 && book[tx][ty] == 0) {
                sum++;
                book[tx][ty] = 1;
                que[tail].x = tx;
                que[tail].y = ty;
                tail++;
            }
        }
        head++;
    }
    
    printf("%d\n", sum);
    getchar();getchar();
    
    return 0;
}
