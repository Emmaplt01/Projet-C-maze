/*
 * E89 Pedagogical & Technical Lab
 * project: maze
 * created on:  2026-01-28 - 15:04 +0100
 * 1st author:  emma.ploton
 * description: strlen
 */

unsigned int stu_strlen(const char *str)
{
    unsigned int i;

    i = 0;
    while (*str != '\0') {
        i = i + 1;
        str = str + 1;
    }
    return i;
}
