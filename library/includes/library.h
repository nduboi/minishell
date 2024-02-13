/*
** EPITECH PROJECT, 2024
** files includes
** File description:
** my
*/

#include <unistd.h>
#include <stdlib.h>

#ifndef MY_H_
    #define MY_H_

int my_array_len(char **av);
int my_getnbr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_puterror(char const *str);
int my_strcmp(const char *first, const char *second);
char *my_strdup(char *src);
int my_strlen(char const *str);

#endif /* !MY_H_ */
