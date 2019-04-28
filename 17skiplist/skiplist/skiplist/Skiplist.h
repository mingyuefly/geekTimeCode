//
//  Skiplist.h
//  skiplist
//
//  Created by Gguomingyue on 2019/4/16.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef Skiplist_h
#define Skiplist_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

/*
 Level[10]:   4
 Level[09]:   1   2   4   7
 Level[08]:   1   2   4   7   9
 Level[07]:   1   2   4   7   9
 Level[06]:   1   2   3   4   7   8   9  10
 Level[05]:   1   2   3   4   6   7   8   9  10
 Level[04]:   1   2   3   4   5   6   7   8   9  10
 Level[03]:   1   2   3   4   5   6   7   8   9  10
 Level[02]:   1   2   3   4   5   6   7   8   9  10
 Level[01]:   1   2   3   4   5   6   7   8   9  10
 Level[00]:   1   2   3   4   5   6   7   8   9  10
*/

// 最大索引级别
#define MAX_LEVEL 15

struct node {
    int val;
    int max_level;
    struct node * forward[MAX_LEVEL];
};

// head中max_level为索引层级，max_level_nodes为最高层级节点数，head为node节点
// 其中head处node节点包含的forward数组在max_level为NULL，在下标0处以及下标0处node的forward数组在下标0处一直循环下去存储的是原始链表
//  head处node节点包含的forward数组在max_level为NULL，在下标非0处以及下标非0处node的forward数组在下标非0处一直循环下去存储的是每一层的索引也就是每一横行元素
//  head处node节点包含的forward数组在max_level为NULL，第一个元素node的val对应第一竖行的元素
//  head处node节点包含的forward数组在max_level为NULL，每一个元素node的forward数组的第n个元素的val，一次对应第二竖行的第n个元素，依次类推

struct skip_list {
    struct node head;
    int max_level;
    int max_level_nodes;
};

void node_init(struct node * node);
void skip_list_init(struct skip_list * sl);
void random_init(void);
int random_level(void);
void random_level_test(void);
void insert(struct skip_list * sl, int val);
struct node * find(struct skip_list * sl, int val);
void skip_delete(struct skip_list * sl, int val);
void print_sl(struct skip_list* sl);


#endif /* Skiplist_h */
