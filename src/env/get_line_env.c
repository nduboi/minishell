/*
** EPITECH PROJECT, 2024
** getline env
** File description:
** get_line_env
*/

#include "minishell1.h"
#include "library.h"

int get_line_env(char *name, struct env_var *env)
{
    int row = 0;
    struct env_var *elements = env;

    for (; elements; row++) {
        if (my_strcmp(elements->name, name) == 0) {
            return row;
        }
        elements = elements->next;
    }
    return -1;
}
