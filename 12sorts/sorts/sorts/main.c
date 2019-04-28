//
//  main.c
//  sorts
//
//  Created by Gguomingyue on 2019/4/12.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    //int a[10] = {9,11,4,15,16,3,20,44,5,10};
    //int a[10] = {44,20,16,15,11,10,9,5,4,3};
    //int a[10] = {100,301,405,150,111,109,999,521,413,312};
    //int a[10] = {100,301,413,150,111,109,999,521,413,312};
    int a[10] = {3, 4, 5, 9, 10, 11, 15, 16, 20, 44};
    
    //dump(a, 10);
    //printf("sorts begin\n");
    
    //bubble_sorts(a, 10);
    //insert_sorts(a, 10);
    //select_sorts(a, 10);
    //merge_sorts(a, 10);
    quick_sorts(a, 10);
    
    dump(a, 10);
    
    return 0;
}
