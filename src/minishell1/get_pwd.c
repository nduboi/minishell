/*
** EPITECH PROJECT, 2024
** get_pwdfile
** File description:
** get_pwd
*/

#include "minishell1.h"
#include "library.h"

char *replace_title_by_homedirectory(char *src, char *home)
{
    char *result = NULL;
    int len_home;
    int len_src;

    if (src && home) {
        free(result);
        len_home = my_strlen(home);
        len_src = my_strlen(src);
        result = malloc(sizeof(char) * (len_home + (len_src - 1) + 1));
        for (int i = 0; i < len_home; i++) {
            result[i] = home[i];
        }
        for (int i = 1; i <= len_src; i++) {
            result[i + len_home - 1] = src[i];
        }
    }
    if (!result)
        return src;
    return result;
}

char *check_for_home_dir(char *path, env_var_t *env)
{
    char *base = NULL;

    if (my_strlen(path) >= 1) {
        if (path[0] == '~')
            base = replace_title_by_homedirectory(path, get_env("HOME",
                env));
        else
            base = path;
    }
    return base;
}

char *get_pwd_file(char *src, char *path, env_var_t *env)
{
    char *base;
    int len;
    int lenbase;
    char *result;

    if (!src || !path)
        return NULL;
    len = my_strlen(src);
    base = check_for_home_dir(path, env);
    lenbase = my_strlen(base);
    result = malloc(sizeof(char) * (lenbase + len + 2));
    for (int i = 0; i < lenbase; i++) {
        result[i] = base[i];
    }
    result[lenbase] = '/';
    for (int i = 0; i <= len; i++) {
        result[lenbase + i + 1] = src[i];
    }
    result[lenbase + len + 1] = '\0';
    return result;
}

char *str_cat_pwd(char *path_1, char *path_2)
{
    char *result = NULL;
    int len1 = 0;
    int len2 = 0;
    int i = 0;

    if (!path_1 || !path_2)
        return result;
    len1 = my_strlen(path_1);
    len2 = my_strlen(path_2);
    result = malloc(sizeof(char) * (len1 + len2 + 2));
    for (; i < len1; i++) {
        result[i] = path_1[i];
    }
    result[i] = '/';
    for (i = 0; i <= len2; i++) {
        result[len1 + i + 1] = path_2[i];
    }
    return result;
}
