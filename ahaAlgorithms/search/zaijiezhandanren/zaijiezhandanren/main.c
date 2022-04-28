//
//  main.c
//  zaijiezhandanren
//
//  Created by mingyue on 2022/4/22.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

/**
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.#.#
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############
*/

#include <stdio.h>

struct note {
    int x;
    int y;
};

char a[20][21];

int getNum(int i, int j) {
    int sum, x, y;
    sum = 0;
    x = i; y = j;
    while (a[x][y] != '#') {
        if (a[x][y] == 'G') {
            sum++;
        }
        x--;
    }
    x = i; y = j;
    while (a[x][y] != '#') {
        if (a[x][y] == 'G') {
            sum++;
        }
        x++;
    }
    x = i; y = j;
    while (a[x][y] != '#') {
        if (a[x][y] == 'G') {
            sum++;
        }
        y--;
    }
    x = i; y = j;
    while (a[x][y] != '#') {
        if (a[x][y] == 'G') {
            sum++;
        }
        y++;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    
    struct note que[401];
    int head, tail;
    int book[20][20] = {0};
    int i, j, k, sum, max = 0, mx, my, n, m, startX, startY, tx, ty;
    
    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    scanf("%d %d %d %d", &n, &m, &startX, &startY);
    
    for (i = 0; i <= n - 1; i++) {
        scanf("%s", a[i]);
    }
    
    head = 1;
    tail = 1;
    que[tail].x = startX;
    que[tail].y = startY;
    tail++;
    book[startX][startY] = 1;
    max = getNum(startX, startY);
    mx = startX;
    my = startY;
    while (head < tail) {
        for (k = 0; k <= 3; k++) {
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];
            if (tx < 0 || tx > n - 1 || ty < 0 || ty > m - 1) {
                continue;
            }
            if (a[tx][ty] == '.' && book[tx][ty] == 0) {
                book[tx][ty] = 1;
                que[tail].x = tx;
                que[tail].y = ty;
                tail++;
                sum = getNum(tx, ty);
                if (sum > max) {
                    max = sum;
                    mx = tx;
                    my = ty;
                }
            }
        }
        head++;
    }
    printf("(%d, %d)%d", mx, my, max);
    getchar();getchar();
    
    return 0;
}
