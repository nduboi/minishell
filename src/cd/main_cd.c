/*
** EPITECH PROJECT, 2024
** main cd
** File description:
** main_cd
*/

#include "minishell1.h"
#include "library.h"

static int go_folder(char *src, struct env_var **env)
{
    char *buffer = malloc(sizeof(char) * (BUFFER_SIZE));
    char **env_variables = fill_env_variables_oldpwd();

    getcwd(buffer, (BUFFER_SIZE));
    env_variables[2] = buffer;
    if (opendir(src) == NULL) {
        write(2, src, my_strlen(src));
        write(2, ": No such file or directory.\n", 29);
        return 1;
    } else {
        if (chdir(src) == -1) {
            write(2, src, my_strlen(src));
            write(2, ": No such file or directory.\n", 29);
            return 1;
        }
        add_value_in_env(env_variables, env);
    }
    return 0;
}

int specific_cases(char **av, struct env_var **env)
{
    if (my_strcmp(av[1], "~") == 0) {
        return go_folder(get_env("HOME", (*env)), env);
    }
    if (my_strcmp(av[1], "-") == 0) {
        return go_folder(get_env("OLDPWD", (*env)), env);
    }
    return 1;
}

int main_cd(int ac, char **av, struct env_var **env)
{
    if (ac == 1) {
        return go_folder(get_env("HOME", (*env)), env);
    }
    if (ac == 2) {
        if (my_strcmp(av[1], "~") != 0 && my_strcmp(av[1], "-") != 0) {
            return go_folder(av[1], env);
        } else
            return specific_cases(av, env);
    } else
        return 1;
    return 0;
}
