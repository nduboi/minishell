/*
** EPITECH PROJECT, 2024
** fill_struct
** File description:
** fill_struct
*/

#include "minishell1.h"
#include "library.h"

static void cd_fill_struct(commands_t **commands)
{
    commands_t *cd = malloc(sizeof(commands_t));

    cd->name = my_strdup("cd");
    cd->next = *commands;
    *commands = cd;
    return;
}

static void setenv_fill_struct(commands_t **commands)
{
    commands_t *setenv = malloc(sizeof(commands_t));

    setenv->name = my_strdup("setenv");
    setenv->next = *commands;
    *commands = setenv;
    return;
}

static void unsetenv_fill_struct(commands_t **commands)
{
    commands_t *unsetenv = malloc(sizeof(commands_t));

    unsetenv->name = my_strdup("unsetenv");
    unsetenv->next = *commands;
    *commands = unsetenv;
    return;
}

static void env_fill_struct(commands_t **commands)
{
    commands_t *env = malloc(sizeof(commands_t));

    env->name = my_strdup("env");
    env->next = *commands;
    *commands = env;
    return;
}

static void exit_fill_struct(commands_t **commands)
{
    commands_t *exit = malloc(sizeof(commands_t));

    exit->name = my_strdup("exit");
    exit->next = *commands;
    *commands = exit;
    return;
}

void fill_struct(commands_t **commands)
{
    cd_fill_struct(commands);
    setenv_fill_struct(commands);
    unsetenv_fill_struct(commands);
    env_fill_struct(commands);
    exit_fill_struct(commands);
    return;
}
