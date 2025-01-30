#include "aux.h"

int	fill_cross(char **map, int y, int x)
{
	return(fill_left(map,y,x) || fill_right(map,y,x) || fill_up(map,y,x) || fill_down(map,y,x));
}