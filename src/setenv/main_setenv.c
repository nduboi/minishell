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

void add_node_env(struct env_var **env, char *name, char *value)
{
    struct env_var *elements;
    struct env_var *temp = *env;

    while (temp->next)
        temp = temp->next;
    if (name && value) {
        elements = malloc(sizeof(env_var_t) * 1);
        elements->name = my_strdup(name);
        elements->value = my_strdup(value);
        elements->next = NULL;
        temp->next = elements;
    }
    if (name && !value) {
        elements = malloc(sizeof(env_var_t) * 1);
        elements->name = my_strdup(name);
        elements->next = NULL;
        temp->next = elements;
    }
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

struct env_var *add_value_in_env(char **av, struct env_var *env)
{
    if (get_line_env(av[1], env) == -1) {
        add_node_env(&env, av[1], av[2]);
    } else {
        modify_node_env(&env, av[1], av[2]);
    }
    return env;
}

int main_setenv(int ac, char **av, struct env_var **env)
{
    if (ac == 3 && my_strcmp(av[0], "setenv") == 0 && (*env) &&
        av[1] && av[2]) {
        (*env) = add_value_in_env(av, (*env));
        return 0;
    }
    if (ac == 2 && my_strcmp(av[0], "setenv") == 0 && (*env) &&
        av[1]) {
        (*env) = add_value_in_env(av, (*env));
        return 0;
    }
    if (ac == 1) {
        print_env(*env);
        return 0;
    }
    return 84;
}
