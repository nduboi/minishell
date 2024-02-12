/*
** EPITECH PROJECT, 2024
** start_command
** File description:
** start_comands
*/

#include "minishell1.h"
#include "library.h"

int execute_in_commands_struct(commands_t *commands, char **data, char ***env)
{
    commands_t *elements = commands;

    while (elements) {
        if (my_strcmp(data[0], elements->name) == 0) {
            (elements->fct(my_array_len(data), data, env));
            return 0;
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

    for (int i = 0; i < len_array; i++) {
        execve(get_pwd_file(data[0], data_path[i], (*env)), data, (*env));
    }
    return 0;
}

int execution_process(char **data, int cmds, commands_t *commands, char ***env)
{
    if (cmds == 2) {
        execute_env_path(data, env);
    } else if (cmds == 1) {
        execute_in_commands_struct(commands, data, env);
    }
    return 0;
}

static void error_pid(void)
{
    perror("fork");
    exit(1);
}

static int wait_pid_fork(pid_t pid)
{
    int status;

    if (waitpid(pid, &status, 0) == -1) {
        perror("waitpid");
        exit(1);
    }
    return status;
}

int start_commands(char **data, int cmds, commands_t *commands, char ***env)
{
    pid_t pid;

    if (cmds == 2) {
        pid = fork();
        if (pid == -1)
            error_pid();
        if (pid == 0) {
            execution_process(data, cmds, commands, env);
        } else {
            wait_pid_fork(pid);
        }
    }
    if (cmds == 1)
        execution_process(data, cmds, commands, env);
    return 0;
}
