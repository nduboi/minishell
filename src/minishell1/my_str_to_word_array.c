/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** Write a function that splits a string into words.
*/
#include <stdlib.h>
#include <stdio.h>

#include "library.h"
#include <unistd.h>

static int is_alphanum(char const str)
{
    if (str == ' ' || str == '\0') {
        return 1;
    }
    return 0;
}

static char *copy_line(int last_char, int first_char, const char *str, int *k)
{
    char *result;

    result = malloc(sizeof(char) * (((last_char + 1) - first_char) + 1));
    for (int i = first_char; i <= last_char; i++) {
        result[*k] = str[i];
        *k = *k + 1;
    }
    return result;
}

static char *catch_to_array(int first_char, int last_char, char const *str)
{
    int k = 0;
    char *result;

    if (first_char == 0) {
        if (first_char == 0 && last_char == -1) {
            result = malloc(sizeof(char) * (2));
            result[k] = str[0];
            k++;
        } else {
            result = copy_line(last_char, first_char, str, &k);
        }
    } else {
        result = malloc(sizeof(char) * ((last_char - first_char) + 1));
        for (int i = first_char + 1; i <= last_char; i++) {
            result[k] = str[i];
            k++;
        }
    }
    result[k] = '\0';
    return result;
}

static char **send_to_the_array(char **result, char *str_result, int j)
{
    int i;

    for (i = 0; str_result[i] != '\0'; i++) {
        result[j][i] = str_result[i];
    }
    result[j][i] = '\0';
    return result;
}

static int how_many_array(char const *str)
{
    int n = 0;
    int j = 0;
    int len_str = my_strlen(str);

    for (int i = 0; i < len_str; i++) {
        if (is_alphanum(str[i]) == 1 && n > 1) {
            j++;
        }
        if (is_alphanum(str[i]) == 1) {
            n = 0;
        }
        n++;
    }
    return (j + 1);
}

static void check_if_new_line(char const *str, int i, int *n)
{
    if (is_alphanum(str[i]) == 1)
        *n = 0;
    *n = *n + 1;
}

static void put_in_array(char ***result, char const *str, int *j, int *tab)
{
    char *str_result;

    (*result)[*j] = malloc(sizeof(char) * ((tab[0] - 1) -
        (tab[0] -tab[1]) + 2));
    str_result = catch_to_array((tab[0] - tab[1]), (tab[0] - 1), str);
    *result = send_to_the_array(*result, str_result, *j);
    *j = *j + 1;
}

static int check_body_str(const char *str, int **tab, int *j, char ***result)
{
    int len_str = my_strlen(str);
    int n = (*tab)[1];

    if ((is_alphanum(str[(*tab)[0]]) == 1 && (*tab)[1] > 1) ||
        (is_alphanum(str[(*tab)[0]]) == 0 && len_str == 1)) {
        put_in_array(result, str, j, *tab);
    }
    check_if_new_line(str, (*tab)[0], &n);
    return n;
}

char **my_str_to_word_array(char const *str)
{
    char **result = {0};
    int n = 0;
    int j = 0;
    int i;
    int *tab = malloc(sizeof(int) * 3);

    result = malloc(sizeof(char *) * (how_many_array(str) + 1));
    for (i = 0; str[i] != '\0'; i++) {
        tab = (int[]){i, n};
        n = check_body_str(str, &tab, &j, &result);
    }
    if ((is_alphanum(str[i]) == 1 && n > 1)) {
        tab = (int[]){i, n};
        put_in_array(&result, str, &j, tab);
    }
    result[j] = NULL;
    return result;
}
