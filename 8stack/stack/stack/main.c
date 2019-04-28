//
//  main.c
//  stack
//
//  Created by Gguomingyue on 2019/4/8.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include "array_stack.h"

int main(int argc, const char * argv[]) {
    
    int i = 0;
    int ret = 0;
    stArrayStack * parrStack = NULL;
    printf("\r\n create  size = 4 arrayStack.");
    parrStack = arrayStack_create(4);
    if (parrStack == NULL) {
        printf("\r\n create size = 4 arrayStack faided.");
        return 0;
    }
    arrayStack_dump(parrStack);
    for (int i = 0; i < 5; i++) {
        ret = arrayStack_push(parrStack, i);
        if (ret != 0) {
            printf("\r\n push size = %d arrayStack faided.",i);
        }
    }
    arrayStack_dump(parrStack);
    
    ret = arrayStack_push_new(parrStack, 4);
    if (ret != 0) {
        printf("\r\n push size = %d arrayStack faided.",4);
    }
    arrayStack_dump(parrStack);
    arrayStack_destroy(parrStack);
    
    return 0;
}
