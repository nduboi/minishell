/*
** EPITECH PROJECT, 2024
** check_if_is a correct command
** File description:
** check_command
*/

#include "minishell1.h"
#include "library.h"

static int check_own_cmd(char *src, int *cmds)
{
    struct stat buffer;
    int cmd = 0;

    if (src[0] == '.' && src[1] == '/') {
        if (!(stat(src, &buffer) == -1))
            cmd = 1;
    }
    if (cmd == 1) {
        if (access(src, X_OK) == -1) {
            perror("errno");
            *cmds = 0;
            return 1;
        }
        *cmds = 2;
        return 1;
    }
    return 0;
}

static int check_internal_cmd(char *pwd, char *src, int *cmds, char **env)
{
    struct stat buffer;
    char **data_path = my_str_to_word_array_pwd(get_env("PATH",
        my_table_cpy(env)));
    int len = my_array_len(data_path);

    for (int i = 0; i < len; i++) {
        free(pwd);
        pwd = get_pwd_file(src, data_path[i], env);
        if (!(stat(pwd, &buffer) == -1)) {
            break;
        }
    }
    if (access(pwd, X_OK) == -1) {
        perror("errno");
        *cmds = 0;
        return 1;
    }
    free(pwd);
    *cmds = 2;
    return 1;
}

int check_commands(char *src, int *cmds, char **env)
{
    char *pwd = malloc(sizeof(char *) * 1);

    if (my_strlen(src) >= 2)
        if (check_own_cmd(src, cmds) == 1)
            return 1;
    if (check_internal_cmd(pwd, src, cmds, env) == 1)
        return 1;
    return 0;
}

static void set_function(char **data, commands_t **elements)
{
    if (my_strcmp(data[0], "cd") == 0)
        (*elements)->fct = main_cd;
    if (my_strcmp(data[0], "env") == 0)
        (*elements)->fct = main_env;
    if (my_strcmp(data[0], "setenv") == 0)
        (*elements)->fct = main_setenv;
    if (my_strcmp(data[0], "exit") == 0)
        (*elements)->fct = main_exit;
    return;
}

void check_correct_command(int *cmds, char **data, commands_t *commands,
    char **env)
{
    commands_t *elements = commands;

    *cmds = 0;
    if (!data)
        return;
    if (!data[0] || my_strcmp(data[0], "\n") == 0)
        return;
    while (elements) {
        if (my_strcmp(data[0], elements->name) == 0) {
            set_function(data, &elements);
            *cmds = 1;
            return;
        }
        elements = elements->next;
    }
    if (check_commands(data[0], cmds, env) == 1)
        return;
    *cmds = 0;
    write(2, "No commands found\n", 18);
    return;
}
