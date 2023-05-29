//
//  main.cpp
//  linkedList
//
//  Created by Gguomingyue on 2019/3/5.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include "Dlist.h"

int main(void) {
    
    stDlistHead dlist = {0};
    stDlistNode * pNode = NULL;
    
    dlist_init(&dlist);
    printf("\r\n inset 1,2,3");
    dlist_insert_head(&dlist, NULL, 1);
    dlist_insert_head(&dlist, NULL, 2);
    dlist_insert_head(&dlist, NULL, 3);
    
    dlist_dump(&dlist);
    
    pNode = dlist_remove_tail(&dlist);
    if (pNode != NULL) {
        printf("\r\n remove %d",pNode->data);
    }
    dlist_insert_head(&dlist, NULL, 4);
    dlist_dump(&dlist);
    
    Lru_dlist(&dlist, 5);
    dlist_dump(&dlist);
    Lru_dlist(&dlist, 6);
    dlist_dump(&dlist);
    Lru_dlist(&dlist, 7);
    dlist_dump(&dlist);
    Lru_dlist(&dlist, 8);
    dlist_dump(&dlist);
    Lru_dlist(&dlist, 6);
    dlist_dump(&dlist);
    
    while(dlist.size > 0)
    {
        pNode = dlist_remove_tail(&dlist);
        if(pNode != NULL)
        {
            printf("\r\n remove %d",pNode->data);
            free (pNode);
        }
    }
    
    printf("\n");
    return 0;
}
