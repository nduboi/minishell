/*
** EPITECH PROJECT, 2023
** test_my_printf
** File description:
** Test file for my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell1.h"
#include "library.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(fill_struct, fill_struct1, .init = redirect_all_std)
{
    commands_t *commands = NULL;
    fill_struct(&commands);
    while (commands) {
        my_putstr(commands->name);
        my_putchar('\n');
        commands = commands->next;
    }
    cr_assert_stdout_eq_str("exit\nenv\nunsetenv\nsetenv\ncd\n");
}

Test(my_str_to_word_array, my_str_to_word_array1, .init = redirect_all_std)
{
    char *str = "ls -la /dev";
    char **data;

    data = my_str_to_word_array(str);
    for (int i = 0; data[i]; i++) {
        my_putstr(data[i]);
        my_putchar('\n');
    }
    cr_assert_stdout_eq_str("ls\n-la\n/dev\n");
}

Test(my_str_to_word_array, my_str_to_word_array2, .init = redirect_all_std)
{
    char *str = "l";
    char **data;

    data = my_str_to_word_array(str);
    for (int i = 0; data[i]; i++) {
        my_putstr(data[i]);
        my_putchar('\n');
    }
    cr_assert_stdout_eq_str("l\n");
}

Test(check_correct_command, check_correct_command1, .init = redirect_all_std)
{
    commands_t *commands = NULL;
    fill_struct(&commands);
    int cmds = 0;

    check_correct_command(&cmds, "ls", commands);
    my_put_nbr(cmds);
    my_putchar('\n');
    check_correct_command(&cmds, "cd", commands);
    my_put_nbr(cmds);
    my_putchar('\n');
    check_correct_command(&cmds, "fqfqfefq", commands);
    my_put_nbr(cmds);
    my_putchar('\n');
    cr_assert_stdout_eq_str("2\n1\n0\n");
}
