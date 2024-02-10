/*
** EPITECH PROJECT, 2023
** array len
** File description:
** my_array_len
*/

#include "../includes/library.h"

int my_array_len(char **av)
{
    int i;

    for (i = 0; av[i]; i++);
    return i;
}
