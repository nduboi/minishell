/*
** EPITECH PROJECT, 2024
** check_if_is a correct command
** File description:
** check_command
*/

#include "minishell1.h"
#include "library.h"

int content_slash(char *src)
{
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] == '/')
            return 1;
    }
    return 0;
}

static int check_own_cmd(char *src, int *cmds)
{
    struct stat buffer;
    int cmd = 0;

    if (content_slash(src))
        if (!(stat(src, &buffer) == -1))
            cmd = 1;
    if (cmd == 1) {
        if (access(src, X_OK) == -1) {
            perror("errno");
            *cmds = 0;
            return 1;
        }
        *cmds = 2;
        return 0;
    }
    return 1;
}

static int check_error(int len)
{
    if (len == -1) {
        write(2, "Error with path environement variable\n", 38);
        return 1;
    }
    return 0;
}

static int check_acces(char *src, int *cmds)
{
    if (access(src, X_OK) == -1) {
        *cmds = 1;
        return 1;
    }
    return 0;
}

static int use_preset_path(char ***data_path)
{
    *data_path = my_str_to_word_array_pwd(
        "/usr/local/bin:/usr/bsd:/bin:/usr/bin");
    return my_array_len(*data_path);
}

static int check_internal_cmd(char *pwd, char *src, int *cmds, env_var_t *env)
{
    struct stat buffer;
    char **data_path = my_str_to_word_array_pwd(get_env("PATH", env));
    int len = my_array_len(data_path);

    if (!data_path)
        len = use_preset_path(&data_path);
    if (check_error(len) == 1)
        return 1;
    for (int i = 0; i < len; i++) {
        free(pwd);
        pwd = get_pwd_file(src, data_path[i], env);
        if (!(stat(pwd, &buffer) == -1)) {
            break;
        }
    }
    if (check_acces(pwd, cmds) == 1)
        return 1;
    free(pwd);
    *cmds = 2;
    return 0;
}

int check_commands(char *src, int *cmds, env_var_t *env)
{
    char *pwd = malloc(sizeof(char *) * 1);

    if (my_strlen(src) >= 2)
        if (check_own_cmd(src, cmds) == 0)
            return 0;
    if (check_internal_cmd(pwd, src, cmds, env) == 0)
        return 0;
    return 1;
}

static void set_function(char **data, commands_t **elements)
{
    if (my_strcmp(data[0], "cd") == 0)
        (*elements)->fct = main_cd;
    if (my_strcmp(data[0], "env") == 0)
        (*elements)->fct = main_env;
    if (my_strcmp(data[0], "setenv") == 0)
        (*elements)->fct = main_setenv;
    if (my_strcmp(data[0], "unsetenv") == 0)
        (*elements)->fct = main_unsetenv;
    if (my_strcmp(data[0], "exit") == 0)
        (*elements)->fct = main_exit;
    return;
}

static void write_error_cmd(char *src)
{
    write(2, src, my_strlen(src));
    write(2, ": Command not found.\n", 21);
    return;
}

int check_correct_command(char **data, commands_t *commands, env_var_t **env,
    env_var_t *cpy_env)
{
    commands_t *elements = commands;
    int cmds = 0;

    (void) cpy_env;
    if (!data)
        return cmds;
    if (!data[0] || my_strcmp(data[0], "\n") == 0)
        return cmds;
    while (elements) {
        if (my_strcmp(data[0], elements->name) == 0) {
            set_function(data, &elements);
            return 1;
        }
        elements = elements->next;
    }
    if (check_commands(data[0], &cmds, *env) == 1) {
        write_error_cmd(data[0]);
        return 84;
    }
    return cmds;
}
