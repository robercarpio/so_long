#include "aux.h"

int map_height(char **map)
{
    int height = 0;
    while (map[height] != NULL)
        height++;
    return height;
}