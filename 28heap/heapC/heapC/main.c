//
//  main.c
//  heapC
//
//  Created by Gguomingyue on 2019/5/18.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include "heapC.h"
#include <stdbool.h>

int main(int argc, const char * argv[]) {
    
    /*
     输入 14
     99 5 36 7 22 17 46 12 2 19 25 28 1 92
     验证
     */
    int i, num;
    printf("请输入n:\n");
    scanf("%d", &num);
    n = num;
    for (i = 1; i <= n; i++) {
        printf("请输入:\n");
        scanf("%d", &h[i]);
    }
    
    createC();
    
    for (int i = 1; i <= n; i++) {
        printf(" %d ", h[i]);
    }
    printf("\n");
    
    while (true) {
        int temp;
        printf("请插入：\n");
        scanf("%d", &temp);
        if (temp == 999999) {
            break;
        }
        insert(temp);
    }
    
    for (int i = 1; i <= n; i++) {
        printf(" %d ", h[i]);
    }
    printf("\n");
    
    for (int i = 0; i < 2; i++) {
        int out = outQueue();
        printf("out = %d\n", out);
        for (int i = 1; i <= n; i++) {
            printf(" %d ", h[i]);
        }
        printf("\n");
    }
    
    updateQueue(6, 1000);
    for (int i = 1; i <= n; i++) {
        printf(" %d ", h[i]);
    }
    printf("\n");
    updateQueue(8, 55);
    for (int i = 1; i <= n; i++) {
        printf(" %d ", h[i]);
    }
    printf("\n");
    
    heapSortC();
    
    for (int i = 1; i <= num; i++) {
        printf(" %d ", h[i]);
    }
    printf("\n");
    
    getchar();getchar();
    
    return 0;
}
