//
//  sorts.h
//  sorts
//
//  Created by Gguomingyue on 2019/4/12.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef sorts_h
#define sorts_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>


void dump(int a[],int size);

/*
 计数排序
 */
void count_sorts(int a[], int size);
void count_sorts_test(void);

/*
 基数排序
 */
void radix_sorts(int a[], int size, int num_count);
void radix_sorts_test(void);

/*
 桶排序
 */
void bucket_sorts(int data[], int size);
void bucket_sort_test(void);


#endif /* sorts_h */
