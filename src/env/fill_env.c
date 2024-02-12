/*
** EPITECH PROJECT, 2024
** fill env
** File description:
** fill_env
*/

#include "minishell1.h"
#include "library.h"

char **fill_env_variables_oldpwd(void)
{
    char **env_variables = malloc(sizeof(char *) * 4);

    env_variables[0] = my_strdup("setenv");
    env_variables[1] = my_strdup("OLDPWD");
    env_variables[3] = NULL;
    return env_variables;
}
