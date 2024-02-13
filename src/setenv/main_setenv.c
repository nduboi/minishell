/*
** EPITECH PROJECT, 2024
** setenv
** File description:
** main_setenv
*/

#include "minishell1.h"
#include "library.h"

char **my_table_cpy(char **src)
{
    char **result = NULL;
    int array_len = 0;

    if (src) {
        array_len = my_array_len(src);
        result = malloc(sizeof(char *) * (array_len + 1));
        for (int i = 0; i < array_len; i++) {
            result[i] = my_strdup(src[i]);
        }
        result[array_len] = NULL;
    }
    return result;
}

static void add_value_name_node(char *name, char *value, struct env_var *temp,
    struct env_var **env)
{
    struct env_var *elements;

    if (name && value) {
        elements = malloc(sizeof(env_var_t) * 1);
        elements->name = my_strdup(name);
        elements->value = my_strdup(value);
        elements->next = NULL;
        if (temp)
            temp->next = elements;
        else
            *env = elements;
    }
    return;
}

static void add_name_node(char *name, char *value, struct env_var *temp,
    struct env_var **env)
{
    struct env_var *elements;

    if (name && !value) {
        elements = malloc(sizeof(env_var_t) * 1);
        elements->name = my_strdup(name);
        elements->next = NULL;
        if (temp)
            temp->next = elements;
        else
            *env = elements;
    }
    return;
}

void add_node_env(struct env_var **env, char *name, char *value)
{
    struct env_var *temp = *env;

    if (temp)
        while (temp->next)
            temp = temp->next;
    add_value_name_node(name, value, temp, env);
    add_name_node(name, value, temp, env);
    return;
}

static void check_free_node(struct env_var *elements)
{
    if (elements->value)
        free(elements->value);
    return;
}

void modify_node_env(struct env_var **env, char *name, char *value)
{
    struct env_var *elements = *env;

    while (elements) {
        if (my_strcmp(elements->name, name) == 0) {
            check_free_node(elements);
            elements->value = my_strdup(value);
        }
        elements = elements->next;
    }
    return;
}

void add_value_in_env(char **av, struct env_var **env)
{
    if (get_line_env(av[1], *env) == -1) {
        add_node_env(env, av[1], av[2]);
    } else {
        modify_node_env(env, av[1], av[2]);
    }
    return;
}

static int parsing_src_is_alpha(char *src)
{
    if (!src)
        return 1;
    for (int i = 0; src[i]; i++) {
        if (!((src[i] >= 'A' && src[i] <= 'Z') ||
            (src[i] >= '0' && src[i] <= '9')))
            return 1;
    }
    return 0;
}

static int check_alphanum(int len, char **data)
{
    if (len == 2) {
        if (parsing_src_is_alpha(data[1]) == 1)
            return 1;
        return 0;
    }
    if (len == 3) {
        if (parsing_src_is_alpha(data[1]) == 1)
            return 1;
        if (parsing_src_is_alpha(data[2]) == 1)
            return 1;
        return 0;
    }
    if (len > 3)
        write(2, "setenv: Too many arguments.\n", 28);
    return 1;
}

int main_setenv(int ac, char **av, struct env_var **env)
{
    if (check_alphanum(ac, av) == 1) {
        write(2,
        "setenv: Variable name must contain alphanumeric characters.\n", 60);
        return 1;
    }
    if (ac == 3 && av[1] && av[2]) {
        add_value_in_env(av, env);
        return 0;
    }
    if (ac == 2 && av[1]) {
        add_value_in_env(av, env);
        return 0;
    }
    if (ac == 1)
        return 0;
    return 1;
}
