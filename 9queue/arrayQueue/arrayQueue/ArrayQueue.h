//
//  ArrayQueue.h
//  arrayQueue
//
//  Created by Gguomingyue on 2019/4/10.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef ArrayQueue_h
#define ArrayQueue_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _array_queue
{
    int size;       // 队列大小
    int num;        // 当前存储数据大小
    int head;       // 队列的头
    int tail;       // 队列的尾
    int *array;     // 数据存储区
}array_queue;

/*
创建队列
*/
array_queue * array_queue_create(int size);

/*
 销毁队列
 */
void array_queue_destroy(array_queue * queue);

/*
 入队
 */
int array_queue_enqueue(array_queue * queue, int data);

/*
 出队
 */
int array_queue_dequeue(array_queue * queue, int * data);

void array_queue_dump(array_queue * queue);


#define array_queue_is_empty(array_queue) (array_queue->num == 0)
#define array_queue_is_full(array_queue)  ((array_queue->num) == (array_queue->size))


#endif /* ArrayQueue_h */
