/*
** EPITECH PROJECT, 2024
** fill env
** File description:
** fill_env
*/

#include "minishell1.h"
#include "library.h"

static void add_equal(char **result, int actual, int len_max)
{
    if (len_max >= actual + 2) {
        (*result)[actual] = '=';
        (*result)[actual + 1] = '\0';
    } else
        (*result)[actual] = '\0';
    return;
}

static void strcat_equal(char **result, char *src, int len_max)
{
    int len = 0;
    int len_src = 0;
    int i = 0;
    int k = 0;

    if (!src || !(*result))
        return;
    len = my_strlen(*result);
    len_src = my_strlen(src);
    for (i = 0; i < len_src; i++) {
        (*result)[k + len] = src[i];
        k++;
    }
    add_equal(result, k + len, len_max);
}

static char *add_all(char **data)
{
    int array_len;
    char *result = NULL;
    int len_src = 0;

    if (!data)
        return result;
    array_len = my_array_len(data);
    for (int i = 0; data[i]; i++)
        len_src += my_strlen(data[i]);
    if (!(len_src > 0))
        return NULL;
    result = malloc(sizeof(char) * (len_src + (array_len - 1) + 1));
    result[0] = '\0';
    for (int i = 0; data[i]; i++)
        strcat_equal(&result, data[i], (len_src + (array_len - 1)));
    return result;
}

static void add_name_value(int len_array, env_var_t **element,
    char **table_data)
{
    if (my_strcmp(table_data[0], "SHLVL") != 0 && len_array == 2) {
        (*element)->name = my_strdup(table_data[0]);
        (*element)->value = my_strdup(table_data[1]);
    }
    if (my_strcmp(table_data[0], "SHLVL") != 0 && len_array > 2) {
        (*element)->name = my_strdup(table_data[0]);
        (*element)->value = add_all(&table_data[1]);
    }
    if (my_strcmp(table_data[0], "SHLVL") == 0) {
        if (len_array == 2) {
            ((*element)->name) = my_strdup(table_data[0]);
            ((*element)->value) = my_stock_nbr(my_getnbr(table_data[1]) + 1);
        } else {
            (*element)->name = my_strdup(table_data[0]);
            (*element)->value = my_stock_nbr(1);
        }
    }
    return;
}

static void add_name(int len_array, env_var_t **element,
    char **table_data)
{
    if (len_array == 1)
        (*element)->name = my_strdup(table_data[0]);
    return;
}

static void add_value_in_struct(char *src, env_var_t **env_struct)
{
    char **table_data;
    env_var_t *element;
    int len_array = 0;

    if (!src)
        return;
    table_data = str_to_word_array(src, "=");
    if (table_data) {
        element = malloc(sizeof(env_var_t) * 1);
        element->value = NULL;
        len_array = my_array_len(table_data);
        add_name_value(len_array, &element, table_data);
        add_name(len_array, &element, table_data);
        element->next = (*env_struct);
        *env_struct = element;
    }
    return;
}

char **fill_path_var(void)
{
    char **result = malloc(sizeof(char *) * 4);
    char *buffer = malloc(sizeof(char) * BUFFER_SIZE);

    result[0] = NULL;
    result[1] = my_strdup("PWD");
    if (getcwd(buffer, BUFFER_SIZE) == NULL) {
        perror("gercwd");
        return NULL;
    }
    result[2] = my_strdup(buffer);
    return result;
}

static env_var_t *fill_with_minimum_info(env_var_t *pos)
{
    char **data = get_content_file("/etc/hostname");

    if (data)
        add_node_env_struct(my_strdup("HOST"), data[0], &pos);
    add_node_env_struct(my_strdup("PWD"), (fill_path_var())[2], &pos);
    add_node_env_struct(my_strdup("SHLVL"), my_stock_nbr(1), &pos);
    return pos;
}

env_var_t *fill_environement(char **env)
{
    env_var_t *env_struct = NULL;
    int len = 0;
    char **pwd_var = fill_path_var();

    if (!env)
        return fill_with_minimum_info(env_struct);
    len = my_array_len(env);
    if (len == 0)
        return fill_with_minimum_info(env_struct);
    for (int i = (len - 1); i >= 0; i--) {
        add_value_in_struct(env[i], &env_struct);
    }
    add_value_in_env(pwd_var, &env_struct);
    return env_struct;
}
