//
//  Bitmap.c
//  bitmap
//
//  Created by Gmingyue on 2019/4/30.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "Bitmap.h"

Bitmap * initBitmap(Bitmap * bitmap, int nbits)
{
    bitmap = (Bitmap *)malloc(sizeof(Bitmap));
    if (bitmap == NULL) {
        return NULL;
    }
    bitmap->nbits = nbits;
    return bitmap;
}

void setValue(Bitmap * bitmap, int k)
{
    if (k > bitmap->nbits) {
        return;
    }
    int size = sizeof(int) * 8;
    int byteIndex = k / size;
    int bitIndex = k % size;
    bitmap->bytes[byteIndex] |= (1<<bitIndex);
}

bool getValue(Bitmap * bitmap, int k)
{
    if (k > bitmap->nbits) {
        return false;
    }
    int size = sizeof(int) * 8;
    int byteIndex = k / size;
    int bitIndex = k % size;
    return (bitmap->bytes[byteIndex] & (1 << bitIndex)) != 0;
}

void freeBitmap(Bitmap * bitmap)
{
    bitmap->bytes = NULL;
}
