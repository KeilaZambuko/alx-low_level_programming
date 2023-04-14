#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

void check_argument_count(int argc)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: cp file_from file_to\n");
        exit(EXIT_FAILURE);
    }
}

int open_file(const char *file_name, int flags, mode_t mode)
{
    int fd = open(file_name, flags, mode);
    if (fd == -1)
    {
        fprintf(stderr, "Error: Can't open file %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    return fd;
}

void check_read(ssize_t result, const char *file_name, int fd_from, int fd_to)
{
    if (result == -1)
    {
        fprintf(stderr, "Error: Can't read from file %s\n", file_name);
        if (fd_from != -1)
            close(fd_from);
        if (fd_to != -1)
            close(fd_to);
        exit(EXIT_FAILURE);
    }
}

void check_write(ssize_t result, const char *file_name, int fd_from, int fd_to)
{
    if (result == -1)
    {
        fprintf(stderr, "Error: Can't write to file %s\n", file_name);
        if (fd_from != -1)
            close(fd_from);
        if (fd_to != -1)
            close(fd_to);
        exit(EXIT_FAILURE);
    }
}

void check_close(int result, int fd)
{
    if (result == -1)
    {
        fprintf(stderr, "Error: Can't close fd %d\n", fd);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    int fd_from = -1, fd_to = -1;
    ssize_t lenr = BUFFER_SIZE, lenw;
    char buffer[BUFFER_SIZE];
    mode_t file_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

    check_argument_count(argc);
    fd_from = open_file(argv[1], O_RDONLY, 0);
    fd_to = open_file(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_mode);

    while (lenr == BUFFER_SIZE)
    {
        lenr = read(fd_from, buffer, BUFFER_SIZE);
        check_read(lenr, argv[1], fd_from, fd_to);

        lenw = write(fd_to, buffer, lenr);
        check_write(lenw, argv[2], fd_from, fd_to);
    }

    int close_result = 0;
    close_result = close(fd_from);
    check_close(close_result, fd_from);
    close_result = close(fd_to);
    check_close(close_result, fd_to);

    return EXIT_SUCCESS;
}
