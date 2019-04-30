//
//  main.c
//  bitmap
//
//  Created by Gmingyue on 2019/4/30.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include "Bitmap.h"

int main(int argc, const char * argv[]) {
    
    int nbits = 10000;
    Bitmap bitmap;
    initBitmap(&bitmap, nbits);
    int bytes[10000] = {0};
    (&bitmap)->bytes = bytes;
    
    int k;
    while (1) {
        printf("请输入k:\n");
        scanf("%d", &k);
        if (k > nbits) {
            break;
        }
        setValue(&bitmap, k);
    }
    
    int m;
    while (1) {
        printf("请输入m:\n");
        scanf("%d", &m);
        if (m == 99999) {
            break;
        }
        if (getValue(&bitmap, m)) {
            printf("bitmap中存在%d\n", m);
        } else {
            printf("bitmap中不存在%d\n", m);
        }
    }
    
    int n;
    while (1) {
        printf("请输入n:\n");
        scanf("%d", &n);
        if (n > nbits) {
            break;
        }
        setValue(&bitmap, n);
    }

    int p;
    while (1) {
        printf("请输入p:\n");
        scanf("%d", &p);
        if (p == 99999) {
            break;
        }
        if (getValue(&bitmap, p)) {
            printf("bitmap中存在%d\n", p);
        } else {
            printf("bitmap中不存在%d\n", p);
        }
    }

    freeBitmap(&bitmap);
    return 0;
}
