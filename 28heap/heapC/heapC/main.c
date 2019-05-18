//
//  main.c
//  heapC
//
//  Created by Gguomingyue on 2019/5/18.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <stdio.h>

int h[101], n;

/*
 交换函数
 */
void swap(int x, int y)
{
    int temp;
    temp = h[x];
    h[x] = h[y];
    h[y] = temp;
}

/*
 向下调整
 */
void siftdown(int i)
{
    int flag = 0, temp = 0;
    while (i * 2 <= n && flag == 0) {
        if (h[i] < h[i * 2]) {
            temp = i * 2;
        } else {
            temp = i;
        }
        if ((i * 2 + 1) <= n) {
            if (h[temp] < h[i * 2 + 1]) {
                temp = i * 2 + 1;
            }
        }
        if (temp == i) {
            flag = 1;
        } else {
            swap(temp, i);
            i = temp;
        }
    }
}

/*
 向上调整
 */
void siftup(int i)
{
    if (i == 1) {
        return;
    }
    int flag = 0;
    while (i != 1 && flag == 0) {
        if (h[i] < h[i / 2]) {
            swap(i, i / 2);
        } else {
            flag = 1;
        }
        i = i / 2;
    }
}

/*
 删除最大元素
 */
int deleteMax()
{
    int t = h[1];
    h[1] = h[n];
    n--;
    siftdown(n);
    return t;
}

/*
 建堆
 */
void create()
{
    for (int i = n / 2; i > 0; i--) {
        siftdown(i);
    }
}

/*
 堆排序
 */
void heapSort()
{
    while (n > 1) {
        swap(1, n);
        n--;
        siftdown(1);
    }
}


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
    
    create();
    
    for (int i = 1; i <= n; i++) {
        printf(" %d ", h[i]);
    }
    printf("\n");
    
    heapSort();
    
    for (int i = 1; i <= num; i++) {
        printf(" %d ", h[i]);
    }
    printf("\n");
    
    return 0;
}
