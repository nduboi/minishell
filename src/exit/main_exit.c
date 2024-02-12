/*
** EPITECH PROJECT, 2024
** main_exit
** File description:
** main_exit
*/

#include "library.h"
#include "minishell1.h"

int main_exit(int ac, char **av, char ***env)
{
    if (*env != NULL)
        *env = *env;
    if (ac >= 2) {
        exit(my_getnbr(av[1]));
    } else
        exit(0);
    return 0;
}
