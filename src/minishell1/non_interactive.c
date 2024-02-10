/*
** EPITECH PROJECT, 2024
** non interactiv
** File description:
** non_interactive
*/

#include "minishell1.h"
#include "library.h"

int non_interactive(void)
{
    char *str = malloc(sizeof(char) * MAXLEN);
    char **data;
    int cmds = 0;
    commands_t *commands = NULL;

    fill_struct(&commands);
    read(STDIN_FILENO, str, MAXLEN);
    str[my_strlen(str) - 1] = '\0';
    data = my_str_to_word_array(str);
    if (my_strcmp(data[0], "exit") == 0)
        return 0;
    check_correct_command(&cmds, data[0], commands);
    if (cmds != 0)
        cmds = start_commands_non_interactive(data, cmds, commands);
    free(data);
    return cmds;
}
