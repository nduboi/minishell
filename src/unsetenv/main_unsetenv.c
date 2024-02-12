/*
** EPITECH PROJECT, 2024
** main_unsetenv
** File description:
** main_unsetenv
*/

#include "library.h"
#include "minishell1.h"

static char **remove_data_line(int row, char **env, int table_len)
{
    char **result = malloc(sizeof(char *) * (table_len));
    int i = 0;
    int k = 0;

    result[table_len - 1] = NULL;
    for (; i < (table_len); k++) {
        if (i == row)
            k++;
        if (!env[k])
            return result;
        result[i] = my_strdup(env[k]);
        i++;
    }
    return result;
}

static void remove_this_name(char *src, char ***env)
{
    int row;
    char **env_cpy = NULL;
    char **env_cpy2 = NULL;

    if (!src || !(*env))
        return;
    env_cpy = my_table_cpy(*env);
    env_cpy2 = my_table_cpy(*env);
    row = get_line_env(src, env_cpy);
    if (row == -1)
        return;
    *env = remove_data_line(row, env_cpy2, my_array_len(env_cpy2));
    return;
}

static int research_environement(char **data, char ***env)
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

int main_unsetenv(int ac, char **av, char ***env)
{
    if (ac >= 2 && my_strcmp(av[0], "unsetenv") == 0) {
        return research_environement(av, env);
    }
    if (ac < 2)
        return 1;
    return 0;
}
