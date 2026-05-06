/*
 * E89 Pedagogical & Technical Lab
 * project: Project maze
 * created on:  2026-01-11 - 14:24 +0100
 * 1st author:  emma.ploton
 * description: Map width
 */
#include <unistd.h>

int print_base10(int nb);
int tc_putchar(char c);

unsigned int strlen_to_lf(char *map)
{
    unsigned int i;

    i = 0;
    while (map[i] != '\n' && map[i] != '\0') {
        i = i + 1;
    }
    return i;
}

int map_width(char *map)
{
    int width;
    int i;
    int len;

    i = 0;
    width = strlen_to_lf(&map[i]);
    while (map[i] != '\0') {
        len = strlen_to_lf(&map[i]);
        if (len != width) {
            return 1;
        }
        i = i + len + 1;
    }
    write(1, "width: ", 7);
    print_base10(width);
    tc_putchar(',');
    return width;
}
