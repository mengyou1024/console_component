/*encoding:GB2312*/
#ifndef __Y_CONSOLE_H__
#define __Y_CONSOLE_H__

#ifdef __cplusplus
extern "C"{
#endif
#include "y_hashtable.h"
#include "y_string_prasing.h"

//#define USING_STDOUT //ʹ�ñ�׼���

typedef enum 
{
    Y_OK=0,
    Y_ERR=-1
}Y_ERR_T;

typedef struct Y_COMMAND
{
    const char* name;
    const char* describe;
    const char* help;
    int (*func)(int argc, char** argv);
}Y_COMMAND;

typedef struct Y_CONSOLE
{
    Y_COMMAND** cmdlist;
    Y_HashTable* hashtable;
    int len;
}Y_CONSOLE;


Y_CONSOLE* y_console_init(int len);//����̨��ʼ��
Y_COMMAND* y_command_create(const char* name, const char* des, const char* help, int (*func)(int argc, char** argv));//��������
Y_ERR_T y_command_register(Y_CONSOLE* console, Y_COMMAND* cmd);//����ע��
int y_cmd_call(Y_CONSOLE* console, const char* name, int argc, char** argv);//ִ������
int y_run_from_string(Y_CONSOLE* console, char* str);
Y_ERR_T y_console_deinit(Y_CONSOLE* console);//����̨���


#ifdef __cplusplus
}
#endif


#endif /*__Y_CONSOLE_H__*/
