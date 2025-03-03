/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borders_h_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:09:02 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/02/27 19:20:09 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

int	is_valid_border(char *line, int *fl, int i, int files)
{
	if (i == 1 && only_chars_allowed(line, "1"))
	{
		*fl = 1;
		return (1);
	}
	if (*fl && i == files && only_chars_allowed(line, "1"))
		return (1);
	return (0);
}

int	borders_h_checker(char *route)
{
	int		fd;
	char	*line;
	int		files;
	int		i;
	int		fl;

	fl = 0;
	i = 1;
	fd = open(route, O_RDONLY);
	if (fd == -1)
		return (perror("Error al abrir el archivo"), exit(-1), -1);
	line = get_next_line(fd);
	files = files_map(route);
	while (line != NULL)
	{
		if (is_valid_border(line, &fl, i, files))
			return (free(line), close(fd), 1);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 0);
}
