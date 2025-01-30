#include "process_map.h"

int	is_playable(char **map,int y, int x)
{
	if(!fill_cross(map,y,x))
	{
		//conseguir cuales son las siguientes coordenadas libres [0,C,P]
		is_playable(map,y,x);
	}
	return(0);
}