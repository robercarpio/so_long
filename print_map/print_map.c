/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:10:40 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/02/26 18:10:41 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_map.h"

void	print_map(t_game game)
{
	int	y;
	int	x;
	int	i;
	int	j;

	i = 0;
	y = 0;
	while (i < game.map.size_y)
	{
		j = 0;
		x = 0;
		while (j < game.map.size_x)
		{
			print_chunk(x, y, game.map.alloc[i][j], &game);
			j++;
			x += 50;
		}
		i++;
		y += 50;
	}
}

void	print_chunk(int x, int y, char chunk, t_game *game)
{
	if (chunk == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->floor, x, y);
	else if (chunk == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall, x, y);
	else if (chunk == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->character, x, y);
	else if (chunk == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->collectible, x, y);
	else if (chunk == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit, x, y);
}
