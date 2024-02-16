/*
** EPITECH PROJECT, 2024
** get content
** File description:
** get_content_file
*/

#include "minishell1.h"
#include "library.h"

static int get_file_directory(char *path)
{
    int fd = -1;

    fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return fd;
    }
    return fd;
}

static int get_size_file(char *path)
{
    struct stat buffer;

    if (stat(path, &buffer) == -1) {
        perror("stats");
        return -1;
    }
    return buffer.st_size;
}

static char *get_src_read(int len, int fd)
{
    char *result = malloc(sizeof(char) * len + 1);

    if (read(fd, result, len) == -1) {
        perror("read");
        return NULL;
    }
    result[len] = '\0';
    return result;
}

char **get_content_file(char *path)
{
    int fd = -1;
    char *file_buffer = NULL;
    char **data = NULL;
    int size = 0;

    if (!path)
        return NULL;
    size = get_size_file(path);
    if (size == -1 && size != 0)
        return NULL;
    fd = get_file_directory(path);
    if (fd == -1)
        return NULL;
    file_buffer = get_src_read(size, fd);
    data = str_to_word_array(file_buffer, "\n");
    return data;
}
