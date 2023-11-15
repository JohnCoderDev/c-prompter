#ifndef COMMANDS_H
#define COMMANDS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum COMMANDS
{
    PRINT,
    QUIT,
    COMMANDS_STACK_SIZE
};

typedef struct
{
    const char *name;
    int (*function)();
    int id;
} Command;

// public stack with all the commands
extern Command COMMANDS_STACK[COMMANDS_STACK_SIZE * sizeof(Command)];

// function to register the command in the `COMMANDS_STACK`
void register_command(char *name, int function(), int id);

// function to setup all the commands
void setup_commands(void);

// gets a string and call the function associated with the `Command`
// struct with the same `name`
int call_function_by_name(char *name, char *args);

// declarations of the functions associated with the commands

int print_text(char *args);
int quit_program(char *args);
char **split_line_command_arguments(char *buffer);
#endif