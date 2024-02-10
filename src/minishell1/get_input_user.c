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

int get_input_user(void)
{
    char *str;
    char **data;
    commands_t *commands = NULL;
    int cmds = 0;

    fill_struct(&commands);
    while (1) {
        str = malloc(sizeof(char) * MAXLEN);
        write(1, "$> ", 4);
        read(STDIN_FILENO, str, MAXLEN);
        str[my_strlen(str) - 1] = '\0';
        data = my_str_to_word_array(str);
        if (my_strcmp(data[0], "exit") == 0)
            return 0;
        check_correct_command(&cmds, data[0], commands);
        if (cmds != 0)
            start_commands(data, cmds, commands);
        free_obj(data, str);
    }
    return 0;
}
