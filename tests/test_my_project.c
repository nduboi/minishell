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
    char *data_ls[] = {"ls", NULL};
    char *data_cd[] = {"cd", NULL};
    char *data_nimp[] = {"fqfqfefq", NULL};

    check_correct_command(&cmds, data_ls, commands);
    my_put_nbr(cmds);
    my_putchar('\n');
    check_correct_command(&cmds, data_cd, commands);
    my_put_nbr(cmds);
    my_putchar('\n');
    check_correct_command(&cmds, data_nimp, commands);
    my_put_nbr(cmds);
    my_putchar('\n');
    cr_assert_stdout_eq_str("2\n1\n0\n");
}

Test(main_env, main_env1, .init = redirect_all_std)
{
    char *av[] = {"env", NULL};
    char **env = malloc(sizeof(char *) * 3);
    env[0] = my_strdup("coucou=noa");
    env[1] = my_strdup("tests=noa");
    env[2] = NULL;

    my_put_nbr(main_env(1, av, &env));
    cr_assert_stdout_eq_str("coucou=noa\ntests=noa\n0");
}

Test(main_env, main_env2, .init = redirect_all_std)
{
    char *av[] = {"encafv", NULL};
    char **env = malloc(sizeof(char *) * 3);
    env[0] = my_strdup("coucou=noa");
    env[1] = my_strdup("tests=noa");
    env[2] = NULL;

    my_put_nbr(main_env(1, av, &env));
    cr_assert_stdout_eq_str("84");
}

Test(main_env, main_env3, .init = redirect_all_std)
{
    char *av[] = {"encafv", NULL};
    char **env = NULL;

    my_put_nbr(main_env(1, av, &env));
    cr_assert_stdout_eq_str("84");
}

Test(main_setenv, main_setenv1, .init = redirect_all_std)
{
    char *av[] = {"setenv", "coucou", "ca va", NULL};
    char **env = malloc(sizeof(char *) * 3);
    env[0] = my_strdup("coucou=noa");
    env[1] = my_strdup("tests=noa");
    env[2] = NULL;

    my_put_nbr(main_setenv(3, av, &env));
    print_env(env);
    cr_assert_stdout_eq_str("0coucou=ca va\ntests=noa\n");
}

Test(main_setenv, main_setenv2, .init = redirect_all_std)
{
    char **av = malloc(sizeof(char *) * 4);
    av[0] = my_strdup("setenv");
    av[1] = my_strdup("OLDPWD");
    av[2] = my_strdup("noa");
    av[4] = NULL;
    char **env = malloc(sizeof(char *) * 3);
    env[0] = my_strdup("coucou=noa");
    env[1] = my_strdup("tests=noa");
    env[2] = NULL;

    my_put_nbr(main_setenv(3, av, &env));
    print_env(env);
    cr_assert_stdout_eq_str("0coucou=noa\ntests=noa\nOLDPWD=noa\n");
}

Test(main_setenv, main_setenv4, .init = redirect_all_std)
{
    char **av = malloc(sizeof(char *) * 5);
    av[0] = my_strdup("setenv");
    av[1] = my_strdup("OLDPWD");
    av[2] = my_strdup("noa");
    av[3] = my_strdup("cace");
    av[4] = NULL;
    char **env = malloc(sizeof(char *) * 3);
    env[0] = my_strdup("coucou=noa");
    env[1] = my_strdup("tests=noa");
    env[2] = NULL;

    my_put_nbr(main_setenv(4, av, &env));
    print_env(env);
    cr_assert_stdout_eq_str("84coucou=noa\ntests=noa\n");
}

Test(main_setenv, main_setenv5, .init = redirect_all_std)
{
    char **av = malloc(sizeof(char *) * 4);
    av[0] = my_strdup("setenvne");
    av[1] = my_strdup("OLDPWD");
    av[2] = my_strdup("noa");
    av[3] = NULL;
    char **env = malloc(sizeof(char *) * 3);
    env[0] = my_strdup("coucou=noa");
    env[1] = my_strdup("tests=noa");
    env[2] = NULL;

    my_put_nbr(main_setenv(3, av, &env));
    print_env(env);
    cr_assert_stdout_eq_str("84coucou=noa\ntests=noa\n");
}

Test(main_setenv, main_setenv6, .init = redirect_all_std)
{
    char **av = malloc(sizeof(char *) * 4);
    av[0] = my_strdup("setenvne");
    av[1] = my_strdup("OLDPWD");
    av[2] = my_strdup("noa");
    av[3] = NULL;
    char **env = NULL;

    my_put_nbr(main_setenv(3, av, &env));
    print_env(env);
    cr_assert_stdout_eq_str("84");
}

Test(main_setenv, main_setenv7, .init = redirect_all_std)
{
    char **av = malloc(sizeof(char *) * 4);
    av[0] = my_strdup("setenvne");
    av[1] = NULL;
    av[2] = NULL;
    av[3] = NULL;
    char **env = malloc(sizeof(char *) * 3);
    env[0] = my_strdup("coucou=noa");
    env[1] = my_strdup("tests=noa");
    env[2] = NULL;

    my_put_nbr(main_setenv(3, av, &env));
    print_env(env);
    cr_assert_stdout_eq_str("84coucou=noa\ntests=noa\n");
}


Test(get_line_env, get_line_env1, .init = redirect_all_std)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = my_strdup("coucou=noa");
    env[1] = my_strdup("tests=noa");
    env[2] = NULL;

    my_put_nbr(get_line_env("azfbzbf", env));
    print_env(env);
    cr_assert_stdout_eq_str("2coucou\ntests\n");
}

Test(my_table_cpy, my_table_cpy1, .init = redirect_all_std)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = my_strdup("coucou=noa");
    env[1] = my_strdup("tests=noa");
    env[2] = NULL;

    my_put_nbr(get_line_env("azfbzbf", my_table_cpy(env)));
    print_env(env);
    cr_assert_stdout_eq_str("2coucou=noa\ntests=noa\n");
}

Test(my_table_cpy, my_table_cpy2, .init = redirect_all_std)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = my_strdup("coucou=noa");
    env[1] = my_strdup("tests=noa");
    env[2] = NULL;
    char **cpy_table = my_table_cpy(env);

    my_put_nbr(get_line_env("azfbzbf", cpy_table));
    print_env(cpy_table);
    cr_assert_stdout_eq_str("2coucou\ntests\n");
}

Test(main_cd, main_cd1, .init = redirect_all_std)
{
    char **av = malloc(sizeof(char *) * 2);
    av[0] = my_strdup("cd");
    av[1] = NULL;
    char **env = malloc(sizeof(char *) * 3);
    env[0] = my_strdup("coucou=noa");
    env[1] = my_strdup("HOME=tests");
    env[2] = NULL;
    char *buffer = malloc(sizeof(char) * 300);
    char *old_path = malloc(sizeof(char) * 300);

    getcwd(old_path, 300);
    my_put_nbr(main_cd(my_array_len(av), av, &env));
    getcwd(buffer, 300);
    if (my_strcmp(buffer, get_env("HOME", my_table_cpy(env))))
        my_put_nbr(0);
    else
        my_put_nbr(1);
    print_env(env);
    char final_str[100];
    strcat(strcpy(final_str, "00coucou=noa\nHOME=tests\nOLDPWD="), old_path);
    strcat(final_str, "\n");
    cr_assert_stdout_eq_str(final_str);
}

Test(main_cd, main_cd2, .init = redirect_all_std)
{
    char **av = malloc(sizeof(char *) * 3);
    av[0] = my_strdup("cd");
    av[1] = my_strdup("~");
    av[2] = NULL;
    char **env = malloc(sizeof(char *) * 3);
    env[0] = my_strdup("coucou=noa");
    env[1] = my_strdup("HOME=tests");
    env[2] = NULL;
    char *buffer = malloc(sizeof(char) * 300);
    char *old_path = malloc(sizeof(char) * 300);

    getcwd(old_path, 300);
    my_put_nbr(main_cd(my_array_len(av), av, &env));
    getcwd(buffer, 300);
    if (my_strcmp(buffer, get_env("HOME", my_table_cpy(env))))
        my_put_nbr(0);
    else
        my_put_nbr(1);
    print_env(env);
    char final_str[100];
    strcat(strcpy(final_str, "00coucou=noa\nHOME=tests\nOLDPWD="), old_path);
    strcat(final_str, "\n");
    cr_assert_stdout_eq_str(final_str);
}
