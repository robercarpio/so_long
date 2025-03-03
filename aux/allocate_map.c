/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:08:47 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/02/26 18:08:50 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"
#include <stdio.h>

char	**allocate_map(char *route)
{
	int		fd;
	char	*line;
	int		height;
	char	**map;
	int		i;

	fd = open(route, O_RDONLY);
	if (fd == -1)
		return (perror("Error al abrir el archivo"), NULL);
	height = files_map(route);
	map = (char **)malloc((height + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = dup_line(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
