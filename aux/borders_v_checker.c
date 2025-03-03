/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borders_v_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:09:07 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/03/03 19:09:50 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

// int	borders_v_checker(char *route)
// {
// 	int		fd;
// 	int		i;
// 	int		files;
// 	char	*line;

// 	fd = open(route, O_RDONLY);
// 	i = 1;
// 	files = files_map(route);
// 	if (fd == -1)
// 		return (perror("Error al abrir el archivo"), -1);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		if ((i == 1 || i == files) && is_invalid_vertical_border(line))
// 		{
// 			free(line);
// 			close(fd);
// 			return (0);
// 		}
// 		if (i != 1 && i != files && (line[0] != '1'
// 				|| line[line_len(line) - 1] != '1'))
// 		{
// 			free(line);
// 			close(fd);
// 			return (0);
// 		}
// 		free(line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	close(fd);
// 	return (1);
// }

int	is_invalid_vertical_border(char *line)
{
	int	len;

	len = line_len(line);
	return (line[0] != '1' || line[len - 1] != '1');
}

static int	close_and_return(int fd, char *line, int ret)
{
	free(line);
	close(fd);
	return (ret);
}

static int	check_middle_lines(char *line, int fd)
{
	if (line[0] != '1' || line[line_len(line) - 1] != '1')
		return (close_and_return(fd, line, 0));
	return (1);
}

int	borders_v_checker(char *route)
{
	int		fd;
	int		i;
	int		files;
	char	*line;

	fd = open(route, O_RDONLY);
	if (fd == -1)
		return (perror("Error al abrir el archivo"), -1);
	files = files_map(route);
	i = 1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if ((i == 1 || i == files) && is_invalid_vertical_border(line))
			return (close_and_return(fd, line, 0));
		if (i != 1 && i != files && check_middle_lines(line, fd) == 0)
			return (0);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (1);
}
