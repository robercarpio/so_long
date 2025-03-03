/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:10:47 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/02/27 21:00:45 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_map.h"
#include <stdio.h>

int	is_exit_reachable(char **grid, int y, int x)
{
	int	width;
	int	height;

	width = line_len(grid[0]);
	height = map_height(grid);
	if (x < 0 || y < 0 || x >= width || y >= height
		|| grid[y][x] == '1')
		return (0);
	if (grid[y][x] == 'E')
		return (1);
	if (grid[y][x] == 'V')
		return (0);
	grid[y][x] = 'V';
	return (is_exit_reachable(grid, y, x + 1)
		|| is_exit_reachable(grid, y, x - 1)
		|| is_exit_reachable(grid, y + 1, x)
		|| is_exit_reachable(grid, y - 1, x));
}

int	are_coins_reachable(char **grid, int y, int x, int *i)
{
	int	width;
	int	height;

	width = line_len(grid[0]);
	height = map_height(grid);
	if (x < 0 || y < 0 || x >= width || y >= height
		|| grid[y][x] == '1')
		return (0);
	if (grid[y][x] == 'C')
		(*i)++;
	if (grid[y][x] == 'V')
		return (0);
	grid[y][x] = 'V';
	return (are_coins_reachable(grid, y, x + 1, i)
		|| are_coins_reachable(grid, y, x - 1, i)
		|| are_coins_reachable(grid, y + 1, x, i)
		|| are_coins_reachable(grid, y - 1, x, i));
}
