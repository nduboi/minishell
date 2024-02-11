/*
** EPITECH PROJECT, 2024
** getline env
** File description:
** get_line_env
*/

#include "minishell1.h"
#include "library.h"

int get_line_env(char *name, char **env)
{
    int row = 0;

    for (; env[row]; row++) {
        if (my_strcmp(strtok(env[row], "="), name) == 0) {
            return row;
        }
    }
    return row;
}
