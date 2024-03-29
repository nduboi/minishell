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

void fill_struct(commands_t **commands);
int check_correct_command(char **data, commands_t *commands, env_var_t **env,
    env_var_t *cpy_env);
char *get_pwd_file(char *src, char *path, env_var_t *env);
char *str_cat_pwd(char *path_1, char *path_2);
char **my_str_to_word_array(char const *str);
char **my_str_to_word_array_pwd(char const *str);
char **str_to_word_array(char *src, const char *separator);
int non_interactive(env_var_t *env, env_var_t *cpy_env);
int execution_process(char **data, int cmds, commands_t *commands,
    env_var_t **env);
int start_commands_non_interactive(char **data, int cmds, commands_t *commands,
    env_var_t **env);
int main_cd(int ac, char **av, struct env_var **env, env_var_t *cpy_env);
int handle_error(char **src, int home, env_var_t *cpy_env);
int main_env(int ac, char **av, struct env_var **env, env_var_t *cpy_env);
int main_setenv(int ac, char **av, struct env_var **env, env_var_t *cpy_env);
int main_exit(int ac, char **av, env_var_t **env, env_var_t *cpy_env);
int main_unsetenv(int ac, char **av, env_var_t **env, env_var_t *cpy_env);
void add_value_in_env(char **av, struct env_var **env);
char *get_env(char *src, struct env_var *env);
void print_env(env_var_t *env);
char **my_table_cpy(char **src);
char *my_str_cpy(char *src);
char **fill_env_variables_oldpwd(void);
char **fill_env_variables_pwd(void);
env_var_t *fill_environement(char **env);
void print_env_struct(env_var_t *env);
char **my_linked_list_to_table(env_var_t *env);
void delete_node(env_var_t **pos, char *src);
int get_line_env(char *name, struct env_var *env);
int content_slash(char *src);
int buildinprgm(char **data, commands_t *commands,
    env_var_t **env, env_var_t *cpy_env);
int native_prgrm(char **data, env_var_t **env);
int check_if_is_a_buildintcmd(char **data, commands_t **elements);
char *my_stock_nbr(int nb);
char **get_content_file(char *path);
void add_node_env_struct(char *src, char *value, env_var_t **pos);
char **fill_env_variables_oldpwd(void);
char **fill_env_variables_pwd(void);

#endif /* !MINISHELL1 */
