/*
 * E89 Pedagogical & Technical Lab
 * project: Project maze
 * created on:  2026-01-17 - 18:14 +0100
 * 1st author:  emma.ploton
 * description: set the start and the guy
 */
#include "point_2D.h"
#include "map.h"

void movement(struct point_2D *p, char *buffer, int width, int position, int height);
int coords(int x, int y, int width);

void start(char *buffer, int width, int height)
{
    int i;
    int position;
    struct point_2D p;

    i = 0;
    p.x = 0;
    p.y = 0;
    while (buffer[i] != 'S') {
        p.x = p.x + 1;
        if (p.x == width) {
            p.x = 0;
            p.y = p.y + 1;
        }
        i = i + 1;
    }
    position = coords(p.x, p.y, width);
    movement(&p, buffer, width, position, height);
}



