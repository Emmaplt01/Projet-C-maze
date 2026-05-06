/*
 * E89 Pedagogical & Technical Lab
 * project: Project maze
 * created on:  2026-01-07 - 12:01 +0100
 * 1st author:  emma.ploton
 * description: main
 */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include "map.h"

void start(char *buffer, int width, int height);
unsigned int stu_strlen(const char *str);

void tc_putchar(char c)
{
    write(1, &c, 1);
}

char *load_file(char *content)
{
    int fd;
    char *buffer;
    struct stat sb;

    fd = open(content, O_RDONLY);
    if (fd == -1) {
        write(1, strerror(errno), stu_strlen(strerror(errno)));
        tc_putchar('\n');
        return NULL;
    }
    stat(content, &sb);
    buffer = malloc(sizeof(char) * sb.st_size + 1);
    read(fd, buffer, sb.st_size);
    buffer[sb.st_size] = '\0';
    close(fd);
    return buffer;
}

int invalid_map(int width, int height)
{
    if (width == 1 || width != height) {
        write(1, "Invalid map", 11);
        tc_putchar('\n');
        return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    int invalid;
    char *buffer;
    struct map m;

    if (ac < 2) {
        return 1;
    }
    buffer = load_file(av[1]);
    m.width = map_width(buffer);
    m.height = map_height(buffer);
    invalid = invalid_map(m.width, m.height);
    if (buffer == NULL) {
        return 0;
    }
    if (invalid == 1) {
        free(buffer);
        return 1;
    }
    start(buffer, m.width, m.height);
    free(buffer);
}

