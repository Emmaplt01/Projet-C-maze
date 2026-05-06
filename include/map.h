/*
*  E89 Pedagogical & Technical Lab
*  project: Project maze
*  created on:  2026-01-21 - 15:22 +0100
*  1st author:  emma.ploton
*  description: struct for width and height
*/

#ifndef MAP_H
#define MAP_H

int map_height(char *map);
int map_width(char *map);

struct map {
    int width;
    int height;
};

#endif
