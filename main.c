#include <stdio.h>
#include "y_console.h"
#include "y_string_prasing.h"
int test(int argc, char* argv[])
{
    printf("-------------------------------------\r\n");
    printf("argc: %d\r\n", argc);
    for(int i=0;i<argc;i++)
        printf("argv[%d]: %s\r\n", i, argv[i]);
    printf("-------------------------------------\r\n");
    //printf("123456789\r\n");
    return 0;
}
int main(int argc, char* argv[])
{
    Y_COMMAND *cmd;
    Y_CONSOLE *console;
    console = y_console_init(20);
    cmd = y_command_create("hello", "hello test", "this is help", test);
    y_command_register(console, cmd);
    /*y_cmd_call(console, "list", console, NULL);
    y_cmd_call(console, "hello", 0, NULL);*/
    y_run_from_string(console, " hello qwewqeasd wqewqsw");
    y_run_from_string(console, " list");
    y_console_deinit(console);

    /*char *test = "   wqweqw   qweqsa   1556";
    Y_STR_PRASED *ys;
    ys = y_string_prase(test);

    printf("parse_num: %d \r\n", ys->num);

    for(int i=0;i<ys->num;i++)
    {
        printf("prase[%d]: %s\r\n", i, ys->string_t[i]);
    }

    y_string_del(ys);*/
    return 0;
}