/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Write a function that displays,
** one-by-one, the characters of a string.
*/

#include "../includes/library.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}

int my_puterror(char const *str)
{
    write(2, str, my_strlen(str));
    return 0;
}
