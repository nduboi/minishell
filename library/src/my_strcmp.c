/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** Write a function that displays,
** one-by-one, the characters of a string.
*/

#include "../includes/library.h"

int my_strcmp(const char *first, const char *second)
{
    if (!first || !second)
        return -1;
    if (my_strlen(first) != my_strlen(second))
        return -1;
    for (int i = 0; first[i]; i++) {
        if (first[i] != second[i])
            return first[i] - second[i];
    }
    return 0;
}
