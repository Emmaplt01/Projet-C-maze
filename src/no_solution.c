/*
 * E89 Pedagogical & Technical Lab
 * project: Project maze
 * created on:  2026-01-21 - 16:59 +0100
 * 1st author:  emma.ploton
 * description: no solution
 */
#include <unistd.h>

int no_solution(int position, int direction, int table_position[], int table_direction[], int *nb_visits)
{
    int i;

    i = 0;
    while (i < *nb_visits) {
        if (table_position[i] == position) {
            if (table_direction[i] == direction) {
                write(1,"No solution to maze.\n", 21);
                return 1;
            }
        }
        i = i + 1;
    }
    table_position[*nb_visits] = position;
    table_direction[*nb_visits] = direction;
    *nb_visits = *nb_visits + 1;
    return 0;
}
