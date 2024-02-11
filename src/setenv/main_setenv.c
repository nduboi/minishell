/*
** EPITECH PROJECT, 2024
** setenv
** File description:
** main_setenv
*/

#include "minishell1.h"
#include "library.h"

static char *put_new_env(char *name, char *value)
{
    int len_name;
    int len_value;
    char *result = NULL;

    if (name && value) {
        len_value = my_strlen(value);
        len_name = my_strlen(name);
        result = malloc(sizeof(char) * (len_name + 1 + len_value + 1));
        for (int i = 0; i < len_name; i++) {
            result[i] = name[i];
        }
        result[len_name] = '=';
        for (int i = 0; i < len_value; i++) {
            result[i + len_name + 1] = value[i];
        }
    }
    return result;
}

char **my_table_cpy(char **src)
{
    char **result = NULL;
    int array_len = 0;

    if (src) {
        array_len = my_array_len(src);
        result = malloc(sizeof(char *) * (array_len + 1));
        for (int i = 0; i < array_len; i++) {
            result[i] = my_strdup(src[i]);
        }
        result[array_len] = NULL;
    }
    return result;
}

char **realloc_env(char **env, int nbr_moreline, char *name, char *value)
{
    char **cpy_env = my_table_cpy(env);
    int len = my_array_len(env);

    env = NULL;
    env = malloc(sizeof(char *) * (len + nbr_moreline + 1));
    for (int i = 0; i < len; i++) {
        env[i] = cpy_env[i];
    }
    env[len] = put_new_env(name, value);
    env[len + nbr_moreline + 1] = NULL;
    return env;
}

static char **modify_env_file(char **env, char *name, char *value)
{
    int nbr_line = 0;

    nbr_line = get_line_env(name, my_table_cpy(env));
    env[nbr_line] = put_new_env(name, value);
    return env;
}

char **add_value_in_env(char **av, char **env)
{
    if (get_env(av[1], my_table_cpy(env)) == NULL)
        env = realloc_env(env, 1, av[1], av[2]);
    else
        env = modify_env_file(env, av[1], av[2]);
    return env;
}

int main_setenv(int ac, char **av, char ***env)
{
    if (ac == 3 && my_strcmp(av[0], "setenv") == 0 && (*env) &&
        av[1] && av[2]) {
        (*env) = add_value_in_env(av, (*env));
    } else
        return 84;
    return 0;
}
