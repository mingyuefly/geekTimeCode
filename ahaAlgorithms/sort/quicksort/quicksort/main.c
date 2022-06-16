//
//  main.c
//  quicksort
//
//  Created by apple on 2022/6/16.
//
/**
 10
 6 1 2 7 9 3 4 5 10 8
 1 2 3 4 5 6 7 8 9 10
 */

#include <stdio.h>
int a[101], n;

void quicksort(int left, int right) {
    int i, j, t, temp;
    if (left > right) {
        return;
    }
    temp = a[left];
    i =left;
    j = right;
    while (i != j) {
        while (a[j] >= temp && i < j) {
            j--;
        }
        while (a[i] <= temp && i < j) {
            i++;
        }
        if (i < j) {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[left] = a[i];
    a[i] = temp;
    quicksort(left, i - 1);
    quicksort(i + 1, right);
    return;
}

int main(int argc, const char * argv[]) {
    
    int i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    quicksort(1, n);
    for (i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    getchar();getchar();
    
    return 0;
}
