/*
** EPITECH PROJECT, 2024
** start_command
** File description:
** start_comands
*/

#include "minishell1.h"
#include "library.h"
#include <signal.h>

static void check_core_dump(int status)
{
    if (WIFSIGNALED(status)) {
        if (136 == status)
            write(2, "Floating exception (core dumped)\n", 33);
        if (139 == status)
            write(2, "Segmentation fault (core dumped)\n", 33);
        if (134 == status)
        write(2, "Abort (core dumped)\n", 20);
    }
}

int execute_in_commands_struct(commands_t *commands, char **data,
    env_var_t **env)
{
    commands_t *elements = commands;

    while (elements) {
        if (my_strcmp(data[0], elements->name) == 0) {
            return (elements->fct(my_array_len(data), data, env));
        }
        elements = elements->next;
    }
    return 1;
}

static void use_preset_path(char ***data_path)
{
    *data_path = my_str_to_word_array_pwd(
        "/usr/local/bin:/usr/bsd:/bin:/usr/bin");
}

static int execute_env_path(char **data, env_var_t **env)
{
    char **data_path = my_str_to_word_array_pwd(get_env("PATH",
        (*env)));
    int len_array;
    char **env_table = my_linked_list_to_table(*env);

    if (!data_path)
        use_preset_path(&data_path);
    len_array = my_array_len(data_path);
    if (my_strlen(data[0]) > 2) {
        if (content_slash(data[0]) == 1) {
            execve(data[0], data, env_table);
            return 0;
        }
    }
    for (int i = 0; i < len_array; i++) {
        execve(get_pwd_file(data[0], data_path[i], (*env)), data, env_table);
    }
    return 0;
}

int execution_process(char **data, int cmds, commands_t *commands,
    env_var_t **env)
{
    int status = 0;

    if (cmds == 2)
        status = execute_env_path(data, env);
    else if (cmds == 1) {
        status = execute_in_commands_struct(commands, data, env);
    }
    return status;
}

static void error_pid(void)
{
    perror("fork");
    exit(1);
}

static int wait_pid_fork(pid_t pid)
{
    int status = 0;

    if (waitpid(pid, &status, WUNTRACED | WCONTINUED) == -1) {
        perror("waitpid");
        exit(84);
    }
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    return status;
}

int start_commands(char **data, int cmds, commands_t *commands,
    env_var_t **env)
{
    pid_t pid;
    int status;

    if (cmds == 2) {
        pid = fork();
        if (pid == -1)
            error_pid();
        if (pid == 0)
            execution_process(data, cmds, commands, env);
        else {
            status = wait_pid_fork(pid);
            check_core_dump(status);
        }
    }
    if (cmds == 1)
        status = execution_process(data, cmds, commands, env);
    return status;
}
