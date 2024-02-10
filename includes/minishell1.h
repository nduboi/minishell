/*
** EPITECH PROJECT, 2024
** MINISHELL1.h
** File description:
** MINISHELL1
*/

#include <unistd.h>
#include <stdio.h>
#include "struct.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef MINISHELL1_H_
    #define MINISHELL1_H_

int get_input_user(void);
void fill_struct(commands_t **commands);
void check_correct_command(int *cmds, char *str, commands_t *commands);
char *get_pwd_file(char *src);

#endif /* !MINISHELL1 */
