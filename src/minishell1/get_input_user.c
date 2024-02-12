/*
** EPITECH PROJECT, 2024
** get_input_user
** File description:
** get_input_user
*/

#include "minishell1.h"
#include "library.h"

static void free_obj(char **data, char *str)
{
    free(data);
    free(str);
    return;
}

int get_input_user(char **env)
{
    char *str;
    char **data;
    commands_t *commands = NULL;
    int cmds = 0;

    fill_struct(&commands);
    while (1) {
        str = malloc(sizeof(char) * MAXLEN);
        write(1, "$> ", 3);
        read(STDIN_FILENO, str, MAXLEN);
        str[my_strlen(str) - 1] = '\0';
        data = my_str_to_word_array(str);
        check_correct_command(&cmds, data, commands, env);
        if (cmds != 0)
            start_commands(data, cmds, commands, &env);
        free_obj(data, str);
    }
    return 0;
}
