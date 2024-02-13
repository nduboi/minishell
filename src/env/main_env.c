/*
** EPITECH PROJECT, 2024
** main_envfile
** File description:
** main_env
*/

#include "minishell1.h"
#include "library.h"

int main_env(int ac, char **av, struct env_var **env)
{
    if (!(*env))
        return 84;
    if (ac == 1 && my_strcmp(av[0], "env") == 0) {
        print_env(*env);
    } else
        return 84;
    return 0;
}
