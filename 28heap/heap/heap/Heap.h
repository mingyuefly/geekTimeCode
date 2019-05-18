//
//  Heap.h
//  heap
//
//  Created by Gguomingyue on 2019/4/24.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef Heap_h
#define Heap_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_HEAP_SIZE (1 << 8)

struct Element {
    int data;
};

struct Heap {
    int capicity;
    int count;
    struct Element * elems[MAX_HEAP_SIZE];
};

void initHeap(struct Heap * heap);
struct Element * createElement(int data);
void fakeHeap(struct Heap * heap);
void swap(struct Heap * heap, int i, int j);
void insert(struct Heap * heap, int data);
void removeMax(struct Heap * heap);
void buildHeap(struct Heap * heap);
void heapify(struct Heap * heap, int index);
int heapSort(struct Heap * heap);
void dumpHeap(struct Heap * heap, int index);
void dump(struct Heap * heap, int count);



#endif /* Heap_h */
