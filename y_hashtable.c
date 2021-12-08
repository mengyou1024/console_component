/*encoding:GB2312*/
#include "y_hashtable.h"

#include <stdlib.h>
#include <string.h>

Y_HashTable* y_HT_create_hashtable(int size)
{
    if(size<=2) return NULL;
    Y_HashTable* ret = (Y_HashTable *)malloc(sizeof(Y_HashTable));
    memset(ret, 0, sizeof(Y_HashTable));
    ret->size = size;
    ret->data = (Y_Node**)calloc(ret->size, sizeof(Y_Node*));
    return ret;
}

Y_Node* y_HT_create_Node(Y_Node* head, const char* key, void* obj)
{
    Y_Node* ret = (Y_Node*)malloc(sizeof(Y_Node));
    memset(ret, 0, sizeof(Y_Node));
    ret->key = key;
    ret->obj = obj;
    ret->Next_t = NULL;
    if(head != NULL)
        head->Next_t = ret;
    return ret;
}

int y_HT_str2hash(const char* str)
{
    int ret=0,i=0;
    for(i=0;str[i]!='\0';i++)
    {
        ret += str[i];
    }
    return ret&0x7fffffff;
}

Y_Hash_Err y_HT_insert(Y_HashTable *hastable, const char* key, void* obj)
{
    int hash = y_HT_str2hash(key);
    int index = hash % hastable->size;
    if(hastable->data[index]==NULL)
    {
        hastable->data[index] = y_HT_create_Node(NULL, key, obj);
    }
    else
    {
        Y_Node *temp=hastable->data[index];
        while(temp->Next_t)
            temp=temp->Next_t;
        hastable->data[index] = y_HT_create_Node(temp, key, obj);
    }
    return Y_Hash_OK;
}

void* y_HT_search_by_key(Y_HashTable *hashtable, const char* key)
{
    int hash = y_HT_str2hash(key);
    int index = hash % hashtable->size;
    Y_Node* ret = hashtable->data[index];
    if(hashtable->data[index]==NULL) return NULL;
    while(ret && strcmp(key, ret->key))
        ret = ret->Next_t;
    return (void*)ret->obj;
}
Y_Hash_Err y_HT_del_hashtable(Y_HashTable* hashtable)
{
    if(hashtable == NULL) return Y_Hash_Mul;
    else
    {
        for(int i=0;i<hashtable->size;i++)
        {
            if(hashtable->data[i]==NULL) return Y_Hash_Mul;
            Y_Node *this=hashtable->data[i], *next;
            while(this)
            {
                next = this->Next_t;
                free(this);
                this = next;
            }
            free(this);
        }
        if(hashtable->data)
            free(hashtable->data);
        if(hashtable)
        free(hashtable);
    }
    return Y_Hash_OK;
}
