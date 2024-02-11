/*
** EPITECH PROJECT, 2024
** main_envfile
** File description:
** main_env
*/

#include "minishell1.h"
#include "library.h"

int main_env(int ac, char **av, char **env)
{
    int len_env;

    if (!env)
        return 84;
    len_env = my_array_len(env);
    if (ac == 1 && my_strcmp(av[0], "env") == 0) {
        for (int i = 0; i < len_env; i++) {
            my_putstr(env[i]);
            my_putchar('\n');
        }
    } else
        return 84;
    return 0;
}
