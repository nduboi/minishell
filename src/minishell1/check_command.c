/*
** EPITECH PROJECT, 2024
** check_if_is a correct command
** File description:
** check_command
*/

#include "minishell1.h"
#include "library.h"

int check_internal_commands(char *str, int *cmds)
{
    struct stat buffer;
    char *pwd = get_pwd_file(str);

    if (stat(pwd, &buffer) == -1)
        return 0;
    *cmds = 1;
    return 1;
}

void check_correct_command(int *cmds, char *str, commands_t *commands)
{
    commands_t *elements = commands;

    while (elements) {
        if (my_strcmp(str, elements->name) == 0) {
            *cmds = 1;
            return;
        }
        elements = elements->next;
    }
    if (check_internal_commands(str, cmds) == 1)
        return;
    *cmds = 0;
    write(2, "No commands found\n", 19);
    return;
}
