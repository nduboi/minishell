/*
** EPITECH PROJECT, 2024
** struct
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct my_commands {

    char *name;
    int (*fct)(int ac, char **data, char ***env);
    struct my_commands *next;
}commands_t;

typedef struct env_var {

    char *name;
    char *value;
    struct env_var *next;
}env_var_t;

#endif /* !STRUCT_H_ */
