/*
** EPITECH PROJECT, 2024
** start_command
** File description:
** start_comands
*/

#include "minishell1.h"
#include "library.h"

int execute_in_commands_struct(commands_t *commands, char **data, char **env)
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

int execution_process(char **data, int cmds, commands_t *commands, char **env)
{
    if (cmds == 2) {
        if (execve(get_pwd_file(data[0]), data, env) == -1 &&
            execve(data[0], data, env) == -1) {
            perror("execve");
            return 1;
        }
    } else {
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

int start_commands(char **data, int cmds, commands_t *commands, char **env)
{
    pid_t pid = fork();

    if (cmds == 2 || cmds == 1) {
        if (pid == -1)
            error_pid();
        if (pid == 0) {
            execution_process(data, cmds, commands, env);
        } else {
            wait_pid_fork(pid);
        }
    }
    return 0;
}
