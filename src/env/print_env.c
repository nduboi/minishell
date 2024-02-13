/*
** EPITECH PROJECT, 2024
** print env
** File description:
** print_env
*/

#include "minishell1.h"
#include "library.h"

void print_env(env_var_t *env)
{
    env_var_t *element = env;

    while (element) {
        if (element->name)
            my_putstr(element->name);
        my_putchar('=');
        if (element->value)
            my_putstr(element->value);
        my_putchar('\n');
        element = element->next;
    }
}
