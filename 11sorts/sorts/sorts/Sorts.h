//
//  Sorts.h
//  sorts
//
//  Created by Gguomingyue on 2019/4/11.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef Sorts_h
#define Sorts_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define SWAP(a,b) \
do{\
(a) ^= (b);\
(b) ^= (a);\
(a) ^= (b);\
}while(0)

/*
 冒泡排序
 */
void bubble_sorts(int a[], int size);

/*
 插入排序
 */
void insert_sorts(int a[], int size);

/*
 选择排序
 */
void select_sorts(int a[], int size);

/*
 归并排序
 */
void merge_sorts(int a[], int size);
void merge_sorts_content(int a[], int begin, int end);
void merge_sentry(int a[], int begin, int middle, int end);

/*
 快速排序
 */

/*
 dump
 */
void dump(int a[], int size);




#endif /* Sorts_h */
