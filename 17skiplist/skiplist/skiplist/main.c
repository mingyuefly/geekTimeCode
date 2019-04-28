//
//  main.c
//  skiplist
//
//  Created by Gguomingyue on 2019/4/16.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include "Skiplist.h"

int main(int argc, const char * argv[]) {
    
    //random_level_test();
    struct skip_list sl;
    struct node * node = NULL;
    int i;
    
    // 初始化跳表
    skip_list_init(&sl);
    print_sl(&sl);
    
    //for (i = 0; i < 10; i++) {
    for (i = 1; i < 22; i = i + 2) {
        insert(&sl, i);
        //print_sl(&sl);
    }
    print_sl(&sl);
    
    node = find(&sl, 8);
    if (node)
        printf("find 8 in sl %d\n", node->val);
    else
        printf("8 not in sl\n");
    node = find(&sl, 6);
    if (node)
        printf("find 6 in sl %d\n", node->val);
    else
        printf("6 not in sl\n");
    node = find(&sl, 9);
    if (node)
        printf("find 9 in sl %d\n", node->val);
    else
        printf("9 not in sl\n");
    
    insert(&sl, 8);
    print_sl(&sl);
    
    node = find(&sl, 8);
    if (node)
        printf("find 8 in sl %d\n", node->val);
    else
        printf("8 not in sl\n");
    
    //for (i = 0; i < 10; i++) {
    for (i = 1; i < 11; i++) {
        skip_delete(&sl, i);
        //print_sl(&sl);
    }
    
    return 0;
}
