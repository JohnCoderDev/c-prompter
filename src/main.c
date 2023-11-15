#include <stdio.h>
#include <stdlib.h>
#include "commands.h"
#include "prompt_config.h"
#include "./lib/string_utils.h"

void get_user_input(char *buffer, int *length)
{
    fgets(buffer, BUFFER_SIZE, stdin);
    *length = strlen(buffer);
    buffer[(*length) - 1] = '\0';
}

void prompt_loop(void)
{
    char buffer[BUFFER_SIZE];
    string *line_arguments;
    string function_name, arguments;
    int length, fid;
    printf("%s\n", WELCOME_MSG);
    do
    {
        printf("%s", COMMAND_LINE);
        get_user_input(buffer, &length);
        line_arguments = split_line_command_arguments(buffer);
        
        if (line_arguments == NULL)
            continue;
        
        function_name = line_arguments[0];
        arguments = line_arguments[1];
        
        if (call_function_by_name(function_name, arguments) == 1)
            printf("ERROR: command `%s` not recognized\n", function_name);      

        if (strcmp(function_name, "quit") == 0) {
            free(line_arguments);
            break;
        }
        free(line_arguments);
    } while (1);
}

int main(int argc, char **argv[])
{
    setup_commands();
    prompt_loop();
    return 0;
}
