//
//  Listhash.h
//  hashtable
//
//  Created by Gguomingyue on 2019/4/19.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef Listhash_h
#define Listhash_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifdef MEMORY_TEST
#include<mcheck.h>
#endif

typedef struct _hashtable_node
{
    void * key;
    void * data;
    struct _hashtable_node * next;//指向具有相同的哈希值的下一个节点
}HashTable_node;

typedef struct _hashtable
{
    HashTable_node **htables;    // 哈希桶指针数组
    int size;                    // 哈希桶容量
    int nel;                     // 总节点数
    int (*hash_value)(struct _hashtable * h, const void * key);
    int (*keycmp)(struct _hashtable * h, const void *key1,const void *key2);
    void (*hash_node_free)(HashTable_node * node);
}HashTable;

#define HASHTAB_MAX_NODES  (0xffffffff)

typedef int (*hash_key_func)(struct _hashtable * h, const void * key);;
typedef int (*keycmp_func)(struct _hashtable *h,const void *key1,const void *key2);
typedef void (*hash_node_free_func)(struct _hashtable_node *node);

HashTable * hashtable_create(int size, hash_key_func hash_value, keycmp_func keycmp, hash_node_free_func hash_node_free);
void hashtable_destory(HashTable *h);
int hashtable_insert(HashTable * h, void *key, void *data);
HashTable_node * hashtable_delete(HashTable * h, void * key);
void * hashtable_search(HashTable * h, void * key);
void hashtable_dump(HashTable *h);
unsigned int simple_hash(const char * str);
int hashtable_hvalue(HashTable *h,const void *key);
int hashtable_keycmp(HashTable *h,const void *key1,const void *key2);
void hashtable_node_free(HashTable_node * node);

struct test_node
{
    char key[80];
    char data[80];
};

/*根据当前结构体元素的地址，获取到结构体首地址*/
#define offsetof(TYPE,MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#define container(ptr,type,member) ({\
const typeof( ((type *)0)->member) *__mptr = (ptr);\
(type *) ( (char *)__mptr - offsetof(type,member));})


#endif /* Listhash_h */
