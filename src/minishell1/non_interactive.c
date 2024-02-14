/*
** EPITECH PROJECT, 2024
** non interactiv
** File description:
** non_interactive
*/

#include "minishell1.h"
#include "library.h"

static int execute_action(char *str, char **data, commands_t *commands,
    env_var_t *env)
{
    int cmds = 0;

    data = my_str_to_word_array(str);
    check_correct_command(&cmds, data, commands, env);
    if (cmds != 0 && cmds != 84)
        return start_commands(data, cmds, commands, &env);
    return cmds;
}

static void wait_input_user(int read, commands_t *commands, int *cmds,
    env_var_t *env)
{
    char *str = NULL;
    char **data = NULL;
    size_t len;

    *cmds = 0;
    if (isatty(STDIN_FILENO))
        write(1, "$> ", 3);
    read = getline(&str, &len, stdin);
    str[my_strlen(str) - 1] = '\0';
    while (read != -1) {
        if (my_strlen(str) == 0 || *cmds == 1)
            break;
        *cmds = execute_action(str, data, commands, env);
        if (isatty(STDIN_FILENO))
            write(1, "$> ", 3);
        read = getline(&str, &len, stdin);
        str[my_strlen(str) - 1] = '\0';
    }
}

int non_interactive(env_var_t *env)
{
    int read = 0;
    int cmds = 0;
    commands_t *commands = NULL;

    fill_struct(&commands);
    wait_input_user(read, commands, &cmds, env);
    if (cmds == 84)
        return 1;
    return cmds;
}
