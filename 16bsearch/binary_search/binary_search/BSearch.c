//
//  BSearch.c
//  binary_search
//
//  Created by Gguomingyue on 2019/4/15.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "BSearch.h"

int bsearch_firt(int a[], int size, int value)
{
    int low = 0, high = size - 1;
    while (low <= high) {
        int middle = low + ((high - low)>>1);
        if (a[middle] <value) {
            low = middle + 1;
        } else if (a[middle] > value) {
            high = middle - 1;
        } else {
            if (middle == 0 || a[middle - 1] != value) {
                return middle;
            } else {
                high = middle - 1;
            }
        }
    }
    return -1;
}

int bsearch_last(int a[], int size, int value)
{
    int low = 0, high = size - 1;
    while (low <= high) {
        int middle = low + ((high - low)>>1);
        if (a[middle] <value) {
            low = middle + 1;
        } else if (a[middle] > value) {
            high = middle - 1;
        } else {
            if (middle == 0 || a[middle + 1] != value) {
                return middle;
            } else {
                low = middle + 1;
            }
        }
    }
    return -1;
}

int bsearch_first_bigger(int a[], int size, int value)
{
    int low = 0, high = size - 1;
    while (low <= high) {
        int middle = low + ((high - low)>>1);
        if (a[middle] < value) {
            if (a[middle + 1] >= value) {
                // 说明是middle右边第一个大于等于value的值
                return middle + 1;
            } else {
                low = middle + 1;
            }
        } else if (a[middle] > value) {
            high = middle - 1;
        } else {
            if (middle == 0 || a[middle - 1] < value) {
                // = 0直接返回
                // !=0说明左边的值小于value，而middle位等于value
                return middle;
            } else {
                high = middle - 1;
            }
        }
    }
    return -1;
}

int bsearch_last_smaller(int a[], int size, int value)
{
    int low = 0, high = size - 1;
    while (low <= high) {
        int middle = low + ((high - low)>>1);
        if (a[middle] < value) {
            low = middle + 1;
        } else if (a[middle] > value) {
            if (a[middle-1] <= value) {
                // (middle-1)位置<=value，而右边的值大于value，说明(middle-1)是最后一个小于等于value的值
                return middle - 1;
            } else {
                high = middle - 1;
            }
        } else {
            if (middle == 0 || a[middle + 1] > value) {
                // =0直接返回
                // !=0middle右边的值大于value，说明middle是最后一个小于等于value的值
                return middle;
            } else {
                high = middle - 1;
            }
        }
    }
    return -1;
}
