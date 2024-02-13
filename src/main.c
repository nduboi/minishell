/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "minishell1.h"
#include "library.h"

int main(int ac, char **av, char **env)
{
    env_var_t *env_var = fill_environement(env);

    (void)av;
    if (ac == 1) {
        if (isatty(STDIN_FILENO)) {
            return get_input_user(env_var);
        } else
            return non_interactive(env_var);
    } else
        return 127;
    return 0;
}
