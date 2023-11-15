#include "commands.h"
#include "./lib/string_utils.h"

Command COMMANDS_STACK[COMMANDS_STACK_SIZE * sizeof(Command)];

void register_command(char *name, int function(), int id)
{
    Command cmd = {.name = name, .function = function, .id = id};
    COMMANDS_STACK[id] = cmd;
}

void setup_commands(void)
{
    register_command("print", &print_text, PRINT);
    register_command("quit", &quit_program, QUIT);
}

char **split_line_command_arguments(char *buffer)
{
    char **arguments;
    char *letter;
    int initial_index = 0, final_index = 0;

    arguments = malloc(2 * sizeof(char *));

    while (buffer[initial_index] == ' ')
        initial_index++;

    if (buffer[initial_index] == '\0' || buffer[initial_index] == '\n')
        return NULL;

    letter = &buffer[initial_index];
    final_index = initial_index;

    while (buffer[final_index] != ' ' && buffer[final_index] != '\0')
        final_index++;

    arguments[0] = malloc((final_index - initial_index) * sizeof(char));
    for (int x = 0; x < final_index - initial_index; x++)
    {
        arguments[0][x] = *letter;
        letter++;
    }
    arguments[0][final_index - initial_index] = '\0';

    final_index++;
    initial_index = final_index;
    letter = &buffer[initial_index];

    if (*letter == '\0')
    {
        arguments[1] = NULL;
        return arguments;
    }

    while (buffer[final_index] != '\0')
        final_index++;

    arguments[1] = malloc((final_index - initial_index) * sizeof(char));
    for (int x = 0; x < final_index - initial_index; x++)
    {
        arguments[1][x] = *letter;
        letter++;
    }
    arguments[1][final_index - initial_index] = '\0';
    return arguments;
}

int call_function_by_name(char *name, char *args)
{
    for (int initial_index = 0; initial_index < COMMANDS_STACK_SIZE; ++initial_index)
        if (strcmp(name, COMMANDS_STACK[initial_index].name) == 0)
            return COMMANDS_STACK[initial_index].function(args);
    return 1;
}

// functions associated with the commands
int print_text(char *arguments)
{
    string *tokens;
    string str_to_print;
    int token_counter = 0;

    if (arguments != NULL)
    {
        tokens = tokenize(arguments, &token_counter);
        if (strcmp(tokens[0], '-a'))
        printf("%s\n", arguments);
    }
    return 0;
}

int quit_program(char *arguments)
{
    if (arguments != NULL)
        printf("arguments passed to the quit function = %s\n", arguments);
    printf("called the function `quit_program`\n");
    return 0;
}