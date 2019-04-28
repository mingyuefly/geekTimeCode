//
//  Skiplist.c
//  skiplist
//
//  Created by Gguomingyue on 2019/4/16.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "Skiplist.h"

void node_init(struct node * node)
{
    // 所有值都初始化为0
    memset(node, 0, sizeof(struct node));
}

void skip_list_init(struct skip_list * sl)
{
    node_init(&sl->head);
    sl->max_level = 0;
    sl->max_level_nodes = 0;
}

void random_init()
{
    static bool done = false;
    if (done) {
        return;
    }
    srandom((unsigned)time(NULL));
    done = true;
}

int random_level(void)
{
    int i, level = 1;
    // 初始化种子
    random_init();
    // 获取1--MAX_LEVEL之间的随机数
    for (i = 1; i < MAX_LEVEL; i++) {
        if (random() % 2 == 1) {
            level++;
        }
    }
    return level;
}

void random_level_test()
{
    printf("random level %d\n", random_level());
    printf("random level %d\n", random_level());
    printf("random level %d\n", random_level());
    printf("random level %d\n", random_level());
    printf("random level %d\n", random_level());
}

void insert(struct skip_list * sl, int val)
{
    // 生成随机索引级别
    int level = random_level();
    printf("level = %d\n", level);
    struct node *update[MAX_LEVEL];
    struct node *new, *p;
    int i;
    
    // 初始化新的node，并赋值val
    new = (struct node *)malloc(sizeof(struct node));
    if (!new) {
        return;
    }
    new->max_level = level;// 最高索引为随机生成的level
    new->val = val;
    
    // 初始化update数组
    for (int i = 0; i < MAX_LEVEL; i++) {
        update[i] = &sl->head;
    }
    
    p = &sl->head;
    for (i = level - 1; i >= 0; i--) {
        while (p->forward[i] && p->forward[i]->val < val) {
            p = p->forward[i];
        }
        // 查到索引中的位置记录并占位
        update[i] = p;
    }
    for (i = 0; i < level; i++) {
        new->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = new;
    }
    if (sl->max_level < level) {
        sl->max_level = level;
        sl->max_level_nodes = 1;
    } else if (sl->max_level == level) {
        sl->max_level_nodes++;
    }
}

struct node * find(struct skip_list * sl, int val)
{
    struct node * node = &sl->head;
    int i;
    for (i = sl->max_level - 1; i >= 0; i--) {
        printf("i[%02d]:", i);
        if (node->forward[i]) {
            printf("%4d", node->forward[i]->val);
        }
        while (node->forward[i] && node->forward[i]->val < val) {
            node = node->forward[i];
            if (node->forward[i]) {
                printf("%4d", node->forward[i]->val);
            }
        }
        printf("\n");
    }
    if (node->forward[0] && node->forward[0]->val == val) {
        return node->forward[0];
    } else {
        return NULL;
    }
    
    // struct node * node = &sl->head; node->forward[i]找到对应索引层级，并找到第一个索引
    // 查找的时候，node = node->forward[i];表示横行的索引链表，指向下一个索引
    // 如果（node->forward[i]->val < val）不成立，通过down指针指向下一层索引，通过i--后，node->forward[i]找到,一个node中的forward数组存的是down节点
    
    /*
     Level[08]:   2   6   7  |10|
     Level[07]:   2   3   6   7   |9|  10
     Level[06]:   1   2   3   4   5   6   7   |9|  10
     Level[05]:   1   2   3   4   5   6   7   |8|  9  10
     Level[04]:   1   2   3   4   5   6   7   |8|   9  10
     Level[03]:   1   2   3   4   5   6   7   |8|   9  10
     Level[02]:   1   2   3   4   5   6   7   |8|  9  10
     Level[01]:   1   2   3   4   5   6   7   |8|   9  10
     Level[00]:   1   2   3   4   5   6   7   |8|  9  10
     */
    
    /*
     Level[10]:      |3|   8
     Level[09]:      |3|   8
     Level[08]:   2  |3|   8
     Level[07]:   2  |3| |5|         |6|   8
     Level[06]:   2   3   5          |6|   8
     Level[05]:   1   2   3   5      |6|   8  10
     Level[04]:   1   2   3   4   5  |6|   8  10
     Level[03]:   1   2   3   4   5  |6|  |7|   8   9  10
     Level[02]:   1   2   3   4   5   6   |7|   8   9  10
     Level[01]:   1   2   3   4   5   6   |7|   8   9  10
     Level[00]:   1   2   3   4   5   6   |7|   8   9  10
     */
}

void skip_delete(struct skip_list * sl, int val)
{
    struct node * update[MAX_LEVEL];
    struct node * p;
    int i;
    
    p = &sl->head;
    for (i = sl->max_level; i >= 0; i--) {
        while (p->forward[i] && p->forward[i]->val < val) {
            p = p->forward[i];
        }
        update[i] = p;
    }
    if (p->forward[0] == NULL || p->forward[0]->val != val) {
        return;
    }
    if (p->forward[0]->max_level == sl->max_level) {
        sl->max_level_nodes--;
    }
    for (i = sl->max_level - 1; i >= 0; i--) {
        if (update[i]->forward[i] && update[i]->forward[i]->val == val)
            update[i]->forward[i] = update[i]->forward[i]->forward[i];
    }
    
    // fixup max_level and max_level_nodes
    if (sl->max_level_nodes == 0) {
        //sl->max_level--;
        p = &sl->head;
        // skip (max_level - 1), direct test (max_level - 2)
        // since no nodes on (max_level - 1)
        for (i = sl->max_level - 2; i >= 0; i--) {
            while (p->forward[i]) {
                sl->max_level_nodes++;
                p = p->forward[i];
            }
            
            if (sl->max_level_nodes) {
                sl->max_level = i + 1;
                break;
            } else
                sl->max_level = i;
        }
    }
}

void print_sl(struct skip_list* sl)
{
    struct node *node;
    int level;
    
    printf("%d level skip list with %d nodes on top\n",
           sl->max_level, sl->max_level_nodes);
    
    for (level = sl->max_level - 1; level >= 0; level--) {
        // 初始化node为sl的head
        node = &sl->head;
        printf("Level[%02d]:", level);
        // 找到对应的索引层级
        while (node->forward[level]) {
            printf("%4d", node->forward[level]->val);
            node = node->forward[level];
        }
        printf("\n");
    }
}


