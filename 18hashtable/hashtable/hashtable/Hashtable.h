//
//  Hashtable.h
//  hashtable
//
//  Created by Gguomingyue on 2019/4/18.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef Hashtable_h
#define Hashtable_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


#define HASH_SHIFT 4
#define HASH_SIZE (1<<HASH_SHIFT)
#define HASH_MASK (HASH_SIZE - 1)

struct hash_table {
    unsigned int used;
    unsigned long entry[HASH_SIZE];
};

void hash_table_reset(struct hash_table * table);
unsigned int hash_function(unsigned long value);
void hash_function_test(void);
unsigned int hash_next_probe(unsigned int prev_key);
void hash_table_next_probe_test(void);
void hash_table_add(struct hash_table * table, unsigned long value);
void hash_table_add_test(void);
bool hash_table_find(struct hash_table * table, unsigned long value);
unsigned int hash_table_slot(struct hash_table * table, unsigned long value);
void hash_table_delete(struct hash_table * table, unsigned long value);
void hash_table_delete_test1(void);
void hash_table_delete_test2(void);
void hash_table_dump(struct hash_table * table);






#endif /* Hashtable_h */
