//
//  main.c
//  binary_search
//
//  Created by Gguomingyue on 2019/4/15.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include "BSearch.h"

int main(int argc, const char * argv[]) {
    
    int a[10] = {5,6,6,9,10,11,11,11,33,33};
    int data = 0;
    int i = 0;
    int res = 0;
    
    printf("\r\n");
    for(i = 0; i < 10 ; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\r\n");
    printf("\r\n输入一个整数");
    scanf("%d", &data);
    res = bsearch_firt(a, 10, data);
    printf("第一个等于data[%d]，下标是%d",data,res);
    
    printf("\r\n输入一个整数");
    scanf("%d",&data);
    res = bsearch_last(a, 10, data);
    printf("最后一个等于data[%d]，下标是%d",data,res);
    
    printf("\r\n输入一个整数");
    scanf("%d",&data);
    res = bsearch_first_bigger(a, 10, data);
    printf("第一个大于等于data[%d]，下标是%d",data,res);
    
    printf("\r\n输入一个整数");
    scanf("%d",&data);
    res = bsearch_last_smaller(a, 10, data);
    printf("最后一个小于等于data[%d]，下标是%d",data,res);
    
    return 0;
}
