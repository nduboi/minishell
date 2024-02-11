/*
** EPITECH PROJECT, 2024
** get_env
** File description:
** get_env
*/

#include "minishell1.h"
#include "library.h"

char *get_env(char *src, char **env)
{
    char *result = NULL;

    for (int i = 0; env[i]; i++) {
        result = strtok(env[i], "=");
        if (my_strcmp(result, src) == 0) {
            result = strtok(NULL, "\n");
            return result;
        }
    }
    return result;
}
