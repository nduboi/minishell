/*
** EPITECH PROJECT, 2024
** no interactive start commands
** File description:
** start_comands_no_interactive
*/

#include "minishell1.h"
#include "library.h"

static int execute_in_commands_struct(commands_t *commands,
    char **data, char ***env)
{
    commands_t *elements = commands;

    while (elements) {
        if (my_strcmp(data[0], elements->name) == 0) {
            exit(elements->fct(my_array_len(data), data, env));
        }
        elements = elements->next;
    }
    return 1;
}

static int execute_env_path(char **data, char ***env)
{
    char **data_path = my_str_to_word_array_pwd(get_env("PATH",
        my_table_cpy(*env)));
    int len_array = my_array_len(data_path);

    if (my_strlen(data[0]) > 2) {
        if (data[0][0] == '.' && data[0][1] == '/') {
            execve(data[0], data, (*env));
            return 0;
        }
    }
    for (int i = 0; i < len_array; i++) {
        execve(get_pwd_file(data[0], data_path[i], (*env)), data, (*env));
    }
    return 0;
}

static int execution_process_non_interactive(char **data, int cmds,
    commands_t *commands, char ***env)
{
    if (cmds == 2)
        execute_env_path(data, env);
    else if (cmds == 1)
        execute_in_commands_struct(commands, data, env);
    return 0;
}

int start_commands_non_interactive(char **data, int cmds, commands_t *commands,
    char ***env)
{
    if (cmds == 2 || cmds == 1)
        execution_process_non_interactive(data, cmds, commands, env);
    return 0;
}
