//
//  BFSTraverse.c
//  BFSTraverse
//
//  Created by mingyue on 2019/5/1.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "BFSTraverse.h"

typedef struct _node{
    int x;
    int s;
}Note;

void bfsFunction()
{
    int i, j, a, b, n, m, head, tail, start, end, flag = 0, e[101][101], max = 999999, book[10001] = {0};
    Note queue[100001];
    
    printf("请输入定点数目和边数目，起点和终点：\n");
    scanf("%d %d %d %d", &n, &m, &start, &end);
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
                e[i][j] = 0;
            } else {
                e[i][j] = max;
            }
        }
    }
    
    for (i = 1; i <= m; i++) {
        printf("请输入边：\n");
        scanf(" %d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }
    
    book[1] = 1;
    head = tail = 1;
    queue[tail].x = start;
    queue[tail].s = 0;
    tail++;
    
    while (head < tail) {
        for (i = 1; i <= n; i++) {
            if (e[queue[head].x][i] != max && book[i] == 0) {
                book[i] = 1;
                queue[tail].x = i;
                queue[tail].s = queue[head].s + 1;
                tail++;
            }
            if (queue[tail-1].x == end) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
        head++;
    }
    
    printf("%d", queue[tail-1].s);
}
