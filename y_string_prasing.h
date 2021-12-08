/*encoding:GB2312*/
#ifndef __Y_STRING_PRASING_H__
#define __Y_STRING_PRASING_H__

#ifdef __cplusplus
extern "C"{
#endif


#define MAX_NUM_OF_ARGS     6       //最大的参数数量
#define MAX_LEN_OF_ARGS     16       //参数中字符串最大的长度
typedef struct Y_STR_PRASED
{
    char *string_t[MAX_NUM_OF_ARGS];
    int num;
}Y_STR_PRASED;

Y_STR_PRASED* y_string_prase(char* str);//将字符串类型解析成Y_STR_PRASED类型
int y_string_del(Y_STR_PRASED* str_prased);//销毁Y_STR_PRASED


#ifdef __cplusplus
}
#endif

#endif /*__Y_STRING_PRASING_H__*/