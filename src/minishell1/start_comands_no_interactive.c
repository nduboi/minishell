/*
** EPITECH PROJECT, 2024
** no interactive start commands
** File description:
** start_comands_no_interactive
*/

#include "minishell1.h"
#include "library.h"

int start_commands_non_interactive(char **data, int cmds, commands_t *commands)
{
    if (commands)
        commands = NULL;
    if (cmds == 2) {
        execution_process(data);
    }
    return 0;
}
