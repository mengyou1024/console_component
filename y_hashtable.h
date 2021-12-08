/*encoding:GB2312*/
#ifndef __Y_HASHTABLE_H__
#define __Y_HASHTABLE_H__

#ifdef __cplusplus
extern "C"{
#endif /*__cplusplus*/

typedef struct Y_Node
{
    const char* key;//万能指针
    void* obj;
    struct Y_Node* Next_t;
}Y_Node;

typedef struct Y_HashTable
{
    Y_Node** data;
    int size;
}Y_HashTable;

typedef enum Y_Hash_Err
{
    Y_Hash_OK=0,
    Y_Hash_Mul=1,
    Y_Hash_Null=-1
}Y_Hash_Err;

Y_HashTable* y_HT_create_hashtable(int size);//创建哈希表
Y_Node* y_HT_create_Node(Y_Node* head, const char* key, void* obj);//创建节点
int y_HT_str2hash(const char* str);//字符串转哈希值
Y_Hash_Err y_HT_insert(Y_HashTable *hastable, const char* key, void* obj);//插入数据
void* y_HT_search_by_key(Y_HashTable *hashtable, const char* key);//通过字符串查找数据
//Y_Hash_Err y_HT_del_node(Y_Node* node);//删除节点
Y_Hash_Err y_HT_del_hashtable(Y_HashTable* hashtable);//删除哈希表


#ifdef __cplusplus
}
#endif /*__cplusplus*/

#endif /*__Y_HASHTABLE_H__*/
