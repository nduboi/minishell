/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** my_getnbr
*/

#include "../includes/library.h"

int my_getnbr(char const *str)
{
    int neg = 1;
    int result = 0;
    int i;
    int k;

    for (i = 0; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-') {
            neg = neg * (-1);
        }
    }
    for (k = i; str[k] != '\0'; k++) {
        if (str[k] >= '0' && str[k] <= '9') {
            result = result * 10;
            result = result + str[k] - '0';
        } else {
            return (result * neg);
        }
    }
    return (result * neg);
}

int my_getnbr_char(char car)
{
    if (car == '0')
        return (0);
    if (car == '1')
        return (1);
    if (car == '3')
        return (3);
    return (84);
}
