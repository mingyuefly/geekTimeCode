//
//  main.c
//  zijiezhadanrenDFD
//
//  Created by mingyue on 2022/4/23.
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
int book[20][20], max, mx, my, n, m;
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

void dfs(int x, int y) {
    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int k, sum, tx, ty;
    sum = getNum(x, y);
    if (sum > max) {
        max = sum;
        mx = x;
        my = y;
    }
    for (k = 0; k <= 3; k++) {
        tx = x + next[k][0];
        ty = y + next[k][1];
        if (tx < 0 || tx > n - 1 || ty < 0 || ty > m - 1) {
            continue;
        }
        if (a[tx][ty] == '.' && book[tx][ty] == 0) {
            book[tx][ty] = 1;
            dfs(tx, ty);
//            book[tx][ty] = 0;
        }
    }
    return;
}

int main(int argc, const char * argv[]) {
    int i, startX, startY;
    scanf("%d %d %d %d", &n, &m, &startX, &startY);
    for (i = 0; i <= n - 1; i++) {
        scanf("%s", a[i]);
    }
    book[startX][startY] = 1;
    max = getNum(startX, startY);
    mx = startX;
    my = startY;
    dfs(startX, startY);
    
    printf("(%d, %d)%d", mx, my, max);
    getchar();getchar();
    
    return 0;
}
