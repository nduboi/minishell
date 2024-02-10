/*
** EPITECH PROJECT, 2023
** strdup
** File description:
** strdup
*/

#include "../includes/library.h"

char *my_strdup(char *src)
{
    int len = my_strlen(src) + 1;
    char *result = malloc(sizeof(char) * (len + 1));
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        result[i] = src[i];
    }
    result[i] = '\0';
    return result;
}
