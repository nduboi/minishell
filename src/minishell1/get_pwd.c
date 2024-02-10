/*
** EPITECH PROJECT, 2024
** get_pwdfile
** File description:
** get_pwd
*/

#include "minishell1.h"
#include "library.h"

char *get_pwd_file(char *src)
{
    char *base = my_strdup("/bin/");
    int len = my_strlen(src);
    int lenbase = my_strlen(base);
    char *result = malloc(sizeof(char) * (lenbase + len + 1));

    for (int i = 0; i <= lenbase; i++) {
        result[i] = base[i];
    }
    for (int i = 0; i <= len; i++) {
        result[lenbase + i] = src[i];
    }
    return result;
}
