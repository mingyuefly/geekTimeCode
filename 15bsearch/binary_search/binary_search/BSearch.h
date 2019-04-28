//
//  BSearch.h
//  binary_search
//
//  Created by Gguomingyue on 2019/4/15.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef BSearch_h
#define BSearch_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int (*funSelect)(int a[], int size, int value);

int bSearch_i(int a[], int size, int value);
int bSearch_r(int a[], int size, int value);
void bSearch_test(funSelect binary_search);

#endif /* BSearch_h */
