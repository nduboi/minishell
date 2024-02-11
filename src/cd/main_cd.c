/*
** EPITECH PROJECT, 2024
** main cd
** File description:
** main_cd
*/

#include "minishell1.h"
#include "library.h"

static int go_folder (char *src)
{
    if (opendir(src) == NULL)
        return 84;
    else
        chdir(src);
    return 0;
}

int main_cd(int ac, char **av, char **env)
{
    if (ac == 1 && my_strcmp(av[0], "cd") == 0) {
        chdir(get_env("HOME", env));
        return 0;
    }
    if (ac == 2 && my_strcmp(av[0], "cd") == 0) {
        if (my_strcmp(av[1], "~") != 0 && my_strcmp(av[1], "-") != 0) {
            return go_folder(av[1]);
        } else
            return 84;
    } else
        return 84;
    return 0;
}
