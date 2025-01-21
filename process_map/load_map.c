#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "aux/aux.h"

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
		rows++;
		free(line); 
	}
	close(fd);
	return (rows);     
}

// int	is_rectangle(char *route)
// {
// 	int	fd1;
// 	int	fd2;
// 	char	*line;
// 	int	rows;
// 	int	len;

// 	fd1 = open(route,O_RDONLY);
// 	if(fd1 == -1)
// 		return(perror("Error al abrir el fichero"),-1);
// 	len = line_len(get_next_line(fd1));
// 	close(fd1);
// 	fd2 = open(route, O_RDONLY);
// 	if(fd2 == -1)
// 	      return(perror("Error al abrir el fichero"),-1);
// 	rows = 0;
// 	while ((line = get_next_line(fd2))!= NULL)
// 	{
// 		if(line_len(line)!= len)
// 		{
//                   close(fd2);
//                   return(0);
//             }
// 		free(line);
// 		rows++;
// 	}
// 	close(fd2);
// 	printf("%d rows\n",rows);
// 	if(rows != rows_map(route))
// 		return(0);
// 	return(1);
// }

// void	is_rectangle(char *route)
// {
// 	char	*line;
// 	char	*line2;
//       int      fd;
// 	int	fd2;
// 	int	rows;
// 	int	len;

// 	fd = open(route, O_RDONLY);
// 	if (fd == -1)
// 		perror("Error al abrir el archivo");
// 	line = get_next_line(fd);
// 	len = line_len(line);
// 	free(line);
// 	fd2 = open(route,O_RDONLY);
// 	if(fd2 == -1)
// 		perror("Error al abrir el archivo");
// 	rows = 0;
// 	while ((line2 = get_next_line(fd2))!= NULL)
// 	{
// 		if(line_len(line2) == l	en)
// 		{
// 			rows++;
// 			free(line2);
//             }
// 		else
// 			close(fd2);
// 	}
// 	printf("%d\n", rows);
// }

void	is_rectangle(char *route)
{
	char	*line;
	char	*line2;
	int	fd, fd2, rows, len, current_len;

	fd = open(route, O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return;
	}

	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		printf("0\n");
		return;
	}

	// Calculamos la longitud sin contar el '\n' (si existe)
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;

	free(line);
	close(fd);

	fd2 = open(route, O_RDONLY);
	if (fd2 == -1)
	{
		perror("Error al abrir el archivo");
		return;
	}

	rows = 0;
	while ((line2 = get_next_line(fd2)) != NULL)
	{
		current_len = ft_strlen(line2);
		if (line2[current_len - 1] == '\n')
			current_len--;

		if (current_len != len)
		{
			free(line2);
			close(fd2);
			printf("0\n");
			return;
		}
		free(line2);
		rows++;
	}
	close(fd2);
	printf("%d\n", rows);
}

int   main(void)
{
	is_rectangle("/home/rober/Desktop/cursus/so_long/process_map/get_next_line/test.txt");
      return(0);
}