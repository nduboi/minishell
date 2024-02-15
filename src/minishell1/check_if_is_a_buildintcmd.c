/*
** EPITECH PROJECT, 2024
** check
** File description:
** check_if_is_a_buildintcmd
*/

#include "minishell1.h"
#include "library.h"

static void set_function(char **data, commands_t **elements)
{
    if (my_strcmp(data[0], "cd") == 0)
        (*elements)->fct = main_cd;
    if (my_strcmp(data[0], "env") == 0)
        (*elements)->fct = main_env;
    if (my_strcmp(data[0], "setenv") == 0)
        (*elements)->fct = main_setenv;
    if (my_strcmp(data[0], "unsetenv") == 0)
        (*elements)->fct = main_unsetenv;
    if (my_strcmp(data[0], "exit") == 0)
        (*elements)->fct = main_exit;
    return;
}

int check_if_is_a_buildintcmd(char **data, commands_t **elements)
{
    while (*elements) {
        if (my_strcmp(data[0], (*elements)->name) == 0) {
            set_function(data, elements);
            return 1;
        }
        *elements = (*elements)->next;
    }
    return 0;
}
