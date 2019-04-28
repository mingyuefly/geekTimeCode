//
//  sorts.c
//  sorts
//
//  Created by Gguomingyue on 2019/4/12.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "sorts.h"

void dump(int a[],int size)
{
    int i = 0;
    
    printf("\r\n");
    
    for(i = 0; i <size; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\r\n");
}

/*
 计数排序
 */
void count_sorts(int a[], int size)
{
    int i = 0;
    int max = 0;
    int *count = NULL;
    int *res = NULL;
    
    // 求最大数
    for (i = 0; i < size; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    
    // count数组 计数
    count = (int *)malloc((max + 1) * sizeof(int));
    if (count == NULL) {
        return;
    }
    memset(count, 0, max * sizeof(int));
    for (i = 0; i < size; i++) {
        int temp = a[i];
        count[temp]++;
        //count[a[i]]++;// 计算每个桶的容量
    }
    
    // 依次累加
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];//计数排序关键在这里，max不能太大，否则空间复杂度控制不了
    }
    
    res = (int *)malloc(size * sizeof(int));
    assert(res != NULL);
    for (int i = size - 1; i >= 0; i--) {
        // 将相同的元素从右向左依次放入所属区间位置
        int num = count[a[i]];
        res[num - 1] = a[i];
        count[a[i]]--;
    }
    memcpy(a, res, size * sizeof(int));
    
    free(res);
    free(count);
}

void count_sorts_test(void)
{
    int a [17]={1,5,6,8,10,9,3,1,2,1,5,6,3,9,5,3,1};
    printf("\r\n conunt sort test ....");
    count_sorts(a, 17);
    dump(a, 17);
}

/*
 基数排序 a[]为将要排序数组，size为数组长度，num_count为每个元素最大位数
 */
void radix_sorts(int a[], int size, int num_count)
{
    int count[10] = {0};
    int *pres = NULL;
    pres = (int *)malloc(sizeof(int) * size);
    assert(pres != NULL);
    
    int i = 0;
    int j = 0;
    int pral = 0;
    int index = 0;
    int break_flag = 0;
    for (i = 0; i < num_count; i++) {
        memset(count, 0, 10 * sizeof(int));
        // 求当前计数
        pral = pow(10, i);
        
        // 计数
        for (j = 0; j < size; j++) {
            index = (a[j]/pral)%10;
            count[index]++;
        }
        
        /*小的优化，可能位数最大的就1，其他的位数差很多*/
        if (count[0] == 9) {
            break_flag++;
        }
        if (break_flag >= 2) {
            printf("\r\n %i",i);
            break;
        }
        
        // 累加
        for (j = 1; j < 10; j++) {
            count[j] += count[j - 1];
        }
        
        // 排序
        for (j = size - 1; j >= 0; j--) {
            index = (a[j]/pral)%10;
            pres[count[index] - 1] = a[j];
            count[index]--;
        }
        memcpy(a, pres, size * sizeof(int));
    }
}

void radix_sorts_test(void)
{
    int a[10] = {123,12341,1232134,124,236,128,1112313129,98,9,8989};
    printf("\r\n radix sort test.....");
    radix_sorts(a, 10, 10);
    dump(a, 10);
}

/*
 桶排序
 */
struct barrel{
    int node[10];
    int count;
};

int partition(int a[],int left,int right)
{
    int i = left;
    int j = right;
    int key = a[left];
    
    while(i < j)
    {
        while((i < j)&& (a[j] >= key))
        {
            j--;
        }
        if (i < j)
        {
            a[i] = a[j];
        }
        while((i < j) && a[i] <= key)
        {
            i++;
        }
        
        if (i<j)
        {
            a[j] = a[i];
        }
    }
    a[i] = key;
    
    return i;
}

void quick_sort(int a[],int left,int right)
{
    int q = 0;
    /*递归终止条件*/
    if (left >= right)
    {
        return;
    }
    
    q = partition(a,left,right);
    quick_sort(a,left,(q - 1));
    quick_sort(a,(q + 1),right);
    return;
}

void bucket_sorts(int data[], int size)
{
    int max, min, num, pos;
    struct barrel * pBarrel;
    int i, j, k;
    
    // 找到桶的大小范围
    max = min = data[0];
    for (i = 0; i < size; i++) {
        if (data[i] > max) {
            max = data[i];
        } else if (data[i] < min) {
            min = data[i];
        } else {
            //
        }
    }
    num = max - (min - 1);
    pBarrel = (struct barrel *)malloc(sizeof(struct barrel) * num);
    memset(pBarrel, 0, sizeof(struct barrel) * num);
    
    // 把数据依次装入桶中
    for (i = 0; i < size; i++) {
        k = (data[i] - (min - 1)) / 10;
        // 每个node数组中放入的数字大小相差不大于10，这也是对桶排序的要求，数字要均匀分布，不能太过集中
        (pBarrel + k)->node[(pBarrel + k)->count] = data[i];
        (pBarrel + k)->count++;
    }
    pos = 0;
    for (i = 0; i < num; i++) {
        if ((pBarrel + i)->count != 0) {
            // 对每个桶进行快速排序
            quick_sort((pBarrel+i)->node, 0, ((pBarrel+i)->count)-1);
        }
        for (j = 0; j < (pBarrel+i)->count; j++) {
            data[pos++] = (pBarrel+i)->node[j];   
        }
    }
    free(pBarrel);
}

void bucket_sort_test(void)
{
    int a[] = {78, 17, 39, 26, 72, 94, 21, 12, 23, 91};
    int size = sizeof(a) / sizeof(int);
    printf("\r\n bucket sort test ...");
    bucket_sorts(a, size);
    dump(a, size);
}
