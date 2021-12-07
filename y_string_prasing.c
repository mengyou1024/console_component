#include "y_string_prasing.h"


#include <string.h>
#include <stdlib.h>


Y_STR_PRASED* y_string_prase(char* str)
{
    Y_STR_PRASED* ret = malloc(sizeof(Y_STR_PRASED));
    memset(ret, 0, sizeof(Y_STR_PRASED));
    int i = 0;
    char* temp;
    temp = ret->string_t[i];
    while(*str)
    {
        if(*str == '\0') 
        {   
            *(temp) = '\0';
            break;
        }
        else if(*str == ' ')
        {
            *(temp) = '\0';
            while(*str == ' ')
            {
                str++;
            }
            if(*(str+1) == '\0') break;
            temp = ret->string_t[++i];
        }
        
        *temp++ = *str++;
    }
    ret->num = i+1;
    return ret;
}

int y_string_del(Y_STR_PRASED* str_prased)
{
    if(str_prased)
        free(str_prased);
    return 0;
}