/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:13:42 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/02/26 19:25:38 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

int	coord_x(char **map, char c)
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
				return (x);
			x++;
		}
		y++;
	}
	return (-1);
}
