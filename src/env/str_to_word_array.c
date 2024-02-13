/*
** EPITECH PROJECT, 2024
** strtowordarray
** File description:
** str_to_word_array
*/

#include "minishell1.h"
#include "library.h"

static int get_nbr_argv(char *src, const char *separator)
{
    int count = 0;
    char *str_token = NULL;

    str_token = strtok(src, separator);
    for (count = 0; str_token != NULL; count ++) {
        str_token = strtok(NULL, separator);
    }
    free(src);
    return count;
}

static char **word_array_argv(char *src, int count, const char *separator)
{
    char *str_token = NULL;
    char **result = malloc(sizeof(char *) * (count + 1));

    str_token = strtok(src, separator);
    for (count = 0; str_token != NULL; count++) {
        result[count] = str_token;
        str_token = strtok(NULL, separator);
    }
    result[count] = NULL;
    return result;
}

char **str_to_word_array(char *src, const char *separator)
{
    char **result = NULL;
    int count = 0;
    char *src_cpy = my_str_cpy(src);
    char *src_cpy2 = my_str_cpy(src);

    if (!src)
        return NULL;
    count = get_nbr_argv(src_cpy, separator);
    result = word_array_argv(src_cpy2, count, separator);
    return result;
}
