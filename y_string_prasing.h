/*encoding:GB2312*/
#ifndef __Y_STRING_PRASING_H__
#define __Y_STRING_PRASING_H__

#ifdef __cplusplus
extern "C"{
#endif


#define MAX_NUM_OF_ARGS     6       //���Ĳ�������
#define MAX_LEN_OF_ARGS     16       //�������ַ������ĳ���
typedef struct Y_STR_PRASED
{
    char *string_t[MAX_NUM_OF_ARGS];
    int num;
}Y_STR_PRASED;

Y_STR_PRASED* y_string_prase(char* str);//���ַ������ͽ�����Y_STR_PRASED����
int y_string_del(Y_STR_PRASED* str_prased);//����Y_STR_PRASED


#ifdef __cplusplus
}
#endif

#endif /*__Y_STRING_PRASING_H__*/