/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_y.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:15:09 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/02/26 19:26:31 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

int	coord_y(char **map, char c)
{
	int	x;
	int	y;

	y = 0;
	while (y < map_height(map))
	{
		x = 0;
		while (x < line_len(map[y]))
		{
			if (map[y][x] == c)
				return (y);
			x++;
		}
		y++;
	}
	return (-1);
}
