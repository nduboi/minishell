/*
** EPITECH PROJECT, 2024
** main_exit
** File description:
** main_exit
*/

#include "library.h"
#include "minishell1.h"


static int write_error_exit(void)
{
    write(2, "exit: Expression Syntax.\n", 25);
    return 1;
}

static int check_correct_format(char *src)
{
    for (int i = 0; src[i] != '\0'; i++)
        if (!(src[i] >= '0' && src[i] <= '9'))
            return write_error_exit();
    return 0;
}

int main_exit(int ac, char **av, env_var_t **env, env_var_t *cpy_env)
{
    (void) cpy_env;
    if (*env != NULL)
        *env = *env;
    if (ac == 2) {
        my_putstr("exit\n");
        if (check_correct_format(av[1]))
            return 1;
        else
            exit(my_getnbr(av[1]));
    }
    if (ac > 2)
        return write_error_exit();
    if (ac == 1) {
        my_putstr("exit\n");
        exit(0);
    }
    return 0;
}
