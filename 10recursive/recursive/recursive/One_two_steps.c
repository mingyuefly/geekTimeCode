//
//  One_two_steps.c
//  recursive
//
//  Created by Gguomingyue on 2019/4/10.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "One_two_steps.h"

int helper(int n ,int *value)
{
    if (value[n] != 0) {
        return value[n];
    }
    value[n] = helper(n-1, value) + helper(n-2, value);
    return value[n];
}

int climbStaris(int n)
{
    int * value = NULL;
    int res = 0;
    
    value = (int *)malloc(sizeof(int) * (n + 1));
    if (value == NULL) {
        return -1;
    }
    
    memset(value, 0, sizeof(int) * (n+1));
    value[0] = 0;
    value[1] = 1;
    value[2] = 2;
    res = helper(n, value);
    free(value);
    
    return res;
}
