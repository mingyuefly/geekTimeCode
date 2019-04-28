//
//  array_stack.h
//  stack
//
//  Created by Gguomingyue on 2019/4/8.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef array_stack_h
#define array_stack_h

#include <stdio.h>

typedef struct _array_stack
{
    int size;
    int pos;
    int *array;
}stArrayStack;

/*
 创建并初始化顺序栈
 */
stArrayStack * arrayStack_create(int size);

/*
 销毁顺序栈
 */
void arrayStack_destroy(stArrayStack *parrStack);

/*
 出栈
 */
int arrayStack_pop(stArrayStack *parrStack);

/*
 入栈
 */
int arrayStack_push(stArrayStack *parrStack, int data);

/*
 扩容入栈
 */
int arrayStack_push_new(stArrayStack *parrStack, int data);

/*
 dump
 */
void arrayStack_dump(stArrayStack *parrStack);


#define arrayStack_size(arrayStack) (arrayStack->size)
#define arrayStack_is_empty(arrayStack) (arrayStack->pos == -1)
#define arrayStack_is_full(arrayStack)  (arrayStack->pos == (arrayStack->size-1))

#endif /* array_stack_h */
