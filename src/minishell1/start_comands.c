/*
** EPITECH PROJECT, 2024
** start_command
** File description:
** start_comands
*/

#include "minishell1.h"
#include "library.h"

int execution_process(char **data)
{
    char *env[] = {"PATH=/bin:/usr/bin", NULL};

    if (execve(get_pwd_file(data[0]), data, env) == -1 &&
        execve(data[0], data, env) == -1) {
        perror("execve");
        return 1;
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

int start_commands(char **data, int cmds, commands_t *commands)
{
    pid_t pid = fork();

    if (commands)
        commands = NULL;
    if (cmds == 2) {
        if (pid == -1)
            error_pid();
        if (pid == 0) {
            execution_process(data);
        } else {
            wait_pid_fork(pid);
        }
    }
    return 0;
}
