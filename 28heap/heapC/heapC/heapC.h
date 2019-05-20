//
//  heap.h
//  heapC
//
//  Created by Gguomingyue on 2019/5/18.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef heap_h
#define heap_h

#include <stdio.h>

extern int h[101];
extern int n;

/*
 交换函数
 */
void swapC(int x, int y);

/*
 向下调整
 */
void siftdownC(int i);

/*
 向上调整
 */
void siftupC(int i);

/*
 删除最大元素
 */
int deleteMaxC(void);

/*
 建堆
 */
void createC(void);

/*
 堆排序
 */
void heapSortC(void);

// 实现优先队列
/*
 插入
 */
void insert(int x);

/*
 出队列
 */
int outQueue(void);

/*
 更新
 */
void updateQueue(int index, int x);



#endif /* heap_h */
