/*
** EPITECH PROJECT, 2024
** delete fct
** File description:
** delete
*/

#include "minishell1.h"
#include "library.h"

void delete_node(env_var_t **pos, char *src)
{
    env_var_t *temp = *pos;
    env_var_t *prev = NULL;

    if (temp != NULL && my_strcmp(temp->name, src) == 0) {
        *pos = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && my_strcmp(temp->name, src) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL || prev == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}
