#include "aux.h"

int	borders_h_checker(char *route)
{
	int	fd;
	char	*line;
	int	files;
	int	i;
	int	fl;

	fl = 0;
	i = 1;
	fd = open(route,O_RDONLY);
	if(fd == -1)
		return(perror("Error al abrir el arcivo"),-1);
	files = files_map(route);
	while((line = get_next_line(fd))!=NULL)
	{
		if(i == 1 && only_chars_allowed(line,"1"))
		{
			fl = 1;
			i++;
			free(line);
		}
		else if(fl)
		{ 
			if(i == files && only_chars_allowed(line,"1"))
				return(free(line),1);
			i++;
			free(line);
		}
	}
	return(0);
}
