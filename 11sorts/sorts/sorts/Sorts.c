
//
//  Sorts.c
//  sorts
//
//  Created by Gguomingyue on 2019/4/11.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "Sorts.h"

/*
 冒泡排序
 */
void bubble_sorts(int a[], int size)
{
    if (size < 1) {
        return;
    }
    bool flag = false;
    for (int i = 0; i < size; i++) {
        flag = false;
        for (int j = 0; j < size - i - 1; j++) {
            //从左到右，不断把大的右移，每次内循环结束都确保将每轮最大的放在每轮的最右边
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}

/*
 插入排序 基本思想就是假设把一个数插入到一个有序数组中
 */
void insert_sorts(int a[], int size)
{
    // 假设左边的数据有序的，把右边的数据依次插入到左边有序数据中
    // 取i = 1, 也就是做初始化左边就1个数据肯定是有序的
    for (int i = 1; i < size; i++) {
        int value = a[i];
        for (int j = i-1; j >= 0; j--) {
            if (a[j] > a[j+1]) {
                // 不断向左边插入，直到比自己小的位置
                a[j+1] = a[j];
            } else {
                // 假设左边是有序的，所以可以break
                break;
            }
            a[j] = value;
        }
    }
}

/*
 选择排序 每次都拿左边元素和右边最小元素交换，所以是非稳定排序，比如两个相等的元素，左边的先和右边最小的交换，这样原来左边的在排序后会到右边
 */
void select_sorts(int a[], int size)
{
    for (int i = 0; i < size - 1; i++) {
        int min = a[i];//假设左起第一个是最小的
        int index = i;
        for (int j = i+1; j < size; j++) {
            if (a[j] < min) {
                min = a[j];// 找到i右边最小的
                index = j; // 记住右边最小的位置
            }
        }
        a[index] = a[i]; // 把i位置的和最小的交换
        a[i] = min;
    }
}

#define SORT_MAX  (1000000)

/*
 归并排序
 */
void merge_sorts(int a[], int size)
{
    merge_sorts_content(a, 0, size - 1);
}

void merge_sorts_content(int a[], int begin, int end)
{
    if (begin >= end) {
        return;
    }
    int middle = (begin + end) / 2;
    merge_sorts_content(a, begin, middle);
    merge_sorts_content(a, middle+1, end);
    merge_sentry(a, begin, middle, end);
}

void merge_sentry(int a[], int begin, int middle, int end)
{
    dump(a, 10);
    printf("begin = %d, middle = %d, end = %d\n", begin, middle, end);
    int leftSize = middle - (begin - 1);
    int rightSize = end - middle;
    printf("leftSize = %d, rightSize = %d\n", leftSize, rightSize);
    int * leftArray = (int *)malloc(sizeof(int) * leftSize);
    int * rightArray = (int *)malloc(sizeof(int) * rightSize);
    int * sumArray = (int *)malloc(sizeof(int) * (leftSize + rightSize));
    assert(leftArray != NULL);
    assert(rightArray != NULL);
    assert(sumArray != NULL);
    memset(leftArray, 0, leftSize * sizeof(int));
    memset(rightArray, 0, rightSize * sizeof(int));
    memset(sumArray, 0, sizeof(int) * (leftSize + rightSize));
    dump(leftArray, leftSize);
    dump(rightArray, rightSize);
    dump(sumArray, leftSize + rightSize);
    
    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = a[begin + i];
    }
    leftArray[leftSize] = SORT_MAX;
    dump(leftArray, leftSize);
    for (int i = 0; i < rightSize; i++) {
        rightArray[i] = a[middle + 1 + i];
    }
    rightArray[rightSize] = SORT_MAX;
    dump(rightArray, rightSize);
    int i = 0, j = 0, k = 0;
    while (i < leftSize || j < rightSize) {
        if (leftArray[i] < rightArray[j]) {
            sumArray[k] = leftArray[i];
            i++;
        } else {
            sumArray[k] = rightArray[j];
            j++;
        }
        k++;
    }
    dump(sumArray, leftSize + rightSize);
    
    for (int n = 0; n < leftSize + rightSize; n++) {
        a[begin + n] = sumArray[n];
    }
    free(leftArray);
    free(rightArray);
    free(sumArray);
    printf("查看a");
    dump(a, 10);
}

/*
 dump
 */
void dump(int a[],int size)
{
    int i = 0;
    
    printf("\r\n");
    for (i = 0; i < size; i++ )
    {
        printf("%d ",a[i]);
    }
    printf("\r\n");
    return;
}
