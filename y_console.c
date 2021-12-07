#include "y_console.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>


/******************************************************/
static void _putchar(const char c)
{
    printf("%c", c);
}
/******************************************************/

#ifdef USING_STDOUT
#include <stdio.h>
static int (*y_print)(const char* format, ...) = printf;
#else
static int _print(const char* format, ...);
static int (*y_print)(const char* format, ...) = _print;
#endif


int _print(const char* format, ...)
{
    va_list ap;
    va_start(ap, format);
    int ret = 0;
    char ch, temp[255];
    char* c_p;
    int num;
    while(*format)
    {
        if('%' != *format)
        {
            _putchar(*format);
            format++;
            ret++;
        }
        else
        {
            format++;
            switch(*format)
            {
                case 'c':
                    ch = va_arg(ap, int);
                    _putchar(ch);
                    format++;
                    ret++;
                    break;
                case 'd':
                    num = va_arg(ap, int);
                    itoa(num,temp,10);
                    ret+=y_print(temp);
                    format++;
                    break;
                case 's':
                    c_p = (char*)va_arg(ap, char*);
                    ret+=y_print(c_p);
                    format++;
                    break;
                default:
                    break;
            }
        }
    }
    va_end(ap); 
    return ret;
}


Y_COMMAND* y_command_create(const char* name, const char* des, const char* help, int (*func)(int argc, char** argv))
{
    Y_COMMAND* ret;
    ret = malloc(sizeof(Y_COMMAND));
    ret->name = name;
    ret->describe = des;
    ret->help = help;
    ret->func = func;
    return ret;
}

Y_ERR_T y_command_register(Y_CONSOLE* console, Y_COMMAND* cmd)
{
    console->cmdlist[console->len] = cmd;
    y_print("cmd address: %d \r\n",(int)console->cmdlist[console->len]);
    y_HT_insert(console->hashtable, console->cmdlist[console->len]->name, console->cmdlist[console->len]);
    (console->len)++;
    return Y_OK;
}

/***********************内建命令**********************/
int _list(int argc, char* argv[]);
/****************************************************/

Y_CONSOLE* y_console_init(int len)
{
    Y_CONSOLE* console;
    Y_COMMAND* temp_cmd;
    console = malloc(sizeof(Y_CONSOLE));
    // y_print("console address: %d \r\n",(int)console);
    console->hashtable = y_HT_create_hashtable(20);
    // y_print("hashtable address: %d \r\n",(int)console->hashtable);
    console->cmdlist = malloc(sizeof(Y_COMMAND*)*len);
    // y_print("cmdlist address: %d \r\n",(int)console->cmdlist);
    console->len=0;
    temp_cmd = y_command_create("list", "列出所有命令", "list", _list);
    y_command_register(console, temp_cmd);
    return console;
}

int y_cmd_call(Y_CONSOLE* console, const char* name, int argc, char** argv)
{
    Y_COMMAND* temp=NULL;
    // y_print("---------------------------------\r\n");
    // y_print("console address: %d \r\n",(int)console);
    // y_print("hashtable address: %d \r\n",(int)(console->hashtable));
    // y_print("cmdlist address: %d \r\n",(int)console->cmdlist);
    // y_print("cmd address: %d \r\n",(int)console->cmdlist[console->len]);
    // y_print("name address: %d \r\n",(int)name);
    // y_print("---------------------------------\r\n");
    temp = y_HT_search_by_key(console->hashtable, name);
    if(temp)
        return (temp->func)(argc, argv);
    else
        return Y_ERR;
}

Y_ERR_T y_console_deinit(Y_CONSOLE* console)
{
    if(console)
    {
        if(console->hashtable)
            y_HT_del_hashtable(console->hashtable);
        if(console->cmdlist)
        {
            for(int i=0;i<console->len;i++)
            {
                if(console->cmdlist[i])
                    {
                        free(console->cmdlist[i]);
                        console->cmdlist[i] = NULL;
                    }
            }
            free(console->cmdlist);
            console->cmdlist=NULL;
        }
        free(console);
        console=NULL;
    }
    return Y_OK;
}

int y_run_from_string(Y_CONSOLE* console, char* str)
{
    Y_STR_PRASED* temp;
    int ret=0;
    temp = y_string_prase(str);

    printf("************************************************\r\n");

    printf("argc : %d \r\n", temp->num);
    printf("argv : %s \r\n", temp->string_t[0]);
    printf("argv address: %d \r\n", (int)temp->string_t);

    printf("************************************************\r\n");
    if(temp->num)
    {
        ret = y_cmd_call(console, temp->string_t[0], temp->num, temp->string_t);
        y_string_del(temp);
        return ret;
    }
    else
    {
        y_string_del(temp);
        return -1;
    }
    
}


/************************内建命令******************************/

int _list(int argc, char* argv[])
{
    Y_CONSOLE* console=(Y_CONSOLE*)argc;
    y_print("======================================================================\r\n");
    y_print("命令列表:\r\n");
    for(int i=0;i<console->len;i++)
    {
        y_print("第[%d]个命令\tname:\t%s\taddress:\t%d\r\n",i+1,console->cmdlist[i]->name,(int)console->cmdlist[i]->func);
    }
    y_print("======================================================================\r\n");
    return 0;
}

/**************************************************************/
