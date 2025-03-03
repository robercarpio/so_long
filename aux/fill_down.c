/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:09:35 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/02/26 18:09:36 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

int	fill_down(char **map, int y, int x)
{
	int	height;

	height = map_height(map);
	while (y < height - 1 && map[y + 1][x] != '1')
	{
		if (map[y + 1][x] != 'E')
			return (1);
		map[y + 1][x] = 'V';
		y++;
	}
	return (0);
}
