//
//  Heap.c
//  heap
//
//  Created by Gguomingyue on 2019/4/24.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "Heap.h"

void initHeap(struct Heap * heap)
{
    for (int i = 0; i < MAX_HEAP_SIZE; i++) {
        heap->elems[i] = NULL;
    }
    heap->count = 0;
    heap->capicity = MAX_HEAP_SIZE;
}

struct Element * createElement(int data)
{
    struct Element * element = (struct Element *)malloc(sizeof(struct Element));
    if (element == NULL) {
        return NULL;
    }
    element->data = data;
    return element;
}

void fakeHeap(struct Heap * heap)
{
    int i, data[10] = {7, 4, 9, 2, 6, 8, 10, 1, 3, 5};
    initHeap(heap);
    for (i = 0; i < 10; i++) {
        heap->elems[i + 1] = createElement(data[i]);
    }
    heap->count = 10;
}

void swap(struct Heap * heap, int i, int j)
{
    struct Element * temp;
    temp = heap->elems[i];
    heap->elems[i] = heap->elems[j];
    heap->elems[j] = temp;
}

void insert(struct Heap * heap, int data)
{
    if (heap == NULL || heap->count > heap->capicity) {
        return;
    }
    struct Element * element = createElement(data);
    heap->elems[heap->count + 1] = element;
    heap->count++;
    int i = heap->count;
    // 自下而上堆化
    while (i / 2 > 0 && heap->elems[i] > heap->elems[i / 2]) {
        swap(heap, i / 2, i);
        i = i / 2;
    }
}

void removeMax(struct Heap * heap)
{
    if (heap == NULL || heap->count == 0) {
        return;
    }
    heap->elems[1] = heap->elems[heap->count];
    heap->elems[heap->count] = NULL;
    heap->count--;
    heapify(heap, 1);
}

void buildHeap(struct Heap * heap)
{
    for (int i = heap->count / 2; i >= 1; i--) {
        heapify(heap, i);
    }
    //{7, 4, 9, 2, 6, 8, 10, 1, 3, 5};
    /*
                 7
         4               9
     2       6       8      10
   1   3   5
     
     */
}

void heapify(struct Heap * heap, int index)
{
    if (heap == NULL || heap->count == 0) {
        return;
    }
    while (true) {
        int maxIndex = index;
        if ((index * 2) <= heap->count && heap->elems[index * 2]->data > heap->elems[index]->data) {
            maxIndex = index * 2;
        }
        if (((index * 2 + 1) <= heap->count) && (heap->elems[maxIndex]->data < heap->elems[index * 2 + 1]->data)) {
            maxIndex = index * 2 + 1;
        }
        if (maxIndex == index) {
            break;
        }
        swap(heap, index, maxIndex);
        index = maxIndex;
    }
}

int heapSort(struct Heap * heap)
{
    int count = heap->count;
    while (heap->count) {
        swap(heap, 1, heap->count);
        heap->count--;
        heapify(heap, 1);
    }
    return count;
}

void dumpHeap(struct Heap * heap, int index)
{
    struct Element *elem;
    int level;
    
    if (index > heap->count)
        return;
    
    elem = heap->elems[index];
    level = fls(index);
    
    dumpHeap(heap, index * 2 + 1);
    
    if (!(index % 2) && index != 1)
        printf("%*s\n", level*3, "|");
    
    printf("%*s - %05d\n", level*3, " ", elem->data);
    
    if (index % 2 && index != 1)
        printf("%*s\n", level*3, "|");
    
    dumpHeap(heap, index * 2);
}

void dump(struct Heap * heap, int count)
{
    for (int i = 1; i <= count; i++) {
        printf("[%02d]: %4d\n", i, heap->elems[i]->data);
    }
}
