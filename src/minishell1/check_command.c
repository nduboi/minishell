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

static int check_file(char *src, int *cmd)
{
    struct stat buffer;

    if (!(stat(src, &buffer) == -1)) {
        if (S_ISREG(buffer.st_mode))
            *cmd = 1;
        else
            return 2;
    }
    return 0;
}

static int check_own_cmd(char *src, int *cmds)
{
    int cmd = 0;

    if (content_slash(src)) {
        if (check_file(src, &cmd) == 2)
            return 2;
    }
    if (cmd == 1) {
        if (access(src, X_OK) == -1) {
            *cmds = 0;
            return 2;
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
    int status = 0;

    if (my_strlen(src) >= 2) {
        status = check_own_cmd(src, cmds);
        if (status == 0)
            return 0;
        if (status == 2)
            return 2;
    }
    if (check_internal_cmd(pwd, src, cmds, env) == 0)
        return 0;
    return 1;
}

static void write_error_cmd(char *src, int status_error)
{
    if (status_error == 1) {
        write(2, src, my_strlen(src));
        write(2, ": Command not found.\n", 21);
        return;
    }
    if (status_error == 2) {
        write(2, src, my_strlen(src));
        write(2, ": Permission denied.\n", 21);
        return;
    }
    return;
}

int check_correct_command(char **data, commands_t *commands, env_var_t **env,
    env_var_t *cpy_env)
{
    commands_t *elements = commands;
    int cmds = 0;
    int status_check = 0;

    (void) cpy_env;
    if (!data)
        return cmds;
    if (!data[0] || my_strcmp(data[0], "\n") == 0)
        return cmds;
    if (check_if_is_a_buildintcmd(data, &elements) == 1)
        return 1;
    status_check = check_commands(data[0], &cmds, *env);
    if (status_check != 0) {
        write_error_cmd(data[0], status_check);
        return 84;
    }
    return cmds;
}
