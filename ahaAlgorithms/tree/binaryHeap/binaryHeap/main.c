//
//  main.c
//  binaryHeap
//
//  Created by apple on 2022/6/25.
//
/**
 14
 99 5 36 7 22 17 46 12 2 19 25 28 1 92
 99 5 36 7 22 17 46 12 2 19 25 28 1 92
 1 2 17 5 19 28 46 12 7 22 25 99 36 92
 54
 68
 -1
 1 2 17 5 19 28 46 12 7 22 25 99 36 92 54 68
 1 2 5 7 12 17 19 22 25 28 36 46 54 68 92 99 
 */

#include <stdio.h>
int h[101]; // 用于存放堆的数组
int n; // 用来存储堆中元素的个数，也就是堆的大小

// 交换
void swap(int x, int y) {
    int t = h[x];
    h[x] = h[y];
    h[y] = t;
    return;;
}

// 向下调整函数
void siftdown(int i) {
    int t, flag = 0;
    while (i * 2 <= n && flag == 0) {
        if (h[i] > h[2 * i]) {
            t = 2 * i;
        } else {
            t = i;
        }
        if (i * 2 + 1 <= n) {
            if (h[t] > h[2 * i + 1]) {
                t = 2 * i + 1;
            }
        }
        if (t != i) {
            swap(t, i);
            i = t;
        } else {
            flag = 1;
        }
    }
    return;;
}

// 向上调整函数
void siftup(int i) {
    int flag = 0;
    if (i == 1) {
        return;
    }
    while (i != 1 && flag == 0) {
        if (h[i] < h[i / 2]) {
            swap(i, i / 2);
        } else {
            flag = 1;
        }
        i = i / 2;
    }
    return;
}

// 插入
void insert(void) {
    int y;
    scanf("%d", &y);
    if (y == -1) {
        return;
    } else {
        n++;
        h[n] = y;
        siftup(n);
        insert();
    }
}

// 建立堆的函数
void create(void) {
    int i;
    for (i = n / 2; i >= 1 ; i--) {
        siftdown(i);
    }
    return;;
}

// 删除最大的元素
int deleteMax(void) {
    int t = h[1];
    h[1] = h[n];
    n--;
    siftdown(1);
    return t;;
}

int main(int argc, const char * argv[]) {
    
    int i, num;
    scanf("%d", &num);
    
    for (i = 1; i <= num; i++) {
        scanf("%d", &h[i]);
    }
    n = num;
    
    for (i = 1; i <= n; i++) {
        printf("%d ", h[i]);
    }
    printf("\n");
    
    create();
    for (i = 1; i <= n; i++) {
        printf("%d ", h[i]);
    }
    printf("\n");
    
    insert();
    for (i = 1; i <= n; i++) {
        printf("%d ", h[i]);
    }
    printf("\n");
    
    num = n;
    for (i = 1; i <= num; i++) {
        printf("%d ", deleteMax());
    }
    
    getchar();
    getchar();
    
    return 0;
}
