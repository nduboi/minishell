/*
** EPITECH PROJECT, 2024
** non interactiv
** File description:
** non_interactive
*/

#include "minishell1.h"
#include "library.h"

int non_interactive(env_var_t *env)
{
    char *str = NULL;
    char **data = NULL;
    int cmds = 0;
    size_t len;
    commands_t *commands = NULL;

    fill_struct(&commands);
    while (getline(&str, &len, stdin) != -1) {
        str[my_strlen(str) - 1] = '\0';
        data = my_str_to_word_array(str);
        if (my_strcmp(data[0], "exit") == 0)
            return 0;
        check_correct_command(&cmds, data, commands, env);
        if (cmds != 0 && cmds != 84)
            cmds = start_commands(data, cmds, commands, &env);
    }
    if (cmds == 84)
        return 1;
    return cmds;
}
