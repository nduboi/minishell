/*
** EPITECH PROJECT, 2024
** non interactiv
** File description:
** non_interactive
*/

#include "minishell1.h"
#include "library.h"

static int execute_action(char *str, commands_t *commands,
    env_var_t **env, env_var_t *cpy_env)
{
    int cmds = 0;
    char **data = NULL;

    data = str_to_word_array(str, " \t");
    cmds = check_correct_command(data, commands, env, cpy_env);
    if (cmds == 1)
        return buildinprgm(data, commands, env, cpy_env);
    if (cmds == 2)
        return native_prgrm(data, env);
    return cmds;
}

static int get_input(char **str, size_t *len)
{
    int read = 0;

    if (isatty(STDIN_FILENO))
        write(1, "$> ", 3);
    read = getline(str, len, stdin);
    (*str)[my_strlen(*str) - 1] = '\0';
    return read;
}

static void wait_input_user(int read, int *cmds,
    env_var_t **env, env_var_t *cpy_env)
{
    char *str = NULL;
    size_t len;
    commands_t *commands = NULL;

    fill_struct(&commands);
    *cmds = 0;
    read = get_input(&str, &len);
    while (read != -1) {
        if (my_strlen(str) == 0 || (isatty(STDIN_FILENO) == 0 && *cmds == 1))
            break;
        *cmds = execute_action(str, commands, env, cpy_env);
        read = get_input(&str, &len);
    }
    if (isatty(STDIN_FILENO))
        my_putstr("exit\n");
}

int non_interactive(env_var_t *env, env_var_t *cpy_env)
{
    int read = 0;
    int cmds = 0;

    wait_input_user(read, &cmds, &env, cpy_env);
    if (cmds == 84)
        return 1;
    return cmds;
}
