//
//  BSearch.h
//  binary_search
//
//  Created by Gguomingyue on 2019/4/15.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef BSearch_h
#define BSearch_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*二分查找算法的变形问题
 *1、查找第一个等于给定数值的元素
 *2、查找最后一个等于给定数值的元素
 *3、查找第一个大于等于给定数值的元素
 *4、查找最后一个小于等于给定数值的元素
 * */

int bsearch_firt(int a[], int size, int value);
int bsearch_last(int a[], int size, int value);
int bsearch_first_bigger(int a[], int size, int value);
int bsearch_last_smaller(int a[], int size, int value);





#endif /* BSearch_h */
