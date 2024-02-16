/*
** EPITECH PROJECT, 2024
** non interactiv
** File description:
** non_interactive
*/

#include "minishell1.h"
#include "library.h"

static char *try_all_env(char *src, env_var_t *env)
{
    char *result = NULL;

    result = get_env(src, env);
    if (!result) {
        write(2, src, my_strlen(src));
        write(2, ": Undefined variable.\n", 22);
        return NULL;
    }
    return result;
}

static char *replace_char_dllr_with_env(char *src, env_var_t *env)
{
    char *result_env = NULL;

    if (src[0] == '$' && src[1] != '?') {
        result_env = try_all_env(&(src)[1], env);
        if (!result_env)
            return NULL;
        return result_env;
    }
    return src;
}

static int check_dllr_envi(char **src, env_var_t *env,
    int last_return_value)
{
    int len = 0;

    if (!(*src))
        return 1;
    len = my_strlen(*src);
    if (len >= 2) {
        *src = replace_char_dllr_with_env(*src, env);
        if (!(*src))
            return 1;
        if ((*src)[0] == '$' && (*src)[1] == '?' && len == 2)
            *src = my_stock_nbr(last_return_value);
        return 0;
    }
    return 0;
}

static int parse_result(char ***data, env_var_t *env,
    int last_return_value)
{
    int len = 0;

    if (!*data)
        return 1;
    len = my_array_len(*data);
    for (int i = 0; i < len; i++) {
        if (check_dllr_envi(&((*data)[i]), env, last_return_value)
            == 1) {
                return 1;
        }
    }
    return 0;
}

static char **convert_input_check_var_envi(char *src,
    env_var_t *env, int *last_return_value)
{
    char **result = NULL;

    result = str_to_word_array(src, " \t");
    if (parse_result(&result, env, *last_return_value) == 1) {
        *last_return_value = 1;
        return NULL;
    }
    *last_return_value = 0;
    return result;
}

static int execute_action(char **data, commands_t *commands,
    env_var_t **env, env_var_t *cpy_env)
{
    int cmds = 0;

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
    char **data = NULL;

    fill_struct(&commands);
    *cmds = 0;
    read = get_input(&str, &len);
    while (read != -1) {
        if (my_strlen(str) == 0 || (isatty(STDIN_FILENO) == 0 && *cmds == 1))
            break;
        data = convert_input_check_var_envi(str, *env, cmds);
        if (data)
            *cmds = execute_action(data, commands, env, cpy_env);
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
