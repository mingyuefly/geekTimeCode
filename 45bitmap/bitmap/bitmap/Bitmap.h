//
//  Bitmap.h
//  bitmap
//
//  Created by Gmingyue on 2019/4/30.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef Bitmap_h
#define Bitmap_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct _bitmap{
    int nbits;
    int *bytes;
}Bitmap;

Bitmap * initBitmap(Bitmap * bitmap, int nbits);
void setValue(Bitmap * bitmap, int k);
bool getValue(Bitmap * bitmap, int k);
void freeBitmap(Bitmap * bitmap);






#endif /* Bitmap_h */
