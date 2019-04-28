//
//  Hashtable.c
//  hashtable
//
//  Created by Gguomingyue on 2019/4/18.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "Hashtable.h"

void hash_table_reset(struct hash_table * table)
{
    int i;
    table->used = 0;
    for (i = 0; i < HASH_SIZE; i++) {
        table->entry[i] = ~0;
    }
}

unsigned int hash_function(unsigned long value)
{
    return value & HASH_MASK;
}

void hash_function_test(void)
{
    int i;
    srandom((unsigned)time(NULL));
    for (i = 0; i < 10; i++) {
        unsigned long value = random();
        printf("%10lu -> %2u\n", value, hash_function(value));
    }
}

unsigned int hash_next_probe(unsigned int prev_key)
{
    return (prev_key + 1) & HASH_MASK;//使用逻辑与的位计算符，如果prev_key < HASH_SIZE, return (prev_key + 1)，如果prev_key == HASH_SIZE，则返回0。（10000 & 1111 = 0）
}

void hash_table_next_probe_test()
{
    int i;
    unsigned int key1, key2;
    key1 = 0;
    for (i = 0; i < HASH_SIZE; i++) {
        key2 = hash_next_probe(key1);
        printf("%2u -> %2u\n", key1, key2);
        key1 = key2;
    }
}

void hash_table_add(struct hash_table * table, unsigned long value)
{
    int key = hash_function(value);
    if (table->used >= HASH_SIZE) {
        return;
    }
    while (table->entry[key] != ~0) {
        key = hash_next_probe(key);
    }
    table->entry[key] = value;
    table->used++;
}

void hash_table_add_test(void)
{
    struct hash_table table;
    hash_table_reset(&table);
    hash_table_add(&table, 87645);
    printf("Table has%s 87645\n",
           hash_table_find(&table, 87645) ? "":"n't");
    printf("Table has%s 87647\n",
           hash_table_find(&table, 87647) ? "":"n't");
}

bool hash_table_find(struct hash_table * table, unsigned long value)
{
    return table->entry[hash_table_slot(table, value)] == value;
}

unsigned int hash_table_slot(struct hash_table * table, unsigned long value)
{
    int i;
    unsigned int key = hash_function(value);
    for (i = 0; i < HASH_SIZE; i++) {
        if (table->entry[key] == value || table->entry[key] == ~0) {
            break;
        }
        key = hash_next_probe(key);
    }
    return key;
}

void hash_table_delete(struct hash_table * table, unsigned long value)
{
    if (!hash_table_find(table, value)) {
        return;
    }
    unsigned int i, j, k;
    i = j = hash_table_slot(table, value);
    
    while (true) {
        // 刚进入将删除的位置置空，再次运行到这里把j已经搬移到i位置的置空
        table->entry[i] = ~0;
        do {
            // do_while确保第一轮执行，如果table->entry[j] == ~0则说明i的下一个位置为空，不影响使用线性探针查询
            j = hash_next_probe(j);
            if (table->entry[j] == ~0) {
                return;
            }
            k = hash_function(table->entry[j]);
            // 在循环内i位置不变，相当于i为一个岗哨，当(i < k && k <= j)条件不满足时，就跳出循环把j位搬到i位，然后将j位置空,而当条件满足时就意味着j位的hash值大于i，就继续往后查找
        } while ((i <= j) ? (i < k && k <= j) : (i < k || k <= j));
        
        table->entry[i] = table->entry[j];
        i = j;
    }
    //table->used++;
}

void hash_table_delete_test1()
{
    struct hash_table table;
    
    hash_table_reset(&table);
    hash_table_add(&table, 0x1ff0);
    hash_table_add(&table, 0x2ff0);
    hash_table_add(&table, 0x3ff0);
    hash_table_dump(&table);
    
    printf("=== Remove 0x1ff0\n");
    hash_table_delete(&table, 0x1ff0);
    hash_table_dump(&table);
}

void hash_table_delete_test2()
{
    struct hash_table table;
    
    hash_table_reset(&table);
    hash_table_add(&table, 0x1ff0);
    hash_table_add(&table, 0x1ff1);
    hash_table_add(&table, 0x1ff2);
    //hash_table_add(&table, 0x1ff2);
    hash_table_add(&table, 0x2ff0);
    hash_table_dump(&table);
    
    printf("=== Remove 0x1ff0\n");
    hash_table_delete(&table, 0x1ff0);
    //hash_table_delete(&table, 0x1ff1);
    hash_table_dump(&table);
}

void hash_table_dump(struct hash_table * table)
{
    int i;
    for (i = 0; i < HASH_SIZE; i++) {
        if (table->entry[i] == ~0) {
            printf("%2u:       nil \n", i);
        } else {
            printf("%2u:%10lu -> %2u\n",
                   i, table->entry[i],
                   hash_function(table->entry[i]));
        }
    }
}
