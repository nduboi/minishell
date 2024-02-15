/*
** EPITECH PROJECT, 2024
** main_unsetenv
** File description:
** main_unsetenv
*/

#include "library.h"
#include "minishell1.h"

static void remove_this_name(char *src, env_var_t **env)
{
    int row;

    if (!src || !(*env))
        return;
    row = get_line_env(src, *env);
    if (row == -1)
        return;
    delete_node(env, src);
    return;
}

static int research_environement(char **data, env_var_t **env)
{
    int len_table = 0;

    if (!(*env) || !(data))
        return 0;
    len_table = my_array_len(data);
    for (int i = 0; i < len_table; i++) {
        remove_this_name(data[i], env);
    }
    return 0;
}

int main_unsetenv(int ac, char **av, env_var_t **env, env_var_t *cpy_env)
{
    (void) cpy_env;
    if (ac >= 2)
        return research_environement(av, env);
    if (ac == 1) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return 1;
    }
    return 0;
}
