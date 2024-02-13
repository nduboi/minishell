/*
** EPITECH PROJECT, 2024
** struct
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct env_var {

    char *name;
    char *value;
    struct env_var *next;
}env_var_t;
typedef struct my_commands {

    char *name;
    int (*fct)(int ac, char **data, env_var_t **env);
    struct my_commands *next;
}commands_t;

#endif /* !STRUCT_H_ */
