/*
** EPITECH PROJECT, 2024
** main cd
** File description:
** main_cd
*/

#include "minishell1.h"
#include "library.h"

static void set_value_old_pwd(char **OLD_variables, char **PWD_variables,
    struct env_var **env)
{
    add_value_in_env(OLD_variables, env);
    add_value_in_env(PWD_variables, env);
    free(OLD_variables);
    free(PWD_variables);
}

static int handle_error(char *src, int home)
{
    if (!src && home != 1) {
        write(2, ": No such file or directory.\n", 29);
        return 1;
    }
    if (!src && home == 1) {
        write(2, "cd: No home directory.\n", 23);
        return 1;
    }
    if (opendir(src) == NULL && home != 1) {
        write(2, src, my_strlen(src));
        write(2, ": No such file or directory.\n", 29);
        return 1;
    }
        if (opendir(src) == NULL && home == 1) {
        write(2, "cd: Can't change to home directory.\n", 36);
        return 1;
    }
    return 0;
}

static int go_folder(char *src, struct env_var **env, int home)
{
    char *buffer = malloc(sizeof(char) * (BUFFER_SIZE));
    char **OLD_variables = fill_env_variables_oldpwd();
    char **PWD_variables = fill_env_variables_pwd();

    if (handle_error(src, home) == 1)
        return 1;
    getcwd(buffer, (BUFFER_SIZE));
    if (buffer)
        OLD_variables[2] = my_strdup(buffer);
    chdir(src);
    getcwd(buffer, (BUFFER_SIZE));
    if (buffer)
        PWD_variables[2] = my_strdup(buffer);
    set_value_old_pwd(OLD_variables, PWD_variables, env);
    return 0;
}

int specific_cases(char **av, struct env_var **env)
{
    if (my_strcmp(av[1], "~") == 0)
        return go_folder(get_env("HOME", (*env)), env, 1);
    if (my_strcmp(av[1], "-") == 0)
        return go_folder(get_env("1OLDPWD", (*env)), env, 0);
    return 1;
}

int main_cd(int ac, char **av, struct env_var **env)
{
    if (ac == 1) {
        return go_folder(get_env("HOME", (*env)), env, 1);
    }
    if (ac == 2) {
        if (my_strcmp(av[1], "~") != 0 && my_strcmp(av[1], "-") != 0) {
            return go_folder(av[1], env, 0);
        } else
            return specific_cases(av, env);
    } else
        return 1;
    return 0;
}
