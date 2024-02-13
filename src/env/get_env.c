/*
** EPITECH PROJECT, 2024
** get_env
** File description:
** get_env
*/

#include "minishell1.h"
#include "library.h"

static int check_if_good_value(env_var_t *elements, char *src)
{
    if (elements->value && elements->name) {
        if (my_strcmp(elements->name, src) == 0)
            return 0;
    }
    return 1;
}

char *get_env(char *src, struct env_var *env)
{
    env_var_t *elements = env;

    if (!elements)
        return NULL;
    while (elements) {
        if (check_if_good_value(elements, src) == 0)
            return elements->value;
        elements = elements->next;
    }
    return NULL;
}
