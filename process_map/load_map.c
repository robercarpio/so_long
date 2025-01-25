#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "aux/aux.h"
#include "process_map.h"

int   rows_map(char *route)
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

int is_rectangle(char *route)
{
    int fd;
    char *line;
    int len = -1;
    int rows = 0;
    int is_rect = 1;

    fd = open(route, O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return -1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        int current_len = line_len(line);
        if (line[0] == '\0')
        {
            free(line);
            break;
        }

        if (len == -1)
            len = current_len;
        else if (current_len != len)
        {
            is_rect = 0;
            free(line);
            break;
        }

        free(line);
        rows++;
    }

    // Consume cualquier línea vacía o final hasta el cierre
    while ((line = get_next_line(fd)) != NULL)
    {
        if (line[0] != '\0')
            is_rect = 0; // Si hay contenido no vacío después, no es válido
        free(line);
    }

    close(fd);

    if (rows == 0 || !is_rect)
        return 0; // No es un rectángulo válido

    return 1; // Es un rectángulo ignorando la última línea
}

int	check_chars_allow(char *route)
{
	char	*allow;
	int	i;
	int	fd;
	char	*line;

	allow = "01PC\n";
	fd = open(route,O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return(-1);
	}
	while ((line = get_next_line(fd))!= NULL)
	{
		if(only_chars_allowed(line,allow) == 0) //es lo mismo que only_chars_allowed(line,allow)
		//only_chars_allowed(line,allow) == 1 es lo mismo que !only_chars_allowed(line,allow)
		{
			free(line);
			return(0);
		}
		free(line);
	}
	close(fd);
	return(1);
}

int	calc_size_x(char *route)
{
	int	size;
	int	fd;
	char	*line;

	fd = open(route,O_RDONLY);
	if(fd == -1)
	{
		perror("Error al abrir el archivo");
		return(-1);
	}
	line = get_next_line(fd);
	size = line_len(line)*10;
	return(size);
}

int	calc_size_y(char *route)
{
	int	size;
	
	size = rows_map(route) * 10;
	return(size);
}

int   main(void)
{
	printf("%d\n",check_chars_allow("/home/rcarpio-/cursus/so_long/process_map/get_next_line/test.txt"));
      return(0);
}