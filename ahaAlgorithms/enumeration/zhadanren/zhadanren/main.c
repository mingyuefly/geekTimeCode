//
//  main.c
//  zhadanren
//
//  Created by mingyue on 2022/4/18.
//  Copyright © 2022 Gmingyue. All rights reserved.
//
/**
 #############
 #GG.GGG#GGG.#
 ###.#G#G#G#G#
 #.......#..G#
 #G#.###.#G#G#
 #GG.GGG.#.GG#
 #G#.#G#.#.###
 ##G...G.....#
 #G#.#G###.#G#
 #...G#GGG.GG#
 #G#.#G#G#.#G#
 #GG.GGG#G.GG#
 #############
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char a[20][21];
    int i, j, sum, map = 0, p, q, x, y, n, m;
    scanf("%d %d", &n, &m);
    
    for (i = 0; i <= n - 1; i++) {
        scanf("%s", a[i]);
    }
    
    
    for (i = 0; i <= n - 1; i++) {
        for (j = 0; j <= m - 1; j++) {
            if (a[i][j] == '.') {
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
                if (sum > map) {
                    map = sum;
                    p = i;
                    q = j;
                }
            }
        }
    }
    
    printf("(%d, %d)%d", p, q, map);
    getchar();getchar();
    
    return 0;
}
