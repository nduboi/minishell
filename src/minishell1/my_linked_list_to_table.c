/*
** EPITECH PROJECT, 2024
** my_linked_list_to_table
** File description:
** my_linked_list_to_table
*/

#include "minishell1.h"
#include "library.h"

int len_linked_list(env_var_t *env)
{
    int len = 0;
    env_var_t *element = env;

    for (; element; len++)
        element = element->next;
    return len;
}

static void fill_char_with_name_value(char *name, char *value, char **result)
{
    int len_name;
    int len_value;
    int i = 0;

    if (name && value) {
        len_name = my_strlen(name);
        len_value = my_strlen(value);
        (*result) = malloc(sizeof(char) * (len_name + len_value + 2));
        (*result)[len_name + len_value + 1] = '\0';
        for (; i < len_name; i++)
            (*result)[i] = name[i];
        (*result)[i] = '=';
        for (i = 0; i < len_value; i++)
            (*result)[i + len_name + 1] = value[i];
    }
    return;
}

static void fill_char_with_name(char *name, char *value, char **result)
{
    int len_name = 0;
    int len_value = 0;
    int i = 0;

    if (name && !value) {
        len_name = my_strlen(name);
        (*result) = malloc(sizeof(char) * (len_name + 2));
        (*result)[len_name + len_value + 1] = '\0';
        for (; i < len_name; i++)
            (*result)[i] = name[i];
        (*result)[i] = '=';
    }
    return;
}

char *name_equal_value(char *name, char *value)
{
    char *result = NULL;

    fill_char_with_name_value(name, value, &result);
    fill_char_with_name(name, value, &result);
    return result;
}

char **my_linked_list_to_table(env_var_t *env)
{
    char **result = NULL;
    int len = len_linked_list(env);
    env_var_t *element = env;

    if (!(len > 0))
        return NULL;
    result = malloc(sizeof(char *) * (len + 1));
    result[len] = NULL;
    for (int i = 0; element; i++) {
        result[i] = name_equal_value(element->name, element->value);
        element = element->next;
    }
    return result;
}
