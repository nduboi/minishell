/*
** EPITECH PROJECT, 2024
** MINISHELL1.h
** File description:
** MINISHELL1
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>

#ifndef MINISHELL1_H_
    #define MINISHELL1_H_
    #define MAXLEN  100
    #define BUFFER_SIZE 300

int get_input_user(char **env);
void fill_struct(commands_t **commands);
void check_correct_command(int *cmds, char **data, commands_t *commands,
    char **env);
char *get_pwd_file(char *src, char *path, char **env);
char **my_str_to_word_array(char const *str);
char **my_str_to_word_array_pwd(char const *str);
int start_commands(char **data, int cmds, commands_t *commands, char ***env);
int non_interactive(char **env);
int execution_process(char **data, int cmds, commands_t *commands,
    char ***env);
int start_commands_non_interactive(char **data, int cmds, commands_t *commands,
    char ***env);
int main_cd(int ac, char **av, char ***env);
int main_env(int ac, char **av, char ***env);
int main_setenv(int ac, char **av, char ***env);
char *get_env(char *src, char **env);
int get_line_env(char *name, char **env);
void print_env(char **env);
char **my_table_cpy(char **src);
char **add_value_in_env(char **av, char **env);

#endif /* !MINISHELL1 */
