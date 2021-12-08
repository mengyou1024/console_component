/*encoding:GB2312*/
#include "y_string_prasing.h"


#include <string.h>
#include <stdlib.h>
#include <stdio.h>


Y_STR_PRASED* y_string_prase(char* str)
{
    Y_STR_PRASED* ret = malloc(sizeof(Y_STR_PRASED));
    char *start, *end;
    memset(ret, 0, sizeof(Y_STR_PRASED));
    for(int i=0;i<MAX_NUM_OF_ARGS;i++)
    {
        ret->string_t[i] = (char*)malloc(sizeof(char)*MAX_LEN_OF_ARGS);
        memset(ret->string_t[i], 0, sizeof(char)*MAX_LEN_OF_ARGS);
    }
    while(*str == ' ')
    {
        str++;
    }
    start = str;
    while(*str)
    {
        if(*(str+1) == '\0') 
        {   
            end=str+1;
            strncpy(ret->string_t[ret->num++], start, (int)(end-start));
            break;
        }
        else if(*str == ' ')
        {
            end = str;
            strncpy(ret->string_t[ret->num++], start, (int)(end-start));
            while(*str == ' ')
            {
                str++;
            }
            if(*(str+1) == '\0') 
            {
                end = str;
                strncpy(ret->string_t[ret->num++], start, (int)(end-start));
                break;
            }
            else
                start = str;
        }
        else
            str++;
    }
    return ret;
}

int y_string_del(Y_STR_PRASED* str_prased)
{
    if(str_prased)
    {
        for(int i=0;i<MAX_NUM_OF_ARGS;i++)
        {
            free(str_prased->string_t[i]);
        }
        free(str_prased);
    }
    return 0;
}