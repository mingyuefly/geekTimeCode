//
//  main.c
//  BFSTraverse
//
//  Created by mingyue on 2019/5/1.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include "DFSTraverse.h"

int main(int argc, const char * argv[]) {
    
    int i, j, m, a, b, c;
    max = 999999;
    min = max;
    
    printf("请输入定点数目和边数目：\n");
    scanf("%d %d", &n, &m);
    
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
        scanf(" %d %d %d", &a, &b, &c);
        e[a][b] = c;
    }
    
    book[1] = 1;
    dfsFunction(1, 0);
    printf("%d", min);
    
    getchar(); getchar();
    
    return 0;
}
