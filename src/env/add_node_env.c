/*
** EPITECH PROJECT, 2024
** add node
** File description:
** add_node_env
*/

#include "minishell1.h"
#include "library.h"

char **fill_env_variables_oldpwd(void)
{
    char **env_variables = malloc(sizeof(char *) * 4);

    env_variables[0] = my_strdup("setenv");
    env_variables[1] = my_strdup("1OLDPWD");
    env_variables[2] = NULL;
    env_variables[3] = NULL;
    return env_variables;
}

char **fill_env_variables_pwd(void)
{
    char **env_variables = malloc(sizeof(char *) * 4);

    env_variables[0] = my_strdup("setenv");
    env_variables[1] = my_strdup("PWD");
    env_variables[2] = NULL;
    env_variables[3] = NULL;
    return env_variables;
}

void add_node_env_struct(char *src, char *value, env_var_t **pos)
{
    env_var_t *elements = malloc(sizeof(env_var_t));

    elements->name = src;
    elements->value = value;
    elements->next = *pos;
    *pos = elements;
}
