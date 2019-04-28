//
//  main.c
//  arrayQueue
//
//  Created by Gguomingyue on 2019/4/10.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include "ArrayQueue.h"

int main(int argc, const char * argv[]) {
    
    int i = 0;
    int ret = 0;
    int data = 0;
    array_queue * queue = NULL;
    
    queue = array_queue_create(4);
    if (queue ==  NULL) {
        printf("\r\n queue is create failed.");
        return 0;
    }
    
    ret = array_queue_dequeue(queue, &data);
    if (ret != 0) {
        printf("\r\n queue %d dequeue failed.",ret);
    }
    
    for (i = 0; i < 5; i++) {
        ret = array_queue_enqueue(queue, i);
        if (ret != 0) {
            printf("\r\n queue %d enqueue failed", i);
        }
    }
    
    array_queue_dump(queue);
    ret = array_queue_dequeue(queue, &data);
    if (ret != 0) {
        printf("\r\n queue %d dequeue failed.",i);
    }
    printf("\r\n queue %d dequue.",data);
    array_queue_dump(queue);
    data = 5;
    printf("\r\n queue %d enqueue.",data);
    ret = array_queue_enqueue(queue,data);
    if (ret != 0)
    {
        printf("\r\n queue %d enqueue failed.",data);
    }
    array_queue_dump(queue);
    ret = array_queue_dequeue(queue, &data);
    printf("\r\n queue %d dequue.",data);
    if (ret != 0) {
        printf("\r\n queue %d dequeue failed.",data);
    }
    array_queue_dump(queue);
    array_queue_destroy(queue);
    
    return 0;
}
