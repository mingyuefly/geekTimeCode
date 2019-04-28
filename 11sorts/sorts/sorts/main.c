//
//  main.c
//  sorts
//
//  Created by Gguomingyue on 2019/4/10.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include "Sorts.h"

int main(int argc, const char * argv[]) {
    
    int a[10] = {9,11,4,15,16,3,20,44,5,10};
    dump(a, 10);
    printf("sorts begin\n");
    
    //bubble_sorts(a, 10);
    //insert_sorts(a, 10);
    //select_sorts(a, 10);
    merge_sorts(a, 10);
    
    dump(a, 10);
    
    return 0;
}
