/*
** EPITECH PROJECT, 2024
** my_str_cpy
** File description:
** my_str_copy
*/

#include "minishell1.h"
#include "library.h"

char *my_str_cpy(char *src)
{
    int len;
    char *result;

    if (!src)
        return NULL;
    len = my_strlen(src);
    result = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i <= len; i++) {
        result[i] = src[i];
    }
    return result;
}
