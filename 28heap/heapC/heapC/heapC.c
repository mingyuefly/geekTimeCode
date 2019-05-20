//
//  heap.c
//  heapC
//
//  Created by Gguomingyue on 2019/5/18.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "heapC.h"

int h[101];
int n;

/*
 交换函数
 */
void swapC(int x, int y)
{
    int temp;
    temp = h[x];
    h[x] = h[y];
    h[y] = temp;
}

/*
 向下调整
 */
void siftdownC(int i)
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
            swapC(temp, i);
            i = temp;
        }
    }
}

/*
 向上调整
 */
void siftupC(int i)
{
    if (i == 1) {
        return;
    }
    int flag = 0;
    while (i != 1 && flag == 0) {
        if (h[i] > h[i / 2]) {
            swapC(i, i / 2);
        } else {
            flag = 1;
        }
        i = i / 2;
    }
}

/*
 删除最大元素
 */
int deleteMaxC()
{
    int t = h[1];
    h[1] = h[n];
    n--;
    siftdownC(1);
    return t;
}

/*
 建堆
 */
void createC()
{
    for (int i = n / 2; i > 0; i--) {
        siftdownC(i);
    }
}

/*
 堆排序
 */
void heapSortC()
{
    while (n > 1) {
        swapC(1, n);
        n--;
        siftdownC(1);
    }
}

// 实现优先队列
/*
 插入
 */
void insert(int x)
{
    n++;
    h[n] = x;
    siftupC(n);
}

/*
 出队列
 */
int outQueue(void)
{
    return deleteMaxC();
}

/*
 更新
 */
void updateQueue(int index, int x)
{
    if (index > n || index <= 0) {
        return;
    }
    h[index] = x;
    siftupC(index);
}
