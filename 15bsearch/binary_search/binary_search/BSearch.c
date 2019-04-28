//
//  BSearch.c
//  binary_search
//
//  Created by Gguomingyue on 2019/4/15.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "BSearch.h"

int bSearch_i(int a[], int size, int value)
{
    int low = 0, high = size - 1;
    
    while (low <= high) {
        int middle = low + ((high - low)>>1);
        if (a[middle] == value) {
            return middle;
        } else if (a[middle] < value) {
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }
    return -1;
}

int bSearch_r(int a[], int size, int value)
{
    int middle = size>>1;
    int idx;
    
    if (a[middle] == value) {
        return middle;
    }
    if (!middle) {
        return -1;
    }
    
    if (a[middle] < value) {
        idx = bSearch_r(a+middle+1, size - (middle - 1), value);
        if (idx != -1) {
            idx += middle + 1;
        }
    } else {
        idx = bSearch_r(a, middle, value);
    }
    
    return idx;
}

void bSearch_test(funSelect binary_search)
{
    int arr[10] = {1, 4, 5, 9, 12, 19, 21, 28, 31, 36};
    int idx;
    idx = binary_search(arr, 10, 12);
    if (idx != -1)
        printf("find 12 at %d\n", idx);
    else
        printf("12 not in arr \n");
    
    idx = binary_search(arr, 10, 28);
    if (idx != -1)
        printf("find 28 at %d\n", idx);
    else
        printf("28 not in arr \n");
    idx = binary_search(arr, 10, 13);
    if (idx != -1)
        printf("find 13 at %d\n", idx);
    else
        printf("13 not in arr \n");
    
    idx = binary_search(arr, 10, 1);
    if (idx != -1)
        printf("find 1 at %d\n", idx);
    else
        printf("1 not in arr \n");
    
    idx = binary_search(arr, 10, 36);
    if (idx != -1)
        printf("find 36 at %d\n", idx);
    else
        printf("36 not in arr \n");
    
    idx = binary_search(arr, 10, 31);
    if (idx != -1)
        printf("find 31 at %d\n", idx);
    else
        printf("31 not in arr \n");
}
