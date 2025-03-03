/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:09:20 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/02/26 18:09:21 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

int	count_char(char **map, char c)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (y < map_height(map))
	{
		x = 0;
		while (x < line_len(map[y]))
		{
			if (map[y][x] == c)
				i++;
			x++;
		}
		y++;
	}
	return (i);
}
