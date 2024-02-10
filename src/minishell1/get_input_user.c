/*
** EPITECH PROJECT, 2024
** get_input_user
** File description:
** get_input_user
*/

#include "minishell1.h"
#include "library.h"

int get_input_user(void)
{
    char *str = malloc(sizeof(char) * 9);
    commands_t *commands = NULL;
    int cmds = 0;

    fill_struct(&commands);
    while (1) {
        write(1, "$> ", 4);
        read(STDIN_FILENO, str, 9);
        str[my_strlen(str) - 1] = '\0';
        if (my_strcmp(str, "exit") == 0)
            return 0;
        check_correct_command(&cmds, str, commands);
        if (cmds == 0)
            return 84;
    }
    return 0;
}
