//
//  Listhash.c
//  hashtable
//
//  Created by Gguomingyue on 2019/4/19.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "Listhash.h"

HashTable * hashtable_create(int size, hash_key_func hash_value, keycmp_func keycmp, hash_node_free_func hash_node_free)
{
    HashTable * h = NULL;
    if (size < 0 || hash_value == NULL || keycmp == NULL) {
        return NULL;
    }
    h = (HashTable *)malloc(sizeof(HashTable));
    if (h == NULL) {
        return NULL;
    }
    h->htables = (HashTable_node **)malloc(sizeof(HashTable_node *) * size);
    if (h->htables == NULL) {
        return NULL;
    }
    h->size = size;
    h->nel = 0;
    h->hash_value = hash_value;
    h->keycmp = keycmp;
    h->hash_node_free = hash_node_free;
    
    for (int i = 0; i < size; i++) {
        h->htables[i] = NULL;
    }
    
    return h;
}

void hashtable_destory(HashTable *h)
{
    int i = 0;
    HashTable_node * cur = NULL;
    HashTable_node * tmp = NULL;
    
    if (h == NULL) {
        return;
    }
    
    for (i = 0; i < h->size; i++) {
        cur = h->htables[i];
        while (cur != NULL) {
            tmp = cur;
            cur = cur->next;
            h->hash_node_free(tmp);
        }
        h->htables[i] = NULL;
    }
    free(h->htables);
    free(h);
}

int hashtable_insert(HashTable * h, void *key, void *data)
{
    if (h == NULL || key == NULL || data == NULL) {
        return 1;
    }
    unsigned int hvalue = 0;
    HashTable_node * cur = NULL;
    HashTable_node * prev = NULL;
    HashTable_node * newNode = NULL;
    
    hvalue = h->hash_value(h, key);
    cur = h->htables[hvalue];
    while (cur != NULL && (h->keycmp(h, key, cur->key) > 0)) {
        prev = cur;
        cur = cur->next;
    }
    if (cur != NULL && (h->keycmp(h,key,cur->key) == 0)) {
        return 2;
    }
    newNode = (HashTable_node *)malloc(sizeof(HashTable_node));
    if (newNode == NULL) {
        return 3;
    }
    newNode->key = key;
    newNode->data = data;
    if (prev == NULL) {
        newNode->next = h->htables[hvalue];
        h->htables[hvalue] = newNode;
    } else {
        newNode->next = prev->next;
        prev->next = newNode;
    }
    h->nel++;
    
    return 0;
}

HashTable_node * hashtable_delete(HashTable * h, void * key)
{
    if (h == NULL || key == NULL) {
        return NULL;
    }
    unsigned int hvalue = 0;
    HashTable_node * cur = NULL;
    HashTable_node * prev = NULL;
    hvalue = h->hash_value(h, key);
    cur = h->htables[hvalue];
    while (cur != NULL && (h->keycmp(h, key, cur->key) >= 0)) {
        if (h->keycmp(h, key, cur->key) == 0) {
            if (prev == NULL) {
                h->htables[hvalue] = cur->next;
            } else {
                prev->next = cur->next;
            }
            return cur;
        }
        prev = cur;
        cur = cur->next;
    }
    
    return NULL;
}

void * hashtable_search(HashTable * h, void * key)
{
    int hvalue = 0;
    HashTable_node * cur = NULL;
    
    if (h == NULL || key == NULL) {
        return NULL;
    }
    hvalue = h->hash_value(h, key);
    cur = h->htables[hvalue];
    while (cur != NULL && (h->keycmp(h, key, cur->key) >= 0)) {
        if (h->keycmp(h, key, cur->key) == 0) {
            return cur->data;
        }
        cur = cur->next;
    }
    
    return NULL;
}

void hashtable_dump(HashTable *h)
{
    int i = 0;
    HashTable_node * cur = NULL;
    
    if (h == NULL)
    {
        return ;
    }
    
    printf("\r\n----开始--size[%d],nel[%d]------------",h->size,h->nel);
    for( i = 0; i < h->size; i ++)
    {
        printf("\r\n htables[%d]:",i);
        cur = h->htables[i];
        while((cur != NULL))
        {
            printf("key[%s],data[%s] ",cur->key,cur->data);
            cur = cur->next;
        }
    }
    
    printf("\r\n----结束--size[%d],nel[%d]------------",h->size,h->nel);
}

unsigned int simple_hash(const char * str)
{
    register unsigned int hash = 0;
    register unsigned int seed = 131;
    while (*str) {
        hash = hash * seed + *str++;
    }
    return hash & (0x7FFFFFFF);
}

int hashtable_hvalue(HashTable *h,const void *key)
{
    return (simple_hash(key) % h->size);
}

int hashtable_keycmp(HashTable *h,const void *key1,const void *key2)
{
    return strcmp(key1, key2);
}

void hashtable_node_free(HashTable_node * node)
{
    struct test_node * ptmp = NULL;
    
    // 释放测试数据
    ptmp = container(node->key, struct test_node, key);
    
    free(ptmp);
    free(node);
}

//void containerFunction(void * nodeKey, typeof(struct test_node) type, char * key)
//{
//    const typeof(((type *)0)->key) *__mptr = nodeKey;
//    (type *) ( (char *)__mptr - offsetof(type, key));
//}
