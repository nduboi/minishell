/*
** EPITECH PROJECT, 2024
** print env
** File description:
** print_env
*/

#include "minishell1.h"
#include "library.h"

void print_env(char **env)
{
    int len_env = my_array_len(env);

    for (int i = 0; i < len_env; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
}
