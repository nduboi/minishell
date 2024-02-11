/*
** EPITECH PROJECT, 2024
** no interactive start commands
** File description:
** start_comands_no_interactive
*/

#include "minishell1.h"
#include "library.h"

static int execute_in_commands_struct(commands_t *commands,
    char **data, char ***env)
{
    commands_t *elements = commands;

    while (elements) {
        if (my_strcmp(data[0], elements->name) == 0) {
            exit(elements->fct(my_array_len(data), data, env));
        }
        elements = elements->next;
    }
    return 1;
}

static int execution_process_non_interactive(char **data, int cmds,
    commands_t *commands, char ***env)
{
    if (cmds == 2) {
        if (execve(get_pwd_file(data[0]), data, (*env)) == -1) {
            perror("execve");
            return 1;
        }
    } else if (cmds == 1) {
        execute_in_commands_struct(commands, data, env);
    }
    return 0;
}

int start_commands_non_interactive(char **data, int cmds, commands_t *commands,
    char ***env)
{
    if (cmds == 2 || cmds == 1) {
        execution_process_non_interactive(data, cmds, commands, env);
    }
    return 0;
}
