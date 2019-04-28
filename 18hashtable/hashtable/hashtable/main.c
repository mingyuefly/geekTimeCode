//
//  main.c
//  hashtable
//
//  Created by Gguomingyue on 2019/4/18.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include "Hashtable.h"
#include "Listhash.h"

int main(int argc, const char * argv[]) {
 
    /***** 线性探针测试 ****/
//    struct hash_table table;
//    hash_table_reset(&table);
//     //3852 和 4044 hash值相同都是12
//    hash_table_add(&table, 3852);
//    hash_table_add(&table, 4044);
//    printf("Table has%s 3852\n",
//           hash_table_find(&table, 3852) ? "":"n't");
//    printf("Table has%s 4044\n",
//           hash_table_find(&table, 4044) ? "":"n't");
//    hash_table_dump(&table);
    
    
    //hash_function_test();
    //hash_table_next_probe_test();
    //hash_table_add_test();
    
    //hash_table_delete_test1();
    //hash_table_delete_test2();
    
    
    /******* 链表法测试 *******/
    //int i = 0;
    int res = 0;
    char *pres = NULL;
    HashTable_node * node = NULL;
    struct test_node *p = NULL;
    HashTable *h = NULL;
#ifdef MEMORY_TEST
    setenv("MALLOC_TRACE","1.txt",1);
    mtrace();
#endif
    
    h = hashtable_create(5, hashtable_hvalue, hashtable_keycmp, hashtable_node_free);
    assert(h!= NULL);
    // 插入
    while(1)
    {
        p = (struct test_node *)malloc(sizeof(struct test_node));
        assert(p != NULL);
        printf("\r\n 请输入key 和value，当可以等于\"quit\"时退出");
        scanf("%s",p->key);
        scanf("%s",p->data);
        
        if(strcmp(p->key,"quit") == 0)
        {
            free(p);
            break;
        }
        
        res = hashtable_insert(h, p->key, p->data);
        if (res != 0)
        {
            free(p);
            printf("\r\n key[%s],data[%s] insert failed %d",p->key,p->data,res);
        }
        else
        {
            printf("\r\n key[%s],data[%s] insert success %d",p->key,p->data,res);
        }
    }
    hashtable_dump(h);
    
    // 查询
    while(1)
    {
        p = (struct test_node*)malloc(sizeof(struct test_node));
        assert(p != NULL);
        printf("\r\n 请输入key 查询value的数值，当可以等于\"quit\"时退出");
        scanf("%s",p->key);
        
        if(strcmp(p->key,"quit") == 0)
        {
            free(p);
            break;
        }
        pres = hashtable_search(h,p->key);
        if (pres == NULL)
        {
            printf("\r\n key[%s] search data failed",p->key);
        }
        else
        {
            printf("\r\n key[%s],search data[%s] success",p->key,pres);
        }
        free(p);
    }
    hashtable_dump(h);
    
    // 删除
    while(1)
    {
        p = (struct test_node *)malloc(sizeof(struct test_node));
        assert(p != NULL);
        printf("\r\n 请输入key 删除节点的数值，当可以等于\"quit\"时退出");
        scanf("%s",p->key);
        
        if(strcmp(p->key,"quit") == 0)
        {
            free(p);
            break;
        }
        node = hashtable_delete(h,p->key);
        if (node == NULL)
        {
            printf("\r\n key[%s] delete node failed ",p->key);
        }
        else
        {
            printf("\r\n key[%s],delete data[%s] success", node->key,  node->data);
            h->hash_node_free(node);
        }
        free(p);
        hashtable_dump(h);
    }
    
    hashtable_destory(h);
#ifdef MEMORY_TEST
    muntrace();
#endif
    
    return 0;
}
