//
//  Sorts.c
//  sorts
//
//  Created by Gguomingyue on 2019/4/11.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "Sorts.h"


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
    //merge_sentry(a, begin, middle, end);
    merge_content(a, begin, middle, end);
}

void merge_content(int a[], int begin, int middle, int end)
{
    //dump(a, 10);
    //printf("begin = %d, middle = %d, end = %d\n", begin, middle, end);
    int * sumArray = (int *)malloc((end - (begin - 1)) * sizeof(int));
    assert(sumArray != NULL);
    //memset(sumArray, 0, (end - (begin - 1)) * sizeof(int));
    int i = 0, j = 0, k = 0;
    int leftSize = middle - (begin - 1);
    int rightSize = end - middle;
    //printf("leftSize = %d, rightSize = %d\n", leftSize, rightSize);
    while (i < leftSize && j < rightSize) {
        if (a[begin + i] <= a[middle + 1 + j]) {
            sumArray[k] = a[begin + i];
            i++;// 左边小，左边+1
        } else {
            sumArray[k] = a[middle + 1 + j];
            j++;// 右边小，右边+1
        }
        k++;
    }
    //dump(sumArray, end - (begin - 1));
    if (i < leftSize) {
        for (int m = i; m < leftSize; m++) {
            sumArray[k] = a[begin + m];
            k++;
        }
    }
    if (j < rightSize) {
        for (int m = j; m < rightSize; m++) {
            sumArray[k] = a[middle + 1 + m];
            k++;
        }
    }
    //dump(sumArray, end - (begin - 1));
    for (int n = 0; n < end - (begin - 1); n++) {
        a[begin + n] = sumArray[n];
    }
    
    free(sumArray);
    //printf("查看a");
    //dump(a, 10);
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
    dump(leftArray, leftSize);
    for (int i = 0; i < rightSize; i++) {
        rightArray[i] = a[middle + 1 + i];
    }
    dump(rightArray, rightSize);
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            sumArray[k] = leftArray[i];
            i++;
        } else {
            sumArray[k] = rightArray[j];
            j++;
        }
        k++;
    }
    dump(sumArray, leftSize + rightSize);
    if (i < leftSize) {
        // 左边边有剩余
        for (int m = i; m < leftSize; m++) {
            sumArray[k] = leftArray[m];
            k++;
        }
    }
    if (j < rightSize) {
        // 右边有剩余
        for (int m = j; m < rightSize; m++) {
            sumArray[k] = rightArray[m];
            k++;
        }
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
 快速排序
 */
void quick_sorts(int a[], int size)
{
    quick_sorts_content(a, 0, size-1);
}

void quick_sorts_content(int a[], int left, int right)
{
    if (left >= right) {
        return;
    }
    int middle = partition(a, left, right);
    quick_sorts_content(a, left, middle-1);
    quick_sorts_content(a, middle+1, right);
}

int partition(int a[], int left, int right)
{
    // 主要思路就是先用哨兵站在第一个大于pivot的位置，往后遍历发现一个小于pivo的元素，就将其与之前哨兵所站的元素交换，然后将哨兵下移到下一个大于pivot的位置，这样以来哨兵看的永远是左起第一个大于pivot的元素
    int pivot = a[right];
    int i = left;
    int j = left;
    for (; j < right; j++) {
        if (a[j] < pivot) {
            if (i != j) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                // 把小于pivot的j位置的元素和i位置的元素交换,也就是把小的往做变换
            } else {
                
            }
            i++;
            // i 移动到下一个位置，i左边的都比pivot小
        } else {
            // i 停留在第一个比pivot大的地方
        }
    }
    int temp = a[i];
    a[i] = pivot;
    a[right] = temp;
    
    return i;
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
