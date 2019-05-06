//
//  main.c
//  heap
//
//  Created by gomeguomingyue on 2019/4/24.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include "Heap.h"

int main(int argc, const char * argv[]) {
    
    struct Heap heap;
    int elements;
    
    fakeHeap(&heap);
    dumpHeap(&heap, 1);
    dump(&heap, (&heap)->count);
    
    printf("After Heapify:\n");
    buildHeap(&heap);
    dumpHeap(&heap, 1);
    dump(&heap, (&heap)->count);
    
    printf("After Heap insert 12:\n");
    insert(&heap, 12);
    dumpHeap(&heap, 1);
    dump(&heap, (&heap)->count);
    
    printf("After Heap insert 11:\n");
    insert(&heap, 11);
    dumpHeap(&heap, 1);
    dump(&heap, (&heap)->count);
    
    printf("After Heap removeMax:\n");
    removeMax(&heap);
    dumpHeap(&heap, 1);
    dump(&heap, (&heap)->count);
    
    printf("After Heap sort:\n");
    elements = heapSort(&heap);
    dump(&heap, elements);
    
    // 重新堆化
    (&heap)->count = elements;
    buildHeap(&heap);
    dumpHeap(&heap, 1);
    dump(&heap, (&heap)->count);
    
    printf("After Heap sort:\n");
    elements = heapSort(&heap);
    dump(&heap, elements);
    
    //{7, 4, 9, 2, 6, 8, 10, 1, 3, 5};
    /*
               7
        4              9
    2       6      8      10
  1   3   5
     
     */
    return 0;
}
