/*
 * E89 Pedagogical & Technical Lab
 * project: Project maze
 * created on:  2026-01-21 - 17:06 +0100
 * 1st author:  emma.ploton
 * description: rotate
 */
#include "direction.h"

int rotate(int direction, char operation)
{
    if (operation == '+') {
        direction = direction + 1;
    } else {
        direction = direction - 1;
    }
    if (direction < NORTH) {
        direction = WEST;
    }
    if (direction > WEST) {
        direction = NORTH;
    }
    return direction;
}
