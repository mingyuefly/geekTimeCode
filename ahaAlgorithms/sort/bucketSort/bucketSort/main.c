//
//  main.c
//  bucketSort
//
//  Created by apple on 2022/6/16.
//
/**
 10
 8 100 50 22 15 6 1 1000 999 0
 0 1 6 8 15 22 50 100 999 1000
 1000 999 100 50 22 15 8 6 1 0 
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int book[1001], i, j, t, n;
    for (i = 0; i <= 1000; i++) {
        book[i] = 0;
    }
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++) {
        scanf("%d", &t);
        book[t]++;
    }
    
    for (i = 0; i <= 1000; i++) {
        for (j = 1; j <= book[i]; j++) {
            printf("%d ", i);
        }
    }
    
    printf("\n");
    
    for (i = 1000; i >= 0; i--) {
        for (j = 1; j <= book[i]; j++) {
            printf("%d ", i);
        }
    }
    
    getchar(); getchar();
    
    return 0;
}
