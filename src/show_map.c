/*
 * E89 Pedagogical & Technical Lab
 * project: Project maze
 * created on:  2026-01-12 - 16:51 +0100
 * 1st author:  emma.ploton
 * description: show the map
 */
#include <unistd.h>

void tc_putchar(char c);
int print_base10(int nb);

void show_map(char *buffer)
{
    int i;

    i = 0;
    while (buffer[i] != '\0') {
        tc_putchar(buffer[i]);
        i = i + 1;
    }
}

