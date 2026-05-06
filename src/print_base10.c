/*
 * E89 Pedagogical & Technical Lab
 * project: Project maze
 * created on:  2026-01-12 - 11:50 +0100
 * 1st author:  emma.ploton
 * description: read and measure
 */

#include <unistd.h>

void tc_putchar(char c);

int print_base10(int nb)
{
    int i;
    int print;

    i = 0;
    if (nb == 0) {
        tc_putchar('0');
        return 1;
    }
    if (nb < 0) {
        tc_putchar('-');
        nb = -nb;
    }
    while (nb > 0) {
        print = '0' + (nb % 10);
        nb = nb / 10;
        i = i + 1;
    }
    while (i > 0) {
        i = i - 1;
        tc_putchar(print);
    }
    return 0;
}

