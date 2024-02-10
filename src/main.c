/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "minishell1.h"
#include "library.h"

int main(int ac, char **av)
{
    if (ac == 1 && my_strcmp(av[0], "./mysh") == 0) {
        if (isatty(STDIN_FILENO)) {
            return get_input_user();
        } else
            return non_interactive();
    } else
        return 84;
    return 0;
}
