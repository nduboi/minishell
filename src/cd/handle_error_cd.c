/*
** EPITECH PROJECT, 2024
** handle error cd
** File description:
** handle_error
*/

#include "minishell1.h"
#include "library.h"

static int check_preset_folder_old_env(char **src,
    env_var_t *cpy_env)
{
    *src = get_env("HOME", cpy_env);
    if (!*src)
        return 1;
    if (opendir(*src) != NULL)
        return 0;
    return 1;
}

static int is_home_accessible(char **src, int home)
{
    if (opendir(*src) == NULL && home == 1) {
        write(2, "cd: Can't change to home directory.\n", 36);
        return 1;
    }
    return 0;
}

static int check_size_src(char *src)
{
    int len;

    if (!src)
        return 1;
    len = my_strlen(src);
    if (len >= 256) {
        write(2, src, my_strlen(src));
        write(2, ": File name too long.\n", 22);
        return 1;
    }
    return 0;
}

static int check_folder_accessible(char *src, int home)
{
    if (opendir(src) == NULL && home != 1) {
        write(2, src, my_strlen(src));
        write(2, ": No such file or directory.\n", 29);
        return 1;
    }
    return 0;
}

static int check_if_home_env(char **src, int home, env_var_t *cpy_env)
{
    if (!(*src) && home == 1) {
        if (check_preset_folder_old_env(src, cpy_env) == 1) {
            write(2, "cd: No home directory.\n", 23);
            return 1;
        } else
            return 0;
    }
    return 0;
}

int handle_error(char **src, int home, env_var_t *cpy_env)
{
    if (!(*src) && home != 1) {
        write(2, ": No such file or directory.\n", 29);
        return 1;
    }
    if (check_if_home_env(src, home, cpy_env) == 1)
        return 1;
    if (check_size_src(*src) == 1)
        return 1;
    if (check_folder_accessible(*src, home) == 1)
        return 1;
    if (is_home_accessible(src, home) == 1)
        return 1;
    return 0;
}
