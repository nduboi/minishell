/*
** EPITECH PROJECT, 2024
** check_if_is a correct command
** File description:
** check_command
*/

#include "minishell1.h"
#include "library.h"

int check_internal_commands(char *src, int *cmds)
{
    struct stat buffer;
    char *pwd = get_pwd_file(src);

    if (stat(pwd, &buffer) == -1 && stat(src, &buffer) == -1)
        return 0;
    if (access(pwd, X_OK) == -1 && access(src, X_OK) == -1) {
        write(2, "Cannot execute program\n", 24);
        *cmds = 0;
        return 1;
    }
    *cmds = 2;
    return 1;
}

void check_correct_command(int *cmds, char *str, commands_t *commands)
{
    commands_t *elements = commands;

    if (!str)
        exit(0);
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
