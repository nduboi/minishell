/*
** EPITECH PROJECT, 2024
** no core dumped
** File description:
** send_no_coredump
*/

#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>

void main(void)
{
    kill(getpid(), SIGSEGV);
}