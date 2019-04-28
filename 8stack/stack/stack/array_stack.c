//
//  array_stack.c
//  stack
//
//  Created by Gguomingyue on 2019/4/8.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "array_stack.h"
#include <stdlib.h>
#include <string.h>

/*
 创建并初始化顺序栈
 */
stArrayStack * arrayStack_create(int size)
{
    stArrayStack *parrStack = NULL;
    parrStack = (stArrayStack *)malloc(sizeof(stArrayStack));
    if (parrStack == NULL) {
        return NULL;
    }
    parrStack->size = size;
    parrStack->pos = -1;
    parrStack->array = (int *)malloc(sizeof(int) * size);
    if (parrStack->array == NULL) {
        free(parrStack);
        return NULL;
    }
    return parrStack;
}

/*
 销毁顺序栈
 */
void arrayStack_destroy(stArrayStack *parrStack)
{
    if (parrStack == NULL) {
        return;
    }
    if (parrStack->array != NULL) {
        free(parrStack->array);
    }
    free(parrStack);
    return;
}

/*
 出栈
 */
int arrayStack_pop(stArrayStack *parrStack)
{
    int data = 0;
    if (arrayStack_is_empty(parrStack)) {
        return -1;
    }
    data = parrStack->array[parrStack->pos];
    parrStack->pos--;
    return 0;
}

/*
 入栈
 */
int arrayStack_push(stArrayStack *parrStack, int data)
{
    if (arrayStack_is_full(parrStack)) {
        return -1;
    }
    parrStack->pos++;
    parrStack->array[parrStack->pos] = data;
    return 0;
}

/*
 扩容入栈
 */
int arrayStack_push_new(stArrayStack *parrStack, int data)
{
    int *ptmp = NULL;
    // 如果栈不满直接插入
    if (!arrayStack_is_full(parrStack)) {
        return arrayStack_push(parrStack, data);
    }
    
    // 如果栈已满，申请内存
    ptmp = (int *)malloc(sizeof(int) * parrStack->size * 2);
    if (ptmp == NULL) {
        return -1;
    }
    
    memcpy(ptmp, parrStack->array, parrStack->size * sizeof(int));
    free(parrStack->array);
    parrStack->array = ptmp;
    parrStack->size = 2 * parrStack->size;
    parrStack->pos++;
    parrStack->array[parrStack->pos] = data;
    return 0;
}

/*
 dump
 */
void arrayStack_dump(stArrayStack *parrStack)
{
    int i = 0;
    if (arrayStack_is_empty(parrStack)) {
        printf("\r\n arrayStack is empty.");
        return;
    }
    printf("\r\narrayStack size = %d,pos= %d,",
           parrStack->size,parrStack->pos);
    for(i = 0; i <= parrStack->pos; i++)
    {
        printf("\r\narry[%d] = %d",i,parrStack->array[i]);
    }
}
