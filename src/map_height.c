/*
 * E89 Pedagogical & Technical Lab
 * project: Project maze
 * created on:  2026-01-11 - 14:22 +0100
 * 1st author:  emma.ploton
 * description: Map height
 */
#include <unistd.h>

int print_base10(int nb);

int map_height(char *map)
{
    int i;
    int height;

    i = 0;
    height = 0;
    while (map[i] != '\0') {
        if (map[i] == '\n') {
            height = height + 1;
        }
        i = i + 1;
    }
    write(1, "height: ", 8);
    print_base10(height);
    write(1, "\n", 1);
    return height;
}
