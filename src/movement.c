/*
 * E89 Pedagogical & Technical Lab
 * project: Project maze
 * created on:  2026-01-17 - 18:53 +0100
 * 1st author:  emma.ploton
 * description: movement
 */
#include "point_2D.h"
#include "map.h"
#include "direction.h"

int coords(int x, int y, int width);
void show_map(char *buffer);
int no_solution(int position, int direction, int table_position[], int table_direction[], int *nb_visits);
int rotate(int direction, char operation);

int north(struct point_2D *p, int width, int direction, char *buffer)
{
    int left;
    int in_front;

    left = coords(p->x, p->y - 1, width);
    in_front = coords(p->x - 1, p->y, width);
    if (left < 0 || in_front < 0) {
        return rotate(direction, '+');
    } else if (buffer[left] == '.' || buffer[left] == ' ') {
        direction = rotate(direction, '-');
        buffer[left] = ' ';
        p->y = p->y - 1;
        return direction;
    } else if (buffer[left] == 'G') {
        p->y = p->y - 1;
        return direction;
    } else if (buffer[in_front] == '.' || buffer[in_front] == ' ') {
        buffer[in_front] = ' ';
        p->x = p->x - 1;
        return direction;
    } else if (buffer[in_front] == 'G') {
        p->x = p->x - 1;
        return direction;
    }
    direction = rotate(direction, '+');
    return direction;
}

int east(struct point_2D *p, int width, int direction, char *buffer)
{
    int left;
    int in_front;

    left = coords(p->x - 1, p->y, width);
    in_front = coords(p->x, p->y + 1, width);
    if (left < 0 || in_front < 0) {
        return rotate(direction, '+');
    } else if (buffer[left] == '.'|| buffer[left] == ' ') {
        direction = rotate(direction, '-');
        buffer[left] = ' ';
        p->x = p->x - 1;
        return direction;
    } else if (buffer[left] == 'G') {
        p->x = p->x - 1;
        return direction;
    } else if (buffer[in_front] == '.' || buffer[in_front] == ' ') {
        buffer[in_front] = ' ';
        p->y = p->y + 1;
        return direction;
    } else if (buffer[in_front] == 'G') {
        p->y = p->y + 1;
        return direction;
    }
    direction = rotate(direction, '+');
    return direction;
}

int south(struct point_2D *p, int width, int direction, char *buffer)
{
    int left;
    int in_front;

    left = coords(p->x, p->y + 1, width);
    in_front = coords(p->x + 1, p->y, width);
    if (left < 0 || in_front < 0) {
        return rotate(direction, '+');
    } else if (buffer[left] == '.'|| buffer[left] == ' ') {
        direction = rotate(direction, '-');
        buffer[left] = ' ';
        p->y = p->y + 1;
        return direction;
    } else if (buffer[left] == 'G') {
        p->y = p->y + 1;
        return direction;
    } else if (buffer[in_front] == '.' || buffer[in_front] == ' ') {
        buffer[in_front] = ' ';
        p->x = p->x + 1;
        return direction;
    } else if (buffer[in_front] == 'G') {
        p->x = p->x + 1;
        return direction;
    }
    direction = rotate(direction, '+');
    return direction;
}

int west(struct point_2D *p, int width, int direction, char *buffer)
{
    int left;
    int in_front;

    left = coords(p->x + 1, p->y, width);
    in_front = coords(p->x, p->y - 1, width);
    if (left < 0 || in_front < 0) {
        return rotate(direction, '+');
    } else if (buffer[left] == '.'|| buffer[left] == ' ') {
        direction = rotate(direction, '-');
        buffer[left] = ' ';
        p->x = p->x + 1;
        return direction;
    } else if (buffer[left] == 'G') {
        p->x = p->x + 1;
        return direction;
    } else if (buffer[in_front] == '.' || buffer[in_front] == ' ') {
        buffer[in_front] = ' ';
        p->y = p->y - 1;
        return direction;
    } else if (buffer[in_front] == 'G') {
        p->y = p->y - 1;
        return direction;
    }
    direction = rotate(direction, '+');
    return direction;
}

int movement(struct point_2D *p, char *buffer, int width, int position, int height)
{
    int direction;
    int table_position[width * height];
    int table_direction[width * height];
    int nb_visits;

    nb_visits = 0;
    direction = 0;
    while (buffer[position] != 'G') {
        if (no_solution(position, direction, table_position, table_direction, &nb_visits) == 1) {
            return 1;
        }
        if (direction == NORTH) {
            direction = north(p, width, direction, buffer);
        } else if (direction == EAST) {
            direction = east(p, width, direction, buffer);
        } else if (direction == SOUTH) {
            direction = south(p, width, direction, buffer);
        } else if (direction == WEST) {
            direction = west(p, width, direction, buffer);
        }
        position = coords(p->x, p->y, width);
    }
    show_map(buffer);
    return 0;
}

