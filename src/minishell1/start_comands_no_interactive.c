/*
** EPITECH PROJECT, 2024
** no interactive start commands
** File description:
** start_comands_no_interactive
*/

#include "minishell1.h"
#include "library.h"

int start_commands_non_interactive(char **data, int cmds, commands_t *commands,
    char **env)
{
    if (cmds == 2 || cmds == 1) {
        execution_process(data, cmds, commands, env);
    }
    return 0;
}
