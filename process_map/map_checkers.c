/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:10:49 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/02/27 19:47:58 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_map.h"

int	check_map(char *route)
{
	return (is_rectangle(route)
		&& check_borders_map(route) && check_chars_allow(route));
}

int	check_rectangle(int fd, int *len, int *rows)
{
	char	*line;
	int		current_len;

	line = get_next_line(fd);
	while (line != NULL)
	{
		current_len = line_len(line);
		if (line[0] == '\0' || (*len != -1 && current_len != *len))
		{
			free(line);
			return (0);
		}
		if (*len == -1)
			*len = current_len;
		free(line);
		(*rows)++;
		line = get_next_line(fd);
	}
	return (1);
}

int	is_rectangle(char *route)
{
	int	fd;
	int	len;
	int	rows;
	int	is_rect;

	len = -1;
	rows = 0;
	fd = open(route, O_RDONLY);
	if (fd == -1)
		return (perror("Error al abrir el archivo"), exit(-1), -1);
	is_rect = check_rectangle(fd, &len, &rows);
	consume_remaining(fd, &is_rect);
	close(fd);
	return (rows > 0 && is_rect);
}

int	check_borders_map(char *route)
{
	return (borders_h_checker(route) && borders_v_checker(route));
}

int	check_chars_allow(char *route)
{
	int		fd;
	char	*line;
	int		b;

	b = 1;
	fd = open(route, O_RDONLY);
	if (fd == -1)
		return (perror("Error al abrir el archivo"), exit(-1), -1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (only_chars_allowed(line, "01CPE") == 0)
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (b);
}
