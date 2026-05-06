/*
 * E89 Pedagogical & Technical Lab
 * project: Project maze
 * created on:  2026-01-16 - 18:54 +0100
 * 1st author:  emma.ploton
 * description: position x and y
 */

int coords(int x, int y, int width)
{
    int position;

    position = (width + 1) * y + x;
    return position;
}
