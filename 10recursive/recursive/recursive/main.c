//
//  main.c
//  recursive
//
//  Created by Gguomingyue on 2019/4/10.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include "One_two_steps.h"

int stepsFun(int n)
{
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    return stepsFun(n-1)+stepsFun(n-2);
}

int main(int argc, const char * argv[]) {
    
    int steps = stepsFun(6);
    printf("steps = %d\n", steps);
    
    printf("\r\nnum%d ,%d",5,climbStaris(5));
    printf("\r\nnum%d ,%d",6,climbStaris(6));
    printf("\r\nnum%d ,%d",7,climbStaris(7));
    
    return 0;
}
