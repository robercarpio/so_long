#include "aux.h"

int   files_map(char *route)
{
	int		fd;
	char	*line;
      int   rows;

      rows = 0;

	fd = open(route, O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (-1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		if(line[0]!='\0')
		{
			rows++;
			free(line); 
		}
	}
	close(fd);
	return (rows);     
}