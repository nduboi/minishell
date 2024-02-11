/*
** EPITECH PROJECT, 2024
** main cd
** File description:
** main_cd
*/

#include "minishell1.h"
#include "library.h"

int main_cd(int ac, char **av, char **env)
{
    if (env != NULL)
        env = NULL;
    if (ac == 1 && my_strcmp(av[0], "cd") == 0) {
        chdir(getenv("HOME"));
    } else
        return 84;
    return 0;
}
