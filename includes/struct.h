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
    void (*fct)(char **);
    struct my_commands *next;
}commands_t;

#endif /* !STRUCT_H_ */
